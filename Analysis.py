import matplotlib.pyplot as plt
import numpy as np
import polars as pl
from scipy.optimize import curve_fit

# data paths
raw_path = {
    "data": "./thing.csv",
    "activity": "./sources.csv",
    "NaEff": "./plots/Ieff/NaI.data",
    "HPGeEff": "./plots/Ieff/HPGe.data",
}
# detectors area
A_NaI = np.pi * 7.5**2
DA_NaI = 2*np.pi * 7.5 * 0.1
A_HPGe = 12
DA_NaI = 0.01
# distance to detectors
dis_NaI = {"up": 25,
           "side": np.sqrt((13.75)**2 + (3.725)**2)}
Ddis_NaI = 0.1
dis_HPGe = {"up": np.sqrt((27.5/2 - 7)**2 + (26.275)**2),
            "down": 6.75, "side": 20.5}
Ddis_HPGe = 0.1
# NaI solid angles
NaI_solang = {"up": A_NaI/(30)**2,
              "down": 2*np.pi,
              "side": A_NaI/(dis_NaI["side"])**2 * np.cos(np.pi/2 -np.arctan(3.725/13.75))
             }
# error on NaI solid angles
ENaI_solang = {"up": np.sqrt((Ddis_NaI/(dis_NaI["up"])**2)**2
                             + (A_NaI*Ddis_NaI/(dis_NaI["up"])**3)**2),
               "down": 0.1,
               "side": np.sqrt((Ddis_NaI/(dis_NaI["side"])**2)**2
                               + (A_NaI*Ddis_NaI/(dis_NaI["side"])**3)**2)
              }
# HPGe solid angles
HPGe_solang = {"up": A_HPGe/(dis_HPGe["up"])**2,
               "down": A_HPGe/(dis_HPGe["down"])**2,
               "side": A_HPGe/(dis_HPGe["side"])**2
              }
# error on HPGe solid angles
EHPGe_solang = {"up": np.sqrt((Ddis_HPGe/(dis_HPGe["up"])**2)**2
                             + (A_HPGe*Ddis_HPGe/(dis_HPGe["up"])**3)**2),
               "down": 0.1,
               "side": np.sqrt((Ddis_HPGe/(dis_HPGe["up"])**2)**2
                               + (A_HPGe*Ddis_HPGe/(dis_HPGe["up"])**3)**2)
              }
