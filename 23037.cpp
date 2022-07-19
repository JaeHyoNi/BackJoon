#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,answer = 0; cin>>N;
    while(N>0){
        int t = N%10; N/=10;
        answer += (t*t*t*t*t);
    }
    cout<<answer;
}