#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void power(ll a[4] , ll b[4]){
    ll temp[4] = {(a[0]*b[0]+a[2]*b[1])%1000000007, (a[0]*b[1]+a[1]*b[3])%1000000007, (a[2]*b[0]+a[3]*b[2])%1000000007, (a[2]*b[1]+a[3]*b[3])%1000000007};
    for(int i=0;i<4;i++){a[i] = temp[i];}
}

ll gcd(ll a, ll b){
    if (b==0 )  return a;
    else        return gcd(b,a%b);
}
int main(){
    ll N,M; cin>>N>>M;
    ll K = gcd(N,M);
    ll n[4] = {1,1,1,0};
    ll NEXT[4] = {1,1,1,0};
    stack<bool> num1,num2,k;
    while(K!=1){
        if(K%2==0) {K/=2; k.push(true);}
        else{K--; k.push(false);}
    }
    while(!k.empty()){
        if(k.top()) power(n , n);
        else{power(n,NEXT);}
        k.pop();
    }
    cout<<n[1]<<endl;
    return 0;
}