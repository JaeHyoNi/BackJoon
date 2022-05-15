#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> arr;
ll check(ll length){
    ll num = 0;
    for(auto K:arr){num += K/length;}
    // cout<<"length = " <<length<<" "<<num<<endl;
    return num;
}
int main(){
    ll K,N,tmp,MIN,MAX,target; cin>>K>>N;
    arr.resize(K);
    for(ll i=0;i<K;i++){scanf("%d",&arr[i]);}
    MAX = *max_element(arr.begin(),arr.end());
    MIN = 1;
    target = (MAX + MIN)/2;
    if(check(MAX) >= N){cout<<MAX;return 0;}
    while(1){
        tmp = check(target);
        if(tmp < N){
            // printf("MAX = %d , MIN = %d, target = %d\n",MAX,MIN,target);
            MAX = target;
            target = (MIN+target)/2;
        }
        else if(tmp >= N){
            // printf("MAX = %d , MIN = %d, target = %d\n",MAX,MIN,target);
            if(MIN+1 == MAX || MIN == MAX) break;
            MIN = target;
            target = (MAX+target)/2;
        }
    }
    cout<<MIN;
}