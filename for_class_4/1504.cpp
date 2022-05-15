#include <bits/stdc++.h>
using namespace std;
int N,E; 
vector<pair<int,int>> road[801];

int dijkstra(int a,int b){
    int far[801] , dis,from,to;
    fill_n(far,N+1,2100000000);
    priority_queue<pair<int,int>> pq; pq.push({a,0}); far[a] = 0;
    while(!pq.empty()){
        from = pq.top().first; dis = -1*pq.top().second; pq.pop();
        if(far[from] < dis) continue;
        for(auto to : road[from]){
            if( dis + to.second < far[to.first]){
                far[to.first] = dis+to.second;
                pq.push({to.first , -1*(dis+to.second)});
            }
        }
    }
    if(far[b] == 2100000000) return -1;
    return far[b];
}

int main(){
    scanf("%d %d",&N,&E); int a,b,c;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&a,&b,&c);
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }
    scanf("%d %d",&a,&b);
    int a_to_b = dijkstra(a,b);
    int f1_a = dijkstra(1,a) , f1_b = dijkstra(1,b) ,fa_N = dijkstra(a,N), fb_N = dijkstra(b,N);
    if(f1_a== -1 || fb_N == -1){
        if(f1_b == -1 || fa_N == -1){cout<<"-1";}
        else {cout<<f1_b+a_to_b+fa_N;}
    }
    else if(f1_b== -1 || fa_N == -1){
        if(f1_a == -1 || fb_N == -1){cout<<"-1";}
        else {cout<<f1_a+a_to_b+fb_N;}
    }
    else{
        cout<<(f1_a + fb_N < f1_b + fa_N ?  f1_a+fb_N+a_to_b : f1_b+fa_N+a_to_b);
    }
}