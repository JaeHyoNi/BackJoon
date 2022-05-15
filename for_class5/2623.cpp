#include <bits/stdc++.h>
using namespace std;

int main(){
    int con[1001] = {0,};
    int N,pd,tmp,pre,M; cin>>N>>pd;
    vector<vector<int>> singer(N+1);
    for(int i=1;i<=pd;i++){
        cin>>M; M--;
        cin>>pre; 
        while(M--){
            cin>>tmp;
            singer[pre].emplace_back(tmp);
            con[tmp] += 1;
            pre = tmp;
        }
    }
    queue<int> wait;
    vector<int> answer;
    for(int i=N;i>0;i--){if(con[i] == 0) wait.push(i);}
    while(!wait.empty()){
        answer.emplace_back(wait.front());
        for(auto K:singer[wait.front()]){
            con[K]-=1;
            if(con[K] == 0){wait.push(K);}
        }
        wait.pop();
    }
    if(answer.size() == N){for(auto K:answer){cout<<K<<" ";}}
    else{cout<<"0";}
    return 0;
}