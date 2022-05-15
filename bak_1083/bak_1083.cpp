#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ans;
    int N,S;
    scanf("%d",&N);
    int arr[50];
    for(int i=0;i<N;i++){scanf("%d",&arr[i]);}
    scanf("%d",&S);
    int i = 0,temp,t = S,target;
    while(S>0){
        if(i==N) break;
        if(i+S+1>=N)  {
            target = max_element(arr+i,arr+N)-arr;
        }
        else        {
            target = max_element(arr+i,arr+i+S+1)-arr;
        }
        temp = arr[target];
        for(int j=target-1;j>=i;j--){
            arr[j+1]=arr[j];
        }
        arr[i] = temp;
        S-= (target-i) ;
        i++;
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}