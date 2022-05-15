#include <bits/stdc++.h>
using namespace std;
bool fuck[10];

bool check(int K){
    if(K<0 || K>1000000) return false;
    if(K==0){
        if(fuck[0] == false) return true;
        else return false;
    } 
    while(K!=0){
        if(fuck[K%10] == true){return false;break;}
        else K /=10;
    }
    return true;
}

int main(){
    int ans=0,N,M,tmp,larger,smaller; cin>>N>>M;
    for(int i=0;i<M;i++){cin>>tmp; fuck[tmp] = true;}
    ans = abs(N-100);
    if(M == 10){cout<<ans;return 0;}
    larger = N,smaller = N;
    
    while(!check(larger) && !check(smaller) ){
        larger++;smaller--;
    }
    if(check(larger)){
        tmp = abs(N-larger)+to_string(larger).size();
        ans = min(ans,tmp);
    }
    if(check(smaller)){
        tmp = abs(N-smaller)+to_string(smaller).size();
        ans = min(ans,tmp);
    }
    cout<<ans;
}