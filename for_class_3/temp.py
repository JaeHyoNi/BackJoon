

def div_fun(f1 = [],f2 = []):
    f1_size = len(f1)
    f2_size = len(f2)
    if(f1[0] == 0):
        del f1[0]
        return 0,f1
    quotient = int(f1[0] / f2[0])
    for i in range(f2_size):
        f1[i] = (f1[i] - (f2[i]*quotient))
    del f1[0]
    return quotient,f1
        
def calcul(f1 = [],f2 = []):
    f1_size = len(f1)
    f2_size = len(f2)
    answer = []
    for i in range(f1_size-f2_size+1):
        cha,f1 = div_fun(f1,f2)
        print("Do..... quotient = ",cha,"  fun = ",f1)
        answer.append(cha)
    while(f1[0] == 0):
        del f1[0]
        print("remove")
        if(len(f1) == 0):
            break
    if(len(f1) == 0):
        f1 = [0]
    print("REAL")
    print(answer , f1)
    return answer,f1
    
U = list(map(int, input().split()))
g = list(map(int,input().split()))

calcul(U,g)