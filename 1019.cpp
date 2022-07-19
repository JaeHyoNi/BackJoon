#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C; cin>>A>>B>>C;
    int arr[10]={0,},MUL;
    MUL = A*B*C;
    while(MUL!=0){
        arr[MUL%10]+=1;
        MUL/=10;
    }
    for(int i=0;i<10;i++){cout<<arr[i]<<endl;}
}