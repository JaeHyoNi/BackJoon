#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dflag = n-1,pflag = n-1;
    while(dflag >= 0 && deliveries[dflag] == 0 ){
        dflag--;
    }
    while(pflag >= 0 && pickups[pflag] == 0){
        pflag--;
    }
    cout<<dflag<<endl;
    cout<<pflag<<endl;
    int moving = 0;
    int psiz,dsiz;

    while(dflag>=0 || pflag >=0){
        moving = max(dflag,pflag);
        psiz = dsiz = cap;
        if(dflag> -1){
           while(dsiz > 0){
               if(deliveries[dflag] == 0) dflag--;
               if(dflag < 0) break;
               if(deliveries[dflag] == dsiz){
                   deliveries[dflag] = 0;
                   dsiz = 0;
                   while(deliveries[dflag] == 0) dflag--;
               }
               else if(deliveries[dflag] > dsiz){deliveries[dflag] -= dsiz; dsiz = 0;}
               else{
                   dsiz -= deliveries[dflag];
                   deliveries[dflag] = 0;
               }
           } 
           for(auto K:deliveries){
            cout<<K<<" ";
           }cout<<endl;
        }
        if(pflag> -1){
           while(psiz > 0){
               if(pickups[pflag] == 0) pflag--;
               if(pflag < 0 ) break;
               if(pickups[pflag] == psiz){
                   pickups[pflag] = 0;
                   psiz = 0;
                   while(pickups[pflag] == 0) pflag--;
               }
               else if(pickups[pflag] > psiz){pickups[pflag] -= psiz; psiz = 0;}
               else{
                   psiz -= pickups[pflag];
                   pickups[pflag] = 0;
               }
           }
           for(auto K:pickups){
            cout<<K<<" ";
           }cout<<endl;
        }
        answer += (moving+1)*2;
    }
    return answer;
}

int main(){
    cout<<solution( 2,7,{1, 0, 2, 0, 1, 0, 2},{0, 2, 0, 1, 0, 2, 0});
}