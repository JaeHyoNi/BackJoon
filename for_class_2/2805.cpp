#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> arr;
int K;
ll check(ll length){
    ll num = 0;
    int MAX = lower_bound(arr.begin(),arr.end(),length)-arr.begin();
    for(int i=MAX;i<K;i++){num += (arr[i]-length);}
    return num;
}
int main(){
    ll N,tmp,MIN,MAX,target; cin>>K>>N; arr.resize(K);
    for(ll i=0;i<K;i++){scanf("%d",&arr[i]);}
    sort(arr.begin(),arr.end());
    MAX = arr[K-1];  MIN = 0;
    target = (MAX + MIN)/2;
    while(1){
        tmp = check(target);
        if(tmp < N){
            if(MIN+1 == MAX) break;
            MAX = target;
            target = (MIN+target)/2;
        }
        else if(tmp >= N){
            if(MIN+1 == MAX) break;
            MIN = target;
            target = (MAX+target)/2;
        }
    }
    cout<<MIN;
}