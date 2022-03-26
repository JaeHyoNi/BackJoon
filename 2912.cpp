#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int insta(int &a,int &b){

}


int main(){
    int N,C,M,A,B;
    scanf("%d %d",&N,&C);
    arr.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d",&arr[N]);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&A,&B);
        cout<<insta(A,B);
    }
}