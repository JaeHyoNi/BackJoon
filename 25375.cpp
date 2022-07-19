#include <bits/stdc++.h>
using namespace std;

int main(){
    long long Q,a,b,f; scanf("%lld",&Q);
    while(Q--){
        scanf("%lld %lld",&a,&b);
        if(b%a != 0 || b/a == 1){printf("0\n");}
        else {printf("1\n");}
    }
}