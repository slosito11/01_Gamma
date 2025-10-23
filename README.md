# 01_Gamma
Root analysis files of the data taken during the gamma ray experiment of 1st year master physics unipd lab


## how to use it
the directory from which you launch root should look like this:
```
├── Analysis.C
├── getHist.hh
├── other.hh files 
└── data
    ├── raw directroy names ex: autunite
    ├── ⋮
    └── Autunite
        ├── raw directroy in which there is RAW
        ├── ⋮
        └── RAW
            ├── DataR_Autunite
            └── otherfile 
```
then after launching root from the command line you should use the following :
```
root [i] .L Analysis.C
```
