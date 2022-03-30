#include <bits/stdc++.h>
using namespace std;
int N;

int gcd(int a,int b){
    if (b==0) return a;
    int tmp = a;
    while(b>0){
        tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int main(){
    int temp;
    scanf("%d",&N);
    vector<int> arr(N,0);
    vector<int> arr2;
    for(int i=0;i<N;i++){scanf("%d",&arr[i]);}
    bool same = true;
    for(int i=0;i<N-1;i++){arr2.push_back(abs(arr[i] - arr[i+1]));}
    int common = arr2[0];
    for(int i=1;i<N-1;i++){
        common = gcd(common,arr2[i]);
    }
    vector<int> ans;
    for(int i=2;i<=sqrt(common);i++){
        if(common % i == 0){
            ans.push_back(i);
            if(i != sqrt(common))   ans.push_back(common/i);
        }
    }
    ans.push_back(common);
    sort(ans.begin(),ans.end());
    for(auto K:ans) cout<<K<<endl;
    return 0;
}