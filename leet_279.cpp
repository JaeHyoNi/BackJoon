#include <bits/stdc++.h>
using namespace std;






int solution(int n){
    int N = (int)sqrt(n),j,tmp;
    vector<int> DP(n+1);
    for(int i=1;i<=n;i++){DP[i] = i;}
    for(int i=2; i<=N; i++){
        tmp = i*i;  DP[tmp] = 1;
        for(int k=tmp;k<=n;k++){
            DP[k] = min(DP[k-tmp] + 1, DP[k]);
        }
    }
    return DP[n];
}






int main(){
    for(int i=1;i<90;i++){
        cout<<i<<" : ";
        cout<<solution(i)<<endl;
    }
}                                                                   