import matplotlib.pyplot as plt
import numpy as np
import polars as pl
#import ROOT as rt

# get the data
data = pl.read_csv("calib_coef")

NaI_fit = np.polynomial.polynomial.polyfit(data["cNaI"], data["E"], 1, full=True)  # 1 means linear
HPGe_fit = np.polynomial.polynomial.polyfit(data["cHPGe"], data["E"], 1,  full=True)  # 1 means linear

print("Sodium detector scale : ", NaI_fit)
print("Germanium detector scale : ", HPGe_fit)

plt.errorbar(data["cNaI"], data["E"], xerr=data["dcNaI"], fmt="bx")
plt.errorbar(data["cHPGe"], data["E"], xerr=data["dcHPGe"], fmt="rx")

print(NaI_fit[0])

plt.plot(data["cNaI"],data["cNaI"]*NaI_fit[0][1]+NaI_fit[0][0], "-b", label = "NaI fit")
plt.plot(data["cHPGe"],data["cHPGe"]*HPGe_fit[0][1]+HPGe_fit[0][0], "-r", label = "HPGe fit")

#plt.axline((0, NaI_fit[0][0]), slope=NaI_fit[0][1], label="NaI fit")
#plt.axline((0, HPGe_fit[0][0]), slope=HPGe_fit[0][1], label="HPGe fit", c = "red")


# make it nice
plt.title("Channel vs Energy")
plt.xlabel("Bin [/]")
plt.ylabel("Energy [keV]")
plt.legend()


# show it
plt.show()
