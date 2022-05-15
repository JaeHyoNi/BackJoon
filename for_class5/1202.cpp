#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> arr;
map<long long,long long> pack;
int main(){
    long long N,K,C,tmp; scanf("%lld %lld",&N,&K);
    arr.resize(N);
    for(long long i=0;i<N;i++){scanf("%lld %lld",&arr[i].first,&arr[i].second);}
    for(long long i=0;i<K;i++){scanf("%lld",&tmp); pack[tmp]++;}
    sort(arr.begin(),arr.end(),[](const pair<long long,long long> &a,const pair<long long,long long> &b){
            return a.second^b.second?a.second>b.second:a.first>b.first;
    });
    long long answer = 0;
    for(auto K: arr){
        auto temp = pack.lower_bound(K.first);
        if(temp == pack.end()) continue;
        if(temp == pack.begin()){if(temp->first < K.first) continue;}
        answer += K.second;
        temp->second--;
        if(temp->second == 0)   pack.erase(temp);
        if(pack.empty()) break;
    }
    cout<<answer;
}