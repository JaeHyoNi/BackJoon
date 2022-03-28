#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,temp;
    priority_queue<int> arr;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        if(temp == 0){
            if(arr.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n",arr.top());
                arr.pop();
            }
        }
        else{
            arr.push(temp);
        }
    }
    return 0;
}