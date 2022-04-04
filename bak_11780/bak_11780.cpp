#include <bits/stdc++.h>
using namespace std;

vector<int> operator+(const vector<int> &a,const vector<int> &b){
    vector<int> temp;
    for(auto K:a) temp.push_back(K);
    for(auto K:b) temp.push_back(K);
    return temp;
}

int main(){
    int f,t,val;
    int N;scanf("%d",&N);
    int M;scanf("%d",&M);
    vector<vector<int>> arr(N+1,vector<int>(N+1,100001));
    vector<vector<vector<int>>> road(N+1,vector<vector<int>>(N+1));
    
    for(int i=0;i<M;i++){scanf("%d %d %d",&f,&t,&val);
        if(arr[f][t] == 0) arr[f][t] = val;
        else arr[f][t] = min(arr[f][t],val);
    }
    for(int mid = 1;mid<=N;mid++){
        for(int from = 1;from<=N;from++){
            for(int to = 1; to <= N; to ++){
                if(arr[from][mid]  + arr[mid][to] < arr[from][to]){
                    arr[from][to] = arr[from][mid] + arr[mid][to];
                    road[from][to] = road[from][mid];
                    road[from][to].push_back(mid);
                    road[from][to] =road[from][to] + road[mid][to];
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j || arr[i][j] == 100001) arr[i][j] = 0;
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 0){
                cout<<"0"<<endl;continue;
            }
            printf("%d %d ",road[i][j].size()+2,i);
            for(auto K:road[i][j]){
                cout<<K<<" ";
            }cout<<j<<endl;
        }
    }
    return 0;
}