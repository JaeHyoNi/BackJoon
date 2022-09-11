#include <bits/stdc++.h>
using namespace std;

vector<bool> push;
vector<vector<int>> effect;

int main(){
    int t,k,N,TARGET=0,state=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>t;
        if(t == 1){
            state |= (1<<i);
        }
    }
    effect.resize(N);
    push.resize(1<<N,false);
    TARGET = (1<<N)-1;
    for(int i=0;i<N;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>k;
            effect[i].emplace_back(k-1);
        }
    }
    if(state == TARGET){cout<<"0"; return 0;}
    queue<pair<int,int>> wait;
    wait.push({state,0});
    pair<int,int> temp;
    while(!wait.empty()){
        temp = wait.front(); wait.pop();
        for(int i=0;i<N;i++){
            if( !(temp.first & (1<<i))){
                k = temp.first;
                k |= (1<<i);
                for(auto K:effect[i]){
                    k ^= (1<<K);
                }
                if(k == TARGET){
                    cout<<temp.second+1<<"\n";
                    return 0;
                }
                if(!push[k]){
                    push[k] = true;
                    wait.push({k,temp.second+1});
                }
            }
        }
    }
    cout<<"-1\n";
    return 0;
}