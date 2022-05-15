#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define point pair<ll,ll>

ll etpro(point &a,point &b,point &c){
    ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
 
    temp = temp - a.second * b.first - b.second * c.first - c.second * a.first;
    if(temp > 0) return 1;
    else if(temp == 0) return 0;
    else return -1;
}

bool check(point &a,point &b,point &c,point &d){
    ll f = etpro(a,b,c) * etpro(a,b,d);
    ll s = etpro(c,d,a) * etpro(c,d,b);

    if(f == 0 && s == 0){
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return a<=d && c<=b;
    }
    else return f<=0 && s<=0;
}

bool check2(point &a,point &b,point &lt,point &rb){
    if(lt.first <= a.first && lt.first<=b.first && lt.second>=a.second && lt.second>=b.second
    && rb.first >= a.first && rb.first >= b.first && rb.second <= a.second && rb.second <= b.second)
        return true;
    else return false;
}

int main(){
    int N;
    ll sx,bx,sy,by;
    point from,to,lb,lt,rb,rt,temp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld %lld %lld %lld",&from.first,&from.second,&to.first,&to.second);
        scanf("%lld %lld %lld %lld",&sx,&sy,&bx,&by);
        if(sx > bx) swap(sx,bx);
        if(sy > by) swap(sy,by);
        lt = {sx,by};
        rb = {bx,sy};
        lb = {lt.first , rb.second};
        rt = {rb.first ,lt.second};
        // printf("lb = [%lld,%lld]\n",lb.first,lb.second);
        // printf("lt = [%lld,%lld]\n",lt.first,lt.second);
        // printf("rt = [%lld,%lld]\n",rt.first,rt.second);
        // printf("rb = [%lld,%lld]\n",rb.first,rb.second);
        if(check2(from,to,lt,rb)) cout<<"T"<<endl;
        else if(check(from,to, lt  , lb   )) cout<<"T"<<endl;
        else if(check(from,to, lt  , rt   )) cout<<"T"<<endl;
        else if(check(from,to, lb  , rb   )) cout<<"T"<<endl;
        else if(check(from,to, rb  , rt  )) cout<<"T"<<endl;
        else cout<<"F"<<endl;
    }
    return 0;
}