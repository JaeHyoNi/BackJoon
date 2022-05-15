#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;
int main(){
    int N,pre; scanf("%d",&N);
    long long tmp;
    while(N--){
        scanf("%lld",&tmp);
        arr.emplace_back(tmp);        
    }
    int s = 0,e = arr.size()-1;
    pre = arr[s] + arr[e];
    bool switching = true;
    long long answer = 2100000000;
    int a,b;
    while(e-s != 1){
        tmp = arr[s] + arr[e];
        if(abs(tmp) < answer){answer = abs(tmp);a=arr[s],b=arr[e];}
        if(switching){
            if( abs(arr[s] + arr[e-1] ) > tmp ){
                !switching;
                s++;
            }
            else{
                e--; pre = tmp;
            }
        }
        else{
            if( abs(arr[s+1] + arr[e]) > tmp ){
                !switching;
                e--;
            }
            else{
                s++; pre = tmp;
            }
        }
    }
    tmp = arr[s] + arr[e];
    if(abs(tmp) < answer){answer = abs(tmp);a=arr[s],b=arr[e];}
    cout<<a<<" "<<b;
}