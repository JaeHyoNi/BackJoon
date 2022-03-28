#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<bool> arr(10001,1);
    arr[0] = 0 , arr[1] = 0;
    int temp = 0;
    for(int i=2;i<10001;i++){
        int t = 2;
        while(i*t <=10001){arr[i*t] = 0;t++;}
    }
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        for(int i=temp/2;i<temp;i++){
            if(arr[i] == 1){
                if(arr[temp-i]){
                    cout<<temp-i<<" "<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}