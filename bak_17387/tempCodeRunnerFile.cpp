#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define point pair<ll,ll>

point operator +(const point &a,const point &b){return {a.first + b.first,a.second + b.second};}
point operator -(const point &a,const point &b){return {a.first - b.first,a.second - b.second};}

//외적 결과값
ll etpro(point a,point b,point c){
    return (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
}

//시계방향인가?
bool check(point a,point b,point c,point d){
    ll f = etpro(a,b,c) * etpro(a,b,d);
    ll s = etpro(c,d,a) * etpro(c,d,b);
    if(f<=0 && s<=0){
        if(f == 0 && s == 0){
            if(a>b) swap(a,b);
            if(c>d) swap(c,b);
            // if(b<c) return false;
            // else return true;
            return a>=d && c<=b;
        }
        else return true;
    }
    else return false;
}

int main(){
    point p1,p2,p3,p4,temp;
    scanf("%lld %lld %lld %lld",&p1.first,&p1.second,&p2.first,&p2.second);
    scanf("%lld %lld %lld %lld",&p3.first,&p3.second,&p4.first,&p4.second);
    if(check(p1,p2,p3,p4)) cout<<"1";
    else cout<<"0";
    return 0;
}