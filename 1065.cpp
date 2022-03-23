#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,ans = 0,a,b,c;
    cin>>N;
    for(int i=1;i<=N;i++){
        if(i<10) ans = ans + 1;
        else if(i<100) ans = ans + 1;
        else{
            a = i/100;
            b = i%100/10;
            c = i%100%10;
            if(a-b == b-c) {
                ans = ans + 1;
            }
        }
    }
    cout<<ans;
}
