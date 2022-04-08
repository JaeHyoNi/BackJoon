#include <bits/stdc++.h>
using namespace std;
int main(){
    int temp,N=10,ans = 0;
    for(int i=0;i<5;i++){
        cin>>temp;
        temp = temp * temp % N;
        ans += temp;
    }
    cout<<ans%10;
}