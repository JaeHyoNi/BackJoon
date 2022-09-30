#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<vector<int>> effect;
vector<bool> pull;
int N,ans = INT32_MAX;


void switching(int num){
    if(num >= ans) return;
    vector<int> arr;
    for(int i=1;i<=N;i++){
        if(A[i]==0){
            arr.emplace_back(i);
        }
    }
    if(arr.empty()){
        ans = min(ans,num);
        return;
    }
    for(auto K:arr){
        if(pull[K] == true){
            continue;
        }
        else{
            pull[K] = true;
            for(auto T:effect[K]){A[T] = (A[T]+1)%2;}
            A[K] = (A[K]+1)%2;
            switching(num+1);
            for(auto T:effect[K]){A[T] = (A[T]+1)%2;}
            A[K] = (A[K]+1)%2;
            pull[K] = false;
        }
    }
}

int main(){
    int C,t; cin>>N; 
    A.resize(N+1,1); effect.resize(N+1),pull.resize(N+1,false);
    for(int i=1;i<=N;i++){cin>>A[i];}
    for(int i=1;i<=N;i++){
        cin>>C;
        for(int j=1;j<=C;j++){
            cin>>t; 
            effect[i].emplace_back(t);
        }
    }
    switching(0);
    if(ans == INT32_MAX) cout<<"-1\n";
    else cout<<ans<<"\n";
}