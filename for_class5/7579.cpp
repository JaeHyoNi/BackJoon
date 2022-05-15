#include <bits/stdc++.h>
using namespace std;
#define app pair<long long,long long>
vector<app> mem;
int arr[101][10001];
int main(){
    int N,M; cin>>N>>M;  mem.resize(N+1);
    int sum = 0,tmp;
    for(int i=1;i<=N;i++){scanf("%d",&mem[i].first);}
    for(int i=1;i<=N;i++){scanf("%d",&mem[i].second); sum += mem[i].second;}
    for(int i=1;i<=N;i++){
        for(int j=0;j<mem[i].second;j++){arr[i][j] = arr[i-1][j];}
        for(int j=mem[i].second;j<=sum;j++){
            tmp = arr[i-1][j-mem[i].second] + mem[i].first;
            arr[i][j] = max(arr[i-1][j] , tmp);
        }
    }
    
    for(int i=0;i<sum+1;i++){
        if(arr[N][i]>=M){
            cout<<arr[N][M];
            break;
        }
    }
    return 0;
}