#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
long long ans;
void merge(int left,int right){
    vector<int> temp;
    int mid = (left+right)/2;
    int a = left,b = mid+1;
    int offset = 0;
    while(a<=mid && b<=right){
        if(arr[a]<=arr[b]){temp.push_back(arr[a++]); ans += offset;}
        else{temp.push_back(arr[b++]); offset++;}
    }
    while(a<=mid){temp.push_back(arr[a++]); ans+=offset;}
    while(b<=right){temp.push_back(arr[b++]);}
    a = left;
    for(auto K:temp){
        arr[left] = K;
        left++;
    }
    return;
}
void merge_sort(int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,right);
    }
}

int main(){
    int N,tmp,x;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        arr.push_back(x);
    }
    merge_sort(0,N-1);
    cout<<ans;
}

//  1 2 3
//  3 2 1
//  1 8 6 7 5 3 2 4
//  1 2 3 4 5 6 7 8
//  
//  1 8 6 7 5 3 2 4    6/8
//  1 6 7 5 3 2 4 8    4/7
//  1 6 5 3 2 4 7 8    4/6
//  1 5 3 2 4 6 7 8    3/5
//  1 3 2 4 5 6 7 8    1/3
//  1 2 3 4 5 6 7 8    1/1
