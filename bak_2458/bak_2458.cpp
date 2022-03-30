#include <bits/stdc++.h>
using namespace std;

bool arr[501][501];

int main(){
    int N,M,smaller,bigger,ans = 0;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&smaller,&bigger);
        arr[smaller][bigger] = 1;
    }
    for(int mid = 1; mid <= N; mid++){
        for(int from = 1; from <= N; from++){
            for(int to = 1; to <= N; to++){
                if(arr[from][mid] && arr[mid][to])
                    arr[from][to] = 1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout.width(2);
            cout<<arr[i][j];
        }cout<<endl;
    }

    for(int i=1;i<=N;i++){
        int pre = 1;
        int bac = N;
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 1) bac --;
            if(arr[j][i] == 1) pre ++;
        }
        if(pre==bac) ans++;
        //printf("I : %d , [%d,%d]\n",i,pre,bac);
    }
    cout<<ans;
}