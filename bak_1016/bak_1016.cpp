#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define max 1000001
ll arr[max];
int main(){
    ll ans=0,from,to,temp,ii;
    scanf("%lld %lld",&from,&to);
    for(ll i=2; i*i<=to;i++){
        ii = i*i;
        temp = from / ii;
        if(from % ii != 0) temp = temp + 1;
        while(ii * temp <= to){
            arr[ii*temp - from] = 1;
            temp = temp + 1;
        }
    }
    for(ll i=0;i<to-from+1;i++){
        if(arr[i] == 0) ans = ans + 1;
    }
    cout<<ans;
}