# lenght of mesurement
time = {"15": 900, "10": 600}
# branching ratios ANALYSIS.C dependent
BrRo1 = pl.Series(
    [
        1.8,  # sodio 511
        0.9995,  # sodio 1274.5
        1.8,  # sodio 511
        0.9995,  # sodio 1274.5
        0.9985,  # cobalto 1173
        0.999826,  # cobalto 1331
        0.9985,  # cobalto 1173
        0.999826,  # cobalto 1331
        0.3578,  # americio 59.5
        0.0755,  # europio 242
        0.2659,  # europio 340
        0.1297,  # europio 780
        0.1450,  # europio 966
        0.1013,  # europio 1100->1089
        0.2085,  # europio  1405
        0.2853,  # europio 121
        0.0755,  # europio 244
        0.2659,  # europio 344
        0.00862,  # europio 367
        0.02238,  # europio 411
        0.0312,  # europio 443
        0.1297,  # europio 778
        0.04243,  # europio 867
        0.1451,  # europio 963
        0.1013,  # europio 1085
        0.1341,  # europio 1111
        0.2085,  # europio 1407
        0.193,  # cal_can 291
        0.376,  # cal_can 348
        0.461,  # cal_can 609
        0.0743,  # cal_can 241
        0.193,  # cal_can 291
        0.376,  # cal_can 348
        0.461,  # cal_can 609
        0.193,  # exp_can 291
        0.376,  # exp_can 348
        0.461,  # exp_can 609
        0.0743,  # exp_can 241
        0.193,  # exp_can 291
        0.376,  # exp_can 348
        0.461,  # exp_can 609
        0.193,  # autunite 291
        0.376,  # autunite 348
        0.461,  # autunite 609
        0.193,  # autunite 291
        0.376,  # autunite 348
        0.461,  # autunite 609
    ]
)
# get the data as polars Dataframe
data = pl.read_csv(raw_path["data"], comment_prefix="#")
# activity data : sample	h_l_y	act_bq	p_time
act = pl.read_csv(raw_path["activity"], separator="\t")
# calc the activity now, days past can be found via website online and measurements chart, days to 22 10 2025
act = act.with_columns(
    (act["act_bq"] * np.exp(-np.log(2) * act["p_time"] / (act["h_l_y"] * 365))).alias(
        "act_now"
    )
)
print(act)
# adding activity to data
data = data.with_columns(
    pl.when(pl.col("sample") == "cobalto")
    .then(act.filter(pl.col("sample") == "cobalto")["act_now"])
    .when(pl.col("sample") == "sodio")
    .then(act.filter(pl.col("sample") == "sodio")["act_now"])
    .when(pl.col("sample") == "americio")
    .then(act.filter(pl.col("sample") == "americio")["act_now"])
    .when(pl.col("sample") == "europio")
    .then(act.filter(pl.col("sample") == "europio")["act_now"])
    .otherwise(act.filter(pl.col("sample") == "boh")["act_now"])
)
# adding solid angle to data
data = data.with_columns(
    pl.when((pl.col("sample") == "cobalto") & (pl.col("chnl") == 0))
    .then(NaI_solang["up"])
    .when((pl.col("sample") == "sodio") & (pl.col("chnl") == 0))
    .then(NaI_solang["up"])
    .when((pl.col("sample") == "americio") & (pl.col("chnl") == 0))
    .then(NaI_solang["up"])
    .when((pl.col("sample") == "europio") & (pl.col("chnl") == 0))
    .then(NaI_solang["side"])
    .when((pl.col("chnl") == 0) & (pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col("sample") != "cobalto") & (pl.col("sample") != "americio"))
    .then(NaI_solang["down"])
    .when((pl.col("sample") == "cobalto") & (pl.col("chnl") == 1))
    .then(HPGe_solang["up"])
    .when((pl.col("sample") == "sodio") & (pl.col("chnl") == 1))
    .then(HPGe_solang["up"])
    .when((pl.col("sample") == "americio") & (pl.col("chnl") == 1))
    .then(HPGe_solang["up"])
    .when((pl.col("sample") == "europio") & (pl.col("chnl") == 1))
    .then(HPGe_solang["side"])
    .when((pl.col("chnl") == 1) & (pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col("sample") != "cobalto") & (pl.col("sample") != "americio"))
    .then(HPGe_solang["down"])
    .alias("solang")
)
# adding error on solid angle to data
data = data.with_columns(
    pl.when((pl.col("sample") == "cobalto") & (pl.col("chnl") == 0))
    .then(ENaI_solang["up"])
    .when((pl.col("sample") == "sodio") & (pl.col("chnl") == 0))
    .then(ENaI_solang["up"])
    .when((pl.col("sample") == "americio") & (pl.col("chnl") == 0))
    .then(ENaI_solang["up"])
    .when((pl.col("sample") == "europio") & (pl.col("chnl") == 0))
    .then(ENaI_solang["side"])
    .when((pl.col("chnl") == 0) & (pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col("sample") != "cobalto") & (pl.col("sample") != "americio"))
    .then(ENaI_solang["down"])
    .when((pl.col("sample") == "cobalto") & (pl.col("chnl") == 1))
    .then(EHPGe_solang["up"])
    .when((pl.col("sample") == "sodio") & (pl.col("chnl") == 1))
    .then(EHPGe_solang["up"])
    .when((pl.col("sample") == "americio") & (pl.col("chnl") == 1))
    .then(EHPGe_solang["up"])
    .when((pl.col("sample") == "europio") & (pl.col("chnl") == 1))
    .then(EHPGe_solang["side"])
    .when((pl.col("chnl") == 1) & (pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col("sample") != "cobalto") & (pl.col("sample") != "americio"))
    .then(EHPGe_solang["down"])
    .alias("Esolang")
)
# adding time to data
data = data.with_columns(
    pl.when((pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col(
        "sample") != "cobalto") & (pl.col("sample") != "americio") & (pl.col("sample") != "autunite"))
    .then(time["15"])
    .otherwise(time["10"])
    .alias("m_time")
)
# adding branching ratios
data = data.with_columns(BrRo1.alias("BrRo"))
# finding the efficiency : Ieff = Int /((solid ang/ 4pi) act br time) = Int *4pi /(solang * act * time * br)
data = data.with_columns(
    (
        pl.col("Int")
        * 4
        * np.pi
        / (pl.col("solang") * pl.col("act_now") * pl.col("m_time") * pl.col("BrRo"))
    ).alias("Ieff")
)

