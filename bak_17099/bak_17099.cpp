#include <bits/stdc++.h>
using namespace std;
struct contest{int s;int e;int val;};
int main(){
    int N,temp,iter=0,MAX = 0;
    pair<int,int> ans = {0,0};
    scanf("%d",&N);
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> next;
    vector<contest> con(N);
    for(int i=0;i<N;i++){scanf("%d %d %d",&con[i].s,&con[i].e,&con[i].val);}
    sort(con.begin(),con.end(),[](const contest &a,const contest &b){return a.s ^ b.s ? a.s < b.s : a.e < b.e;});
    for(auto K:con){
        if(next.empty()){
            next.push({K.e,K.val + ans.second});
            ans.first = K.s;    
        }
        else{
            while(next.top().first < K.s){
                ans = {next.top().first, max(next.top().second , ans.second)};
                next.pop();
            }
            ans.first = K.s;
            next.push({K.e , ans.second + K.val});
        }
    }
    while(!next.empty()){
        ans.second = max(ans.second , next.top().second);
        next.pop();

    }
    cout<<ans.second;
}
