#include <bits/stdc++.h>

using namespace std;
using ll = long long;
long long N,M,K;

ll feature_sum(ll a,vector<ll> &arr){
    ll sum = 0,iter = a;
    while(iter >= 1){
        sum = sum + arr[iter];
        iter = iter - (iter & ((-1)*iter));
    }
    return sum;
}

void update(ll b,ll c,vector<ll> &arr){
    ll iter = b,gap;
    gap = c - (feature_sum(b,arr)-feature_sum(b-1,arr)); 
    while(iter <= N){
        arr[iter] = arr[iter] + gap;
        iter = iter + (iter & (-1)*iter);
    }
}

ll prefix_sum(ll b,ll c,vector<ll> &arr){
    return feature_sum(c,arr) - feature_sum(b-1,arr);
}
int main(){
    ll tmp, iter,a,b,c;
    scanf("%lld %lld %lld",&N,&M,&K);
    vector<long long> arr(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>tmp;
        iter = i;
        while(iter <= N){
            arr[iter] = arr[iter] + tmp;
            iter = iter + (iter & (-1)*iter);
        }
    }
    for(int i=1;i<=M+K;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1) update(b,c,arr);
        else cout<<prefix_sum(b,c,arr)<<endl;
    }
}