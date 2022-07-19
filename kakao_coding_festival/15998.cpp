#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a,ll b){
    if(b==0){return a;}
    else{return gcd(b,a%b);}
}

int main(){
    const ll MAX = pow(10, 18);
    ll N,in,out,recharge,charge = 0; scanf("%lld",&N);
    ll MIN=0;
    bool contradiction = false;
    charge = 0;    
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &in, &out);
        if(in >= 0){
            charge += in;
            if(charge != out) {cout<<"-1"; return 0;}
        }
        else {
            if( charge >= -1*in){
                charge += in;
                if(charge != out){cout<<"-1"; return 0;}
            }
            else{
                recharge = out - in - charge;
                MIN = gcd(MIN, recharge);
                if(MIN == 1 && out != 0) {cout<<"-1"; return 0;}
                recharge = -1*(charge+in);
                recharge = recharge%MIN == 0 ? recharge/MIN : recharge/MIN+1;
                // printf("charge : %lld recharge : %lld ,MIN : %lld, next : %lld\n",charge,recharge,MIN,charge+in);
                charge += recharge*MIN;
                charge += in;
                if(charge != out){
                    cout<<"-1"; return 0;
                }
            }
        }
    }
    if(MIN == 0) {cout<<"1";}
    else cout<<MIN;
    return 0;
}

          
