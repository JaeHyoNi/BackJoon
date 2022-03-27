#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,a,b,at,siz=0;
    scanf("%d",&N);
    vector<int> AB(501,0);
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        AB[a] = b;
    }
    vector<int> arr,LIS;
    for(auto K:AB){if(K!=0) arr.push_back(K);}
    LIS.push_back(arr[0]); siz = 1; 
    for(auto K:arr){
        at = lower_bound(LIS.begin(),LIS.end(),K)-LIS.begin();
        if(at == siz) {LIS.push_back(K); siz = siz + 1;}
        else LIS[at] = K;
    }
    printf("%d",arr.size()-siz);
}