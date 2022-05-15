#include <bits/stdc++.h>
using namespace std;
#define MAX 5000001
int prime[MAX];
int main(){
    int N,K,J;
    for(int i=2;i<MAX;i++){
        if(prime[i] == 0){
            K=2;prime[i] = i;
            while(K*i<MAX){if(prime[K*i]==0)prime[K*i] = i;K++;}
        }
    }
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&K);
        while(K != 1){
            printf("%d ",prime[K]);
            K = K/prime[K];
        }
        printf("\n");
    }
}