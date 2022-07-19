#include <bits/stdc++.h>
using namespace std;
map<string, int> arr;
map<string, bool> n; 
int main(){
    string temp;
    int N,M; cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp; 
        n[temp] = true;
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        if(n[temp]){
            arr[temp]+=1;
        }
    }
    int answer = 0;
    for(auto K:arr){
        answer+=K.second;
    }
    cout<<answer;
}