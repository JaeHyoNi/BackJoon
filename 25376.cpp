#include <bits/stdc++.h>
using namespace std;


vector<int> A;
vector<vector<int>> B,effect;
vector<bool> pull;
int N,ans = INT32_MAX;

void switching(int now,int num){
    if(now == N+1){
        bool is  = true;
        for(int i=1;i<=N;i++){
            if(A[i] == 0){
                is = false; 
                break;
            }
        }
        if(is){ans = min(ans,now);}
        return;
    }
    for(auto K:B[now]){A[K] = 1;} A[now] = 1;
    switching(now+1,num+1);
    for(auto K:B[now]){A[K] = 0;} A[now] = 0;
    switching(now+1,num);
}


int main(){
    int C,t,N; cin>>N; 
    A.resize(N+1); B.resize(N+1);
    for(int i=1;i<=N;i++){cin>>A[i]; }
    for(int i=1;i<=N;i++){
        cin>>C;
        for(int j=1;j<=C;j++){
            cin>>t; 
            B[i].emplace_back(t);
        }
    }
    switching(1,0);
    if(ans == INT32_MAX){cout<<"-1";}
    else{cout<<ans;}
}




// int ans=INT32_MAX,N;
// vector<bool> pull;
// vector<int> A;
// vector<vector<int>> B,effect;


// void switching(int now){
//     if(now >= ans) return;
//     int t = -1;
//     for(int i=1;i<=N;i++){
//         if(A[i] == 0){
//             t = i; break;
//         }
//     }
//     if(t == -1){
//         ans = min(now,ans);
//         return;
//     }
//     for(auto K:effect[t]){
//         if(pull[K] == true) continue;
//         pull[K] = true; 
//         for(auto J:B[K]){A[J] = (A[J]+1)%2;}
//         switching(now+1);
//         pull[K] = false;
//         for(auto J:B[K]){A[J] = (A[J]+1)%2;}
//     }

// }


// int main(){
//     int C,t; cin>>N; 
//     A.resize(N+1); B.resize(N+1); pull.resize(N+1,false); effect.resize(N+1);
//     for(int i=1;i<=N;i++){cin>>A[i]; }
    
//     for(int i=1;i<=N;i++){
//         effect[i].emplace_back(i);
//         B[i].emplace_back(i);
//         cin>>C;
//         for(int j=1;j<=C;j++){
//             cin>>t; 
//             B[i].emplace_back(t);
//             effect[t].emplace_back(i);
//         }
//     }
//     switching(0);
//     if(ans == INT32_MAX){cout<<"-1";}
//     else{cout<<ans;}
// }