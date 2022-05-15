#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int N,S;
    scanf("%d",&N);
    arr.resize(N,0);
    for(int i=0;i<N;i++){scanf("%d",&arr[i]);}
    scanf("%d",&S);
    int i = 0,temp;
    while(S--){
        while(arr[i] > arr[i+1]){i++;}
        if(i>=N-1) {
            i=0;
            while(arr[i] > arr[i+1]){i++;}
            if(i>=N-1)  {break;}
        }
        swap(arr[i],arr[i+1]);
    }
    for(auto K:arr) cout<<K<<" ";
}