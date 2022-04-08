#include <bits/stdc++.h>
using namespace std;
int arr[10001];

int main(){
    int N,t;cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&t);
        arr[t]++;
    }
    for(int i=0;i<10001;i++){
        if(arr[i]!=0){
            for(int j=0;j<arr[i];j++){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
