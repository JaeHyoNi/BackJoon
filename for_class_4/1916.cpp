#include <bits/stdc++.h>
using namespace std;
int Dis[1001];
vector<pair<int,int>> road[100001];
int main(){
    int current,next,distance,next_dis,from,to,tmp,N,M,a,b,c; scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        road[a].push_back({b,c});
    }    
    scanf("%d %d",&from,&to);
    fill_n(Dis,N+1,2100000000);
    Dis[from] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> wait;
    wait.push({0,from});
    while(!wait.empty()){
        distance = wait.top().first; current = wait.top().second; wait.pop();
        if(distance > Dis[current]) continue;
        for(auto K:road[current]){
            next = K.first; 
            next_dis = distance + K.second;
            if(next_dis < Dis[next]){
                Dis[next] = next_dis;
                wait.push({next_dis,next});
            } 
        }
    }
    cout<<Dis[to];
}