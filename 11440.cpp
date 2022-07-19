#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void power(ll a[][2],ll b[][2]){
    ll n[2][2] = {{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                n[i][j] += (a[i][k]*b[k][j]);
                n[i][j] %= 1000000007;
            }
        }
    }
    for(int i=0;i<2;i++){for(int j=0;j<2;j++){a[i][j] = n[i][j];}}
}
int main(){
    ll N; cin>>N;
    long long arr[2][2] = {{1,1},{1,0}};
    long long n[2][2] = {{1,1},{1,0}};
    stack<bool> ord;
    while(N!=1){
        if(N%2==0){ord.push(1); N/=2;}
        else{ord.push(0); N--;}
    }
    while(!ord.empty()){
        if(ord.top()){power(arr,arr);}
        else{power(arr,n);}
        ord.pop();
    }
    ll n1 = arr[0][1];
    power(arr,n);
    ll n2 = arr[0][1];
    cout<<n1*n2 % 1000000007;
}