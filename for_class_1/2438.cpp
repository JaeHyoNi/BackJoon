#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,T;cin>>N;
    T = N;
    while(T--){
        for(int i=0;i<T;i++) cout<<" ";
        for(int i=T;i<N;i++) cout<<"*";
        cout<<endl;
    }
    cout<<endl;
}