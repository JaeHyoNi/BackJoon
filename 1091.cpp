#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ans=0;cin>>N;
    vector<int> ord,ran,now,tmp,emp;
    ord.resize(N);ran.resize(N),now.resize(N),tmp.resize(N),emp.resize(N,0);
    for(int i=0;i<N;i++){cin>>ord[i];}    
    for(int i=0;i<N;i++){cin>>ran[i];now[i] = i%3;}
    if(ord == now) {cout<<"0"; return 0;}
    while(1){
        tmp = emp;
        for(int i=0;i<N;i++){tmp[i] = now[ran[i]];}
        now = tmp;
        bool cycle = true;
        for(int i=0;i<N;i++){if(now[i] != i){cycle = false;break;}}
        if(cycle || ans > 200000) {cout<<"-1"; break;}
        else ans+=1;
        if(ord == now){cout<<ans;break;}
    }
    return 0;
}