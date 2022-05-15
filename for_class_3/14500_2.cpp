#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define update(x,y) (x)>(y) ? (x):(y)

int a[505][505];
int MAX = 0;

void match(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]); 
            MAX = update(MAX , a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]); 
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]); 
            MAX = update(MAX , a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]); 
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]); 
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]); 
            MAX = update(MAX , a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
            MAX = update(MAX , a[i][j+1]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]);
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]); 
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i+1][j]+a[i+2][j]); 
            MAX = update(MAX , a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);  
            MAX = update(MAX , a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1]); 
            MAX = update(MAX , a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]); 
            MAX = update(MAX , a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+2][j]);  
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2]); 
            MAX = update(MAX , a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
            MAX = update(MAX , a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j]); 
            MAX = update(MAX , a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]); 
            MAX = update(MAX , a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1]);
        }
    }
    return;
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){for(int j=0; j<M; j++){scanf("%d",&a[i][j]);}}
    match(N,M);
    cout<<MAX;
}
