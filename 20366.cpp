#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N; cin>>N;
    ll temp,pre,ans;
    vector<ll> ball(N);
    for(int i=0;i<N;i++) {cin>>ball[i]; }
    sort(ball.begin(),ball.end());
    for(int i=0;i<N-1;i++){
        for(int j=i+3;j<N;j++){
            for(int k=i+1;k<j-1;k++){
                pre = 99999999999;
                if(k==i || k==j) continue;
                for(int l=k+1;l<j;l++){
                    if(l==i || l==j) continue;
                    temp = abs( (ball[i]+ball[j]) - (ball[k]+ball[l]) );
                    if( pre < temp ) break;
                    pre = temp;
                    if(pre < ans) {ans = pre;}
                }
            }
        }
    }
    cout<<ans<<endl;
}
