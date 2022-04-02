#include <bits/stdc++.h>
using namespace std;
bool arr[1000001];
int main(){
    int a,b,k;
    scanf("%d %d",&a,&b);
    for(int i=2;i<=b;i++){
        if(arr[i] == 0){
            if(i>=a) printf("%d\n",i);
            k = 2;
            while(i*k<=b){arr[i*k] = 1;k++;}
        }
    }
    return 0;
}