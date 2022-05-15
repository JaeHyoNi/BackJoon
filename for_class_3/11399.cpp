#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int N; cin>>N;
    arr.resize(N,0);
    for(int i=0;i<N;i++){cin>>arr[i];}
    sort(arr.begin(),arr.end());
    for(int i=0;i<N-1;i++){
        arr[i+1] += arr[i];
    }
    cout<<accumulate(arr.begin(),arr.end(),0);
}