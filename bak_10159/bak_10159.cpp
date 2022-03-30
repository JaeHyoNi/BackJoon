#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];

int main(){
    int N,K,from,to;
    scanf("%d %d",&N,&K);
    for(int i=1;i<=K;i++){
        scanf("%d %d",&from,&to);
        arr[from][to] = 1;
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
        int ans = -1;
        for(int j=1;j<=N;j++){
            if(arr[i][j]  || arr[j][i] ) continue;
            else ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}