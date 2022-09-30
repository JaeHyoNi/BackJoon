#include <bits/stdc++.h>
using namespace std;
int weight[5][5] = {
    1,2,2,2,2,
    2,1,3,4,3,
    2,3,1,3,4,
    2,4,3,1,3,
    2,3,4,3,1
};
int arr[5][5][100001];
int siz;
vector<int> li;
int temp;
int dp(int l,int r,int step){
    if(step == siz) return 0;
    if(arr[l][r][step] != 0) return arr[l][r][step];
    int ans = INT32_MAX;
    ans = min ( dp(li[step],r,step+1) + weight[li[step]][l] ,
                dp(l,li[step],step+1) + weight[r][li[step]] );
    arr[l][r][step] = ans;
    return arr[l][r][step];
}


int main(){
    int next;
    while(1){
        cin>> next;
        if(next == 0) break;
        li.emplace_back(next);
    }
    siz = li.size();
    int answer = dp(0,0,0);
    cout<<answer;
}
    