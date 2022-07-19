#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> arr;
ll N;

ll calcul(ll K){
    ll now = 0,Sum = 0;
    for(int i=0;i<N;i++){
        Sum += abs(arr[i] - now);
        now += K;
    }
    return Sum;
}

int main(){
    ll mid1,mid2,lo,hi;
    cin>>N; arr.resize(N);
    for(int i=0;i<N;i++){cin>>arr[i];}
    lo = 0 , hi = arr[N-1];
    while(lo+3 < hi){
        mid1 = (2*lo + hi)/3;
        mid2 = (lo+2*hi)/3;
        if(calcul(mid1) < calcul(mid2)) hi = mid2;
        else lo = mid1;
    }
    ll answer = LLONG_MAX;
    for(int i=lo; i<=hi; i++){
        answer = min(answer,calcul(i));
    }
    cout<<answer;
}