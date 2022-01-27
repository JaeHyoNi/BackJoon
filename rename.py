import os

def changeName(path):
    i=1
    for filename in os.listdir(path):
        print(path+filename, '=>' , filename[2:4]);
        os.rename(path+filename,filename[2:4])
        i+=1

changeName('..\..\아빠\재즈\[ 카페 재즈음악 명곡 모음집 ] [320Kbps]\2005 - Vol. 07\SCANS')