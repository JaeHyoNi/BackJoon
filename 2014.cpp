#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    map<ll,bool> VISIT;
    ll N,ord,temp,temp2 = 0,MAX = 0; cin>>N>>ord;
    vector<ll> arr(N);
    priority_queue< ll,vector<ll>,greater<ll>> wait;
    temp = 0;
    for(int i=0;i<N;i++){cin>>arr[i];}
    wait.push(1);
    for(int i=0;i<ord;i++){
        // cout<<i<<" : "<<wait.top()<<"\n";
        temp = wait.top(); wait.pop();
        for(int j=0;j<N;j++){
            temp2 = temp*arr[j];
            if(wait.size() > ord-i && temp2 > MAX ) continue;
            if(!VISIT[temp2]){
                VISIT[temp2] = true;
                MAX = max(MAX,temp2);
                wait.push(temp2);
            }
        }
    }
    cout<<wait.top();
}