#include <bits/stdc++.h>
using namespace std;

int A[10001],B[10001],N,K;
vector<int> H,temp;

int calcul(int num){
    int SUM = 0,MAX = 0;
    for(int i=0;i<N;i++){
        if(H[i]>num){temp[i] = (H[i]-num)*B[i];}
        else{temp[i] = (num-H[i])*A[i];}
    }
    for(int i=0;i<K;i++){SUM+=temp[i];}
    MAX = SUM;
    for(int flag = K; flag<N; flag++){
        SUM = SUM + temp[flag] - temp[flag-K];
        SUM = min(SUM,MAX);
    }
    return MAX;
}

void getinput(){
    cin>>N>>K;
    H.resize(N) , temp.resize(N);
    for(int i=0;i<N;i++){cin>>H[i];}
    for(int i=0;i<N;i++){cin>>A[i];}
    for(int i=0;i<N;i++){cin>>B[i];}
    printf("N : %d , K : %d\n",N,K);
}

int main(){
    getinput();
    int mid1,mid2,T=100,lo,hi;
    hi = *max_element(H.begin(),H.end());
    lo = *min_element(H.begin(),H.end());
    for(int i=lo;i<=hi;i++){
        printf("[%d] : %d\n",i,calcul(i));
    }
    while(lo+3<hi){
        mid1 = (2*lo + hi)/3;
        mid2 = (lo+2*hi)/3; 
        printf("mid1 = %d , mid2 = %d , hi = %d , lo = %d\n",mid1,mid2,hi,lo);
        if(calcul(mid1)<calcul(mid2)){hi = mid2;}
        else{lo = mid1;}
    }
    int answer = 9999999;
    for(int i=lo; i<=hi; i++){
        answer = min(answer,calcul(i));
    }
    cout<<answer;
}