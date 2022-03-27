#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,C,temp,at,target,pre;
    scanf("%d %d",&N,&C);
    vector<int> arr;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    C -= 2;
    if(C==0) {printf("%d",arr[N-1] - arr[0]); return 0;}
    int offset = (arr[N-1] - arr[0])/(C+1);
    bool find = false;
    pre = arr[0];
    int k = C;
    while(!find){
        while(k > 0){
            target = pre + offset;
            at = lower_bound(arr.begin(),arr.end(),target)-arr.begin();
            pre = arr[at];
            k = k - 1;
        }
        if(arr[N-1] - pre >= offset ){
            find = true;
        }
        else{
            k = C;
            pre = arr[0];
            offset = offset - 1;
        }
    }
    printf("%d",offset);
    return 0;
}