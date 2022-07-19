#include<bits/stdc++.h>
using namespace std;
bool VISIT[100001];
vector<vector<int>> road;

int main(){
    int N,M,from,to,S,s; cin>>N>>M;
    road.resize(N+1);
    set<int> fan;
    for(int i=0;i<M;i++){
        cin>>from>>to;
        road[from].push_back(to);
    }
    cin>>S;
    for(int i=0;i<S;i++){cin>>s;  fan.insert(s);}
    if(fan.find(1)!=fan.end()){cout<<"Yes"; return 0;}
    queue<int> wait; wait.push(1);
    bool yes = false;
    while(!wait.empty()){
        from = wait.front(); wait.pop();
        if(road[from].empty()){yes = true; break;}
        for(auto K:road[from]){
            if(VISIT[K]){continue;}
            VISIT[K] = true;
            if(fan.find(K)==fan.end()){wait.push(K);}
        }
    }
    if(yes) cout<<"yes";
    else{cout<<"Yes";}
}