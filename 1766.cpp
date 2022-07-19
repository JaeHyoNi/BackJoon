#include <bits/stdc++.h>
using namespace std;
vector<int> numOfSon;
vector<vector<int>> sons;  
int main(){
    int N,M,now,pre,after; cin>>N>>M;
    numOfSon.resize(N+1,0);
    sons.resize(N+1);
    for(int i=0;i<M;i++){
        cin>>pre>>after;
        numOfSon[after]++;
        sons[pre].emplace_back(after);
    }
    priority_queue<int,vector<int>, greater<int>> wait;
    for(int i=1;i<=N;i++){
        if(numOfSon[i] == 0){
            wait.push(i);
        }
    }
    vector<int> answer;
    while(!wait.empty()){
        now = wait.top(); wait.pop();
        answer.emplace_back(now);
        for(auto K:sons[now]){
            numOfSon[K] --;
            if(numOfSon[K] == 0){wait.push(K);}
        }
    }    
    for(auto K:answer){
        cout<<K<<" ";
    }
}