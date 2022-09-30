#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int A,B;
int N;
struct gogo{int val; int flag; bool use;};
gogo dp[2][4001];


int main(){
    cin>>N;
    arr.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr.begin(),arr.end());
    dp[0][0] = dp[1][0] = {0,0,false};
    for(int i=1;i<N;i++){
        int M = dp[0][i-1].val + arr[dp[1][i-1].flag];
        if(!dp[0][i-1].use && dp[1][i-1].flag+1 < N){
            M = max(M , M+arr[dp[1][i-1].flag+1])
        }
    }

}