#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
vector<ll> arr;

bool check(ll K,ll K2){
    if(sqrt(K)==(int)sqrt(K)){K = (int)sqrt(K);}
    else return false;
    if(sqrt(K2)==(int)sqrt(K2)){K2 = (int)sqrt(K2);}
    else return false;
    K = K*K2;
    if(sqrt(K)==(int)sqrt(K)){return true;}
    else return false;
}

int main(){
    bool can;
    int N; cin>>N; arr.resize(N);
    for(int i=0;i<N;i++) {cin>>arr[i];}
    for(int i=0;i<N-1;i++){
        if(arr[i]<=arr[i+1]) continue;
        for(int j=i+1;j<N;j++){
            can = false;
            if(check(arr[i],arr[j])){
                swap(arr[i],arr[j]);
                can = true;
                break;
            }
        }
        if(can == false){cout<<"NO"; return 0;}
    }
    cout<<"YES";
}