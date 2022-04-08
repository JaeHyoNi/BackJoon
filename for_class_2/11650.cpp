#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> arr;
    int N;cin>>N;
    arr.resize(N);
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end());
    for(auto K:arr){
        printf("%d %d\n",K.first,K.second);
    }    
    return 0;
}