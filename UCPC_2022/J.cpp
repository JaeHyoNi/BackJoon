#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
vector<ll> arr;
vector<bool> findprime(10000001);
vector<ll> prime;
bool check(ll N){
    for(auto K:prime){
        if(K>N) break;
        while(N%K==0) N/=K;
    }
    if(sqrt(N)==(int)sqrt(N)){return true;}
    else return false;
}

void checkprime(){
    ll num = 10000000;
    for (int i = 2; i <= num; i++) {
        if (findprime[i] == 0) {prime.emplace_back(i*i);continue;}
        for (int j = i + i; j <= num; j += i) { findprime[j] = 0;}
    }
}

int main(){
    checkprime();
    bool can;
    int N; cin>>N; arr.resize(N);
    for(int i=0;i<N;i++) {cin>>arr[i];}
    for(int i=0;i<N-1;i++){
        if(arr[i]<=arr[i+1]) continue;
        for(int j=i+1;j<N;j++){
            can = false;
            if(check(arr[i]*arr[j])){
                swap(arr[i],arr[j]);
                can = true;
                break;
            }
        }
        if(can == false){cout<<"NO"; return 0;}
    }
    cout<<"YES";
}