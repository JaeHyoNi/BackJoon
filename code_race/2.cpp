#include<bits/stdc++.h>
using namespace std;
vector<int> arr,ans;
int N;
map<int,int> m;

int do_fun(){
    int num = 0;
    for(int i=0;i<N;){
        if(arr[i] != ans[i]){
            int idx = m[ans[i]];
            m[arr[i]] = idx;
            swap(arr[i],arr[idx]);
            num++;
        }
        else i++;
    }
    return num;
}


int main(){
    cin>>N; arr.resize(N);
    for(int i=0;i<N;i++){scanf("%d",&arr[i]);}
    ans = arr;
    sort(ans.begin(),ans.end());
    int i = 0;
    for(auto K:arr){
        m[K] = i++;
    }
    int answer = do_fun();
    cout<<answer;
}