data = data.with_columns(
    (
        np.sqrt(
            (
                (
                    np.pow(pl.col("Int"), 0.5)
                    * 4
                    * np.pi
                    / (
                        pl.col("solang")
                        * pl.col("act_now")
                        * pl.col("m_time")
                        * pl.col("BrRo")
                    )
                )
            )
            ** 2
            + (
                (
                    pl.col("Int")
                    * 4
                    * np.pi
                    / (
                        pl.col("solang") ** 2
                        * pl.col("act_now")
                        * pl.col("m_time")
                        * pl.col("BrRo")
                    )
                )
                * pl.col("Esolang")
            )
            ** 2
        )
    ).alias("EIeff")
)
# everything done so what are the columns we got ?
print(data.columns)
with pl.Config(tbl_rows=100):
    print(data.filter(pl.col("sample")=="europio")["chnl","peak_nmbr","mean", "Int", "Ieff", "act_now", "solang", "m_time"])

# """
if False:
# what do we got as efficiency ?
# NaI
# make the plot
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["mean"],
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["sigma"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["mean"],
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["sigma"],
        fmt="g+",
        label="cobalt",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "europio"))["mean"],
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "europio"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "europio"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "europio"))["sigma"],
        fmt="c2",
        label="europio",
    )
    plt.errorbar(
       data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["mean"],
       data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["Ieff"],
       yerr=data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["EIeff"],
       xerr=data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["sigma"],
       fmt="k1",
       label="cal_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "exp_can"))["mean"],
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "exp_can"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "exp_can"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "exp_can"))["sigma"],
        fmt="b3",
        label="exp_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "autunite"))["mean"],
        data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "autunite"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "autunite"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "autunite"))["sigma"],
        fmt="m4",
        label="autunite",
    )
# make it nice
    plt.title("NaI efficiency")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("Efficiency")
    plt.legend()
# show it
    plt.show()

# HPGe
# make the plot
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["mean"],
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["sigma"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["sigma"],
        fmt="g+",
        label="cobalt",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["sigma"],
        fmt="y3",
        label="americio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["sigma"],
        fmt="c2",
        label="europio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cal_can"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cal_can"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cal_can"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cal_can"))["sigma"],
        fmt="k1",
        label="cal_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "exp_can"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "exp_can"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "exp_can"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "exp_can"))["sigma"],
        fmt="b3",
        label="exp_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "autunite"))["mean"],
        data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "autunite"))["Ieff"],
        yerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "autunite"))["EIeff"],
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "autunite"))["sigma"],
        fmt="m4",
        label="autunite",
    )
# make it nice
    plt.title("HPGe efficiency")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("Efficiency")
    plt.legend()
# show it
    plt.show()

if True:
# what do we got as resolution efficiency ?
# NaI
# make the plot
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "sodio"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["dmean"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["dmean"],
        fmt="g+",
        label="cobalto",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "europio"))["dmean"],
        fmt="c2",
        label="europio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cal_can"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cal_can"))["dmean"],
        fmt="k1",
        label="cal_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "exp_can"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "exp_can"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "exp_can"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "exp_can"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "exp_can"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "exp_can"))["dmean"],
        fmt="b3",
        label="exp_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "autunite"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "autunite"))["sigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "autunite"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "autunite"))["dsigma"]/data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "autunite"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "autunite"))["dmean"],
        fmt="m4",
        label="autunite",
    )
# make it nice
    plt.title("NaI photopeak resolution")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("resolution[%]")
    plt.legend()
    plt.savefig("plots/NaI_pres")
# show it
    plt.show()

# HPGe
# make the plot
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "sodio"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["dmean"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["dmean"],
        fmt="g+",
        label="cobalto",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["dmean"],
        fmt="y3",
        label="americio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["dmean"],
        fmt="c2",
        label="europio",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cal_can"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cal_can"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cal_can"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cal_can"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cal_can"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cal_can"))["dmean"],
        fmt="k1",
        label="cal_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "exp_can"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "exp_can"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "exp_can"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "exp_can"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "exp_can"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "exp_can"))["dmean"],
        fmt="b3",
        label="exp_can",
    )
    plt.errorbar(
        data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "autunite"))["mean"],
        2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "autunite"))["sigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "autunite"))["mean"] * 100,
        yerr=2*(2 * np.log(2))**0.5 * data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "autunite"))["dsigma"]/data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "autunite"))["mean"] * 100,
        xerr=data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "autunite"))["dmean"],
        fmt="m4",
        label="autunite",
    )
# make it nice
    plt.title("HPGe photopeak resolution")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("resolution[%]")
    plt.legend()
    plt.savefig("plots/HPGe_pres")
# show it
    plt.show()




