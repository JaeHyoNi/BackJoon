#include <bits/stdc++.h>
using namespace std;
#define road pair<int,int>
vector<road> road_union[10001];
int far[10001];
int answer[10001];
int N,M,X;

void Dij(int num){
    for(int i=1;i<=N;i++){far[i] = 2100000000;}
    far[num] = 0;
    priority_queue<road> wait;
    road tmp;
    wait.push({num,0});
    while(!wait.empty()){
        tmp = wait.top(); wait.pop();
        if(far[tmp.first] < -1 * tmp.second) continue;
        for(auto K: road_union[tmp.first]){
            if(K.second - tmp.second < far[K.first]){
                far[K.first] = K.second - tmp.second;
                wait.push({K.first , -1*far[K.first]});
            }
        }
    }
    if(X==num){
        for(int i=1;i<=N;i++){
            answer[i] += far[i];
        }
    }
    else{
        answer[num] += far[X];
    }
}


int main(){
    int a,b,c; cin>>N>>M>>X;
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        road_union[a].push_back({b,c});
    }
    vector<int> temp;
    for(int i=1;i<=N;i++){Dij(i);}
    cout<<*max_element(answer,answer+N+1);
}