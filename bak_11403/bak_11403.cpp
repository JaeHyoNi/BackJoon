#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int mid=1;mid<=N;mid++){
        for(int from=1;from<=N;from++){
            for(int to=1;to<=N;to++){
                if(arr[from][mid] && arr[mid][to])
                    arr[from][to] = 1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    return 0;
}