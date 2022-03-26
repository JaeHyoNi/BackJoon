#include <bits/stdc++.h>
using namespace std;
int arr[350000][2];
int t = 0;
int all = 0;
void result(int start,int end,int left,int right,int num,pair<int,int> &ans){
    t++;
    if(start == left && end == right){
        ans =  {min(arr[num][0] , ans.first), max( arr[num][1] , ans.second ) };
        return;
    }
    if(start > right || end < left) return;
    int left_end = (right - left)/2+left;
    int right_start = left_end + 1;
    if      (end <= left_end)       {result(start, end,        left, left_end,   num*2, ans);}
    else if (start >= right_start)  {result(start, end, right_start,    right, num*2+1, ans);}
    else{
        result(      start, left_end,        left, left_end,   num*2,  ans);
        result(right_start,      end, right_start,    right, num*2+1,  ans);
    }
    return; 
}


int main(){
    int N,M,k=1;
    scanf("%d %d",&N,&M);
    while(k<N){k = k * 2;}
    
    for(int i=0;i<k*2+1;i++){
        arr[i][0] = 1000000001;
    }
    all = k;
    for(int i=0;i<N;i++){scanf("%d",&arr[i + k][0]); arr[i+k][1] = arr[i+k][0];}
    k = k*2-1;
    while(k!=1){
        arr[k/2][0] = min(arr[k][0],arr[k-1][0]);
        arr[k/2][1] = max(arr[k][1],arr[k-1][1]);
        k -= 2;
    }
    int a,b;
    pair<int,int> temp;
    for(int i=0;i<M;i++){
        temp = {1000000001,-1};
        t = 0;
        scanf("%d %d",&a,&b);
        result(a,b,1,all,1,temp);
        printf("%d %d\n",temp.first,temp.second);
    }
}