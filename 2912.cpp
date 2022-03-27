#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int ans = 0,deep = 10000000,K;

void insta(int start,int end , int left , int right,int num,int dep){
    if(start == left && end == right)   {
        if(ans == 0 || ans == -1) {
            if(ans == -1){
                if(deep < dep) return;
            }
            ans = arr[num];
        }
        else if(arr[num] == -1) {}
        else if(arr[num] != ans) {
            ans = -1;
            deep = min(deep,dep);
        }
        return;
    }
    else if(start > right || end < left)    return;
    int mid = (right-left)/2 + left;
    if(end <= mid){insta( start, end, left, mid, num*2,dep+1);}
    else if(mid + 1 <= start) {insta(start,end,mid+1,right,num*2+1,dep+1);}
    else{
        insta(start,mid,left,mid,num*2,dep+1);
        insta(mid+1,end,mid+1,right,num*2+1,dep+1);
    }
    return;
}

int main(){
    int N,C,M,A,B;

    ifstream fin; 
    ofstream fout;
    fin.open("test_txt/in.txt");
    fout.open("test_txt/out.txt");                                                    fin>>N>>C;
    //scanf("%d %d",&N,&C);
    int k = 1;
    while(k<N){k = k * 2;}
    arr.resize(k*2+1,0);
    K = k;
    for(int i=0;i<N;i++)
                                                         fin>>arr[k+i];
        //scanf("%d",&arr[k+i]);
    int i = k*2-1;
    while(i>0){
        if(arr[i] == arr[i-1]){
            arr[i/2] = arr[i];
        }
        else if(arr[i] == 0 || arr[i-1] == 0){
            arr[i/2] = arr[i]==0 ? arr[i-1] : arr[i];
        }
        else arr[i/2] = -1;
        i = i - 2;
    }
    //scanf("%d",&M);
                                                            fin>>M;
    for(int i=0;i<M;i++){
        ans = 0;deep = 10000000;
                                                            fin>>A>>B;
        //scanf("%d %d",&A,&B);
        insta( A, B, 1, k, 1,1);
        if(ans >0) {
            fout<<"yes "<<ans<<"\n";
            //printf("yes %d\n",ans);
        }
        else {
            fout<<"no\n";
            //printf("no\n");
        }
    }
    fin.close();
    fout.close();
    return 0;
}