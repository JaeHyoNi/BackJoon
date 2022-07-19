#include <bits/stdc++.h>
using namespace std;

long long cood(long long x,long long y){
    long long T = max(abs(x),abs(y));
    long long P = (2*(T+1)-1);
    long long RB = P*P;
    long long LT = (RB-2*(P-1)); 
    if(x == T){return RB + ((y-T));}
    else if(x == -1*T){return LT-(T+y);}
    else if(y == T){return (P-2)*(P-2)+(-1*x+T);}
    else {return LT + T+x;}
    return 0;
}

int main(){
    long long r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
    long long N=0,K=0;
    for(int i=r1;i<=r2;i++){for(int j=c1;j<=c2;j++){N = max(N,cood(i,j));}}
    while(N!=0){N/=10; K++;}
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            printf("%*d ",K,cood(i,j));
        }
        printf("\n");
    }
    return 0;
}