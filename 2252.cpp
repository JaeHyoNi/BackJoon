#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> graph[32001];
int main(void){
    int f,t;
    cin>>N>>M;
    vector<int> cha(N+1,0);
    vector<int> ans;
    for(int i=0;i<M;i++){
        cin>>f>>t;
        graph[f].push_back(t);
        cha[t] = cha[t] + 1;
    }
    queue<int> wait;
    for(int i=1;i<N+1;i++){
        if(cha[i] == 0){
            wait.push(i);
        }
    }
    int iter;
    while(!wait.empty()){
        iter = wait.front();
        wait.pop();
        ans.push_back(iter);
        for(auto K:graph[iter]){
            cha[K] = cha[K] - 1;
            if(cha[K] == 0){
                wait.push(K);
            }
        }
    }
    for(auto K:ans){
        cout<<K<<" ";
    }
}
