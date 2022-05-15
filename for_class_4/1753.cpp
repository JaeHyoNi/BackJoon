#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000
vector<pair<int,int>> road[20001];
int DIS[20001];

void dijkstra(int N){
    int dis,from,to,temp;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> wait;
    wait.push(make_pair(0,N));
    DIS[N] = 0;
    while(!wait.empty()){
        from = wait.top().second; temp = wait.top().first;  wait.pop();
        if(DIS[from] < temp) {continue;}
        for(int i=0;i<road[from].size();i++){
            to = road[from][i].first , dis = road[from][i].second;
            if(temp + dis < DIS[to]){
                DIS[to] = temp + dis;
                wait.push(make_pair(DIS[to],to));
            }
        }
    }
}

int main(){
    int V,E,num,a,b,c; scanf("%d %d %d",&V,&E,&num);
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&a,&b,&c);
        road[a].push_back({b,c});
    }
    fill_n(DIS,V+1,INF);
    dijkstra(num);
    for(int i=1;i<=V;i++){
        if(DIS[i] != INF)   cout<<DIS[i]<<"\n";
        else {cout<<"INF\n"<<endl;}
    }
}
