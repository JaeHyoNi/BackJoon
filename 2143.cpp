#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
int main(){
    ll T,A,B,aa,bb,ans=0;   cin>>T;
    vector<ll> a,b;
    cin>>A; a.resize(A);
    for(int i=0;i<A;i++){cin >> a[i];}
    cin>>B; b.resize(B);
    for(int i=0;i<B;i++){cin>> b[i];}

    for(int i=0;i<A;i++){
        ll temp = a[i]; 
        for(int j=i+1;j<A;j++){
            temp += a[j];
            a.emplace_back(temp);
        }
    }
    for(int i=0;i<B;i++){
        ll temp = b[i];
        for(int j=i+1;j<B;j++){
            temp += b[j];
            b.emplace_back(temp);
        }
    }
    sort(b.begin(),b.end());
    for(auto K: a){
        ll target = T - K;
        aa = lower_bound(b.begin(),b.end(),target) - b.begin();
        bb = upper_bound(b.begin(),b.end(),target) - b.begin();
        ans += (bb-aa);
    }
    cout<<ans<<"\n";
}
