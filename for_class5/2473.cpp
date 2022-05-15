#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int N; scanf("%d",&N);
    vector<ll> arr(N);
    ll temp,answer=99999999999,iter,k,a,b,c;
    for(int i=0;i<N;i++){scanf("%lld",&arr[i]);}
    sort(arr.begin(),arr.end());
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            temp = (arr[i]+arr[j])*-1;
            iter = lower_bound(arr.begin(),arr.end(),temp)-arr.begin();
            k = iter;
            while((i== k || k==j) && k<N) k++;
            if(k!= N && abs(temp*-1 + arr[k]) < answer) {answer = abs(temp*-1 + arr[k]); a=arr[i];b=arr[j];c=arr[k];} 
            k = iter-1;
            while((k==i || k==j) && k>-1) k--;p
            if(k != -1 && abs(temp*-1 + arr[k]) < answer) {answer = abs(temp*-1 + arr[k]); a=arr[i];b=arr[j];c=arr[k];} 
        }
    }
    vector<ll> ans = {a,b,c};
    sort(ans.begin(),ans.end());
    for(auto K:ans){cout<<K<<" ";}
}