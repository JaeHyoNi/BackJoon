#include <bits/stdc++.h>
using namespace std;

bool arr[257][257];
int N,K,from,to,iter,temp,num;

void floyd_warshall(){
    for(int m = 1 ; m<= N; m++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(arr[i][m] && arr[m][j]) arr[i][j] = true;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j] && arr[j][i]){
                printf("-1\n");
                return;
            }
        }
    }
    for(int i=1;i<=N;i++){
        int s = 1;
        int n = N;
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 1) n--;
            if(arr[j][i] == 1) s++; 
        }
        printf("%d %d\n",s,n);
    }
}






int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(false);

    scanf("%d %d",&N,&K);
    for(int i=0;i<K;i++){
        scanf("%d %d",&from,&to);
        arr[from][to] = 1;
    }    
    floyd_warshall();
    return 0;
}