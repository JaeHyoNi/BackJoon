#include<bits/stdc++.h>

using namespace std;
int arr[3][1000];
int main(){
    int N; cin>>N;
    cin>>arr[0][0]>>arr[1][0]>>arr[2][0];
    for(int i=1;i<N;i++){
        cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
        arr[0][i] += min(arr[1][i-1],arr[2][i-1]);
        arr[1][i] += min(arr[0][i-1],arr[2][i-1]);
        arr[2][i] += min(arr[0][i-1],arr[1][i-1]);
    }

    cout<<min(arr[0][N-1],min(arr[1][N-1],arr[2][N-1]));
}