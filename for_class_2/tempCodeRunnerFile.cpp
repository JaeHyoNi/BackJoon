#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> arr;
ll check(ll length){
    ll num = 0;
    for(auto K:arr){
        if(K>length){
            num += (K-length);
        }
    }
    return num;
}
int main(){
    ll K,N,tmp,MIN,MAX,target; cin>>K>>N;
    arr.resize(K);
    for(ll i=0;i<K;i++){scanf("%d",&arr[i]);}
    MAX = *max_element(arr.begin(),arr.end());
    MIN = 1;
    target = (MAX + MIN)/2;
    while(1){
        tmp = check(target);
        if(tmp < N){
            MAX = target;
            target = (MIN+target)/2;
        }
        else if(tmp >= N){
            if(MIN+1 == MAX || MIN == MAX) break;
            MIN = target;
            target = (MAX+target)/2;
        }
    }
    cout<<MIN;
}