if False:
# HINT 1A
    A1data = data.filter(
        ((pl.col("chnl") == 0) & ((pl.col("sample") ==
         "cobalto") | (pl.col("sample") == "sodio"))) #| (pl.col("sample") == "europio")
        |
        # & ((pl.col("sample")!="europio") | ((pl.col("mean")<200) & (pl.col("sample")=="europio")))) #((pl.col("chnl")==0) & (pl.col("sample")=="europio") & (pl.col("mean")>1200))
        ((pl.col("chnl") == 1) & ((pl.col("sample") == "americio") | (pl.col("sample") ==
                                                                      "cobalto") | (pl.col("sample") == "europio") | (pl.col("sample") == "sodio"))) #  | (pl.col("sample") == "europio")
    )
# NaI
# fit func
    if True:

        def Eff_fit(x, a, b, c, d):
            return a * x**b / (1000 * c + x**d)

        popt, pcov = curve_fit(
            Eff_fit,
            A1data.filter(pl.col("chnl") == 0)["mean"],
            A1data.filter((pl.col("chnl") == 0))["Ieff"],
            p0=[1.387e-04, 9.05, -1.589e+19, 8.21],# [1.79, 10.125, -2.77e+25, 10.569], # 
            maxfev=1000000,
        )
        print(popt)
        plt.plot(
            np.arange(510, 1380),
            Eff_fit(np.arange(510, 1380), popt[0], popt[1], popt[2], popt[3]),
            label=f"Efficiency : {popt[0]: .4g} + x ** {popt[1]: .4g} \n/ (1000 * {popt[2]: .4g} + x ** {popt[3]: .4g})",
        )
# make the plot
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["mean"],
        A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["EIeff"],
        xerr=A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "sodio"))["sigma"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["mean"],
        A1data.filter((pl.col("chnl") == 0) & (
            pl.col("sample") == "cobalto"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))[
            "EIeff"
        ],
        xerr=A1data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "cobalto"))[
            "sigma"
        ],
        fmt="g+",
        label="cobalt",
    )
    # plt.errorbar(
    #     A1data.filter((pl.col("chnl") == 0) & (
    #         pl.col("sample") == "europio"))["mean"],
    #     A1data.filter((pl.col("chnl") == 0) & (
    #         pl.col("sample") == "europio"))["Ieff"],
    #     yerr=A1data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))[
    #         "EIeff"
    #     ],
    #     xerr=A1data.filter((pl.col("chnl") == 0) & (pl.col("sample") == "europio"))[
    #         "sigma"
    #     ],
    #     fmt="c2",
    #     label="europio",
    # )

# make it nice
    plt.title("NaI efficiency")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("Efficiency")
    plt.legend()
    plt.xscale("log")
    plt.tight_layout()

    #plt.savefig("plots/NaI_eff.png")
# show it
    plt.show()

# HPGe
# fit func
    def HEff_fit(x, a, b, c, d):
        return a * x**b / (1000 * c + x**d)


    popt, pcov = curve_fit(
        HEff_fit,
        A1data.filter((pl.col("chnl") == 1))["mean"],
        A1data.filter((pl.col("chnl") == 1))["Ieff"],
        p0=[930, 2.78, 38456, 3.85],
        maxfev=1000000,
    )
    print(popt)
    plt.plot(
        np.arange(50, 1380),
        HEff_fit(np.arange(50, 1380), popt[0], popt[1], popt[2], popt[3]),
        label=f"Efficiency : {popt[0]: .4g} + x ** {popt[1]: .4g} \n/ (1000 * {popt[2]: .4g} + x ** {popt[3]: .4g})",
    )
# make the plot
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["mean"],
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["EIeff"],
        xerr=A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "sodio"))["sigma"],
        fmt="rx",
        label="sodio",
    )
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["mean"],
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "cobalto"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))[
            "EIeff"
        ],
        xerr=A1data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "cobalto"))[
            "sigma"
        ],
        fmt="g+",
        label="cobalt",
    )
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["mean"],
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "americio"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))[
            "EIeff"
        ],
        xerr=A1data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "americio"))[
            "sigma"
        ],
        fmt="y3",
        label="americio",
    )
    plt.errorbar(
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["mean"],
        A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["Ieff"],
        yerr=A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["EIeff"],
        xerr=A1data.filter((pl.col("chnl") == 1) & (
            pl.col("sample") == "europio"))["sigma"],
        fmt="c2",
        label="europio",
    )
# make it nice
    plt.title("HPGe efficiency")
    plt.xlabel("Energy [KeV]")
    plt.ylabel("Efficiency")
    plt.legend()
    plt.tight_layout()

    #plt.savefig("plots/tHPGe_eff.png")
