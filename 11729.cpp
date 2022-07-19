#include <bits/stdc++.h>
using namespace std;
int answer = 0;
int next(int a,int b){
    bool t[4]={false,}; t[a] = true; t[b] = true;
    for(int i=1;i<=3;i++){if(!t[i]) return i;}
    return -1;
}
int hanoi_calcul(int from,int to,int val){
    if(val == 1){return 1;}
    else{return hanoi_calcul(from,next(from,to),val-1) + 1 + hanoi_calcul(next(from,to),to,val-1);}
}

void hanoi_show(int from, int to, int val){
    if(val == 1){printf("%d %d\n",from,to);}
    else{
        hanoi_show(from ,next(from,to),val-1 );
        printf("%d %d\n",from,to); 
        hanoi_show(next(from,to),to,val-1);
    }
}

int main(){
    int N; cin>>N;
    printf("%d\n",hanoi_calcul(1,3,N));
    hanoi_show(1,3,N);
}