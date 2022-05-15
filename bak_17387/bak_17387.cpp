#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define point pair<ll,ll>

ll etpro(point a,point b,point c){
    ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
 
    temp = temp - a.second * b.first - b.second * c.first - c.second * a.first;
    if(temp > 0) return 1;
    else if(temp == 0) return 0;
    else return -1;
}

bool check(point a,point b,point c,point d){
    ll f = etpro(a,b,c) * etpro(a,b,d);
    ll s = etpro(c,d,a) * etpro(c,d,b);

    if(f == 0 && s == 0){
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return a<=d && c<=b;
    }
    else return f<=0 && s<=0;
}

int main(){
    point p1,p2,p3,p4,temp;
    scanf("%lld %lld %lld %lld",&p1.first,&p1.second,&p2.first,&p2.second);
    scanf("%lld %lld %lld %lld",&p3.first,&p3.second,&p4.first,&p4.second);
    if(check(p1,p2,p3,p4)) cout<<"1";
    else cout<<"0";
    return 0;
}