# show it
    plt.show()


# HINT 1B
B1data = data.filter((pl.col("chnl") == 1) & (pl.col("sample") == "europio"))
# relative intensities
rel_I = pl.DataFrame({"R_I": [
        141., # 121.8
        36.6, # 244.7
        127.2, # 344.3
        4.19, # 367.8
        10.71, # 411
        15., # 444
        62.6, # 778.8
        20.54, # 867.3
        70.4, # 963.9
        48.7, # 1085,8
        65., # 1111.9
        100., # 1407.8
        ],
        "ER_I": [
        4., # 121.8
        1.1, # 244.7
        1.3, # 344.3
        0.04, # 367.8
        0.11, # 411
        0.15, # 444
        0.6, # 778.8
        0.21, # 867.3
        0.7, # 963.9
        0.5, # 1085,8
        0.7, # 1111.9
        1., # 1407.8
        ]
})
# relative efficiencies
B1data = B1data.with_columns(
    (pl.col("Int")/B1data.filter(pl.col("peak_nmbr")==14)["Int"].item() *  100/rel_I["R_I"])
    .alias("R_E")
)
B1data = B1data.with_columns(
    ((
        (pl.col("Int")**0.5/B1data.filter(pl.col("peak_nmbr")==14)["Int"].item() *  100/rel_I["R_I"])**2
        +
        (pl.col("Int")/(B1data.filter(pl.col("peak_nmbr")==14)["Int"].item()**1.5) *  100/rel_I["R_I"])**2
        +
        (pl.col("Int")/B1data.filter(pl.col("peak_nmbr")==14)["Int"].item() *  100/(rel_I["R_I"]**2) * rel_I["ER_I"])**2
    )**0.5).alias("ER_E")
)

with pl.Config(tbl_rows=100):
    print(B1data["solang", "mean", "Int", "BrRo","R_E", "Ieff"])

plt.errorbar(
    B1data["mean"],
    B1data["R_E"],
    yerr=B1data["ER_E"],
    xerr=B1data["sigma"],
    fmt="c2",
    label="europio",
)
# fit func
if False:
    popt, pcov = curve_fit(
        HEff_fit,
        B1data["mean"],
        B1data["Ieff"],
        p0=[930, 2.78, 38998, 3.86],
        maxfev=1000000,
    )
    print(popt)
    plt.plot(
        np.arange(50, 1380),
        HEff_fit(np.arange(50, 1380), popt[0], popt[1], popt[2], popt[3]),
        label=f"Efficiency : {popt[0]: .4g} + x ** {popt[1]: .4g} \n / (1000 * {popt[2]: .4g} + x ** {popt[3]: .4g})",
    )
# make it nice
plt.title("HPGe relative efficiency")
plt.xlabel("Energy [KeV]")
plt.ylabel("Relative efficiency")
#plt.legend()
plt.tight_layout()

#plt.savefig("plots/HPGe_Reff.png")
# show it
plt.show()
# """
# HINT 3

act3 = data.filter((pl.col("sample") != "europio") & (pl.col("sample") != "sodio") & (pl.col(
    "sample") != "cobalto") & (pl.col("sample") != "americio") & (pl.col("sample") != "cal_can"))

# add wheight
act3 = act3.with_columns(
    pl.when(pl.col("sample") == "autunite")
    .then(32.3)
    .when(pl.col("sample") == "exp_can")
    .then(6.7)
    .alias("peso")
)
DF = 0.602739091575738
CF = 0.101266666666667

cal_can_Int = data.filter(pl.col("sample") == "cal_can")["Int"]
E = pl.concat([cal_can_Int, cal_can_Int[:-1]])

cal_can_Ieff = data.filter(pl.col("sample") == "cal_can")["Ieff"]
t_cal_can_Ieff = pl.concat([cal_can_Ieff, cal_can_Ieff[:-1]])

# finding the activity via efficiency: act = Int /((solid ang/ 4pi) Ieff br time) = Int *4pi /(solang * Ieff * time * br)
act3 = act3.with_columns(
    (pl.col("Int") * 4 * np.pi / (pl.col("solang") * pl.col("BrRo") *
     pl.col("m_time") * t_cal_can_Ieff * pl.col("peso")))  # pl.col("peso")
    .alias("estimated_act/g")
)
# finding the activity via RN
act3 = act3.with_columns(
    (pl.col("Int") / (DF * CF * E * pl.col("m_time") * 0.001225))  # pl.col("peso")
    .alias("RN/kg")
)

with pl.Config(tbl_rows=100):
    print(act3)
