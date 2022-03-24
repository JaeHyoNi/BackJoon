#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,tmp,sum = 0,st,en;
    scanf("%d",&N);
    vector<int> arr(N),arr2(N+1,0);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        sum = sum + arr[i];
        arr2[i+1] = sum;
    }
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&st,&en);
        printf("%d\n",arr2[en] - arr2[st-1]);
    }
    return 0;
}
