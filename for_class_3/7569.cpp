#include <bits/stdc++.h>
using namespace std;

int arr[101][101][101] ,N,M,H;
typedef struct {int x; int y; int z;}point;

int main(){
    queue<point> wait;
    point tmp;
    int siz,sum = 0;    cin>>M>>N>>H;
    for(int k=0;k<H;k++){for(int i=0;i<N;i++){for(int j=0;j<M;j++){
        cin>>arr[i][j][k];
        if(arr[i][j][k] == 1){wait.push({i,j,k});}
        if(arr[i][j][k] == 0){sum += 1;}
    }}}
    int ans = 0;
    while(!wait.empty()){
        if(sum == 0) break;
        ans+=1;
        siz = wait.size();
        for(int i=0;i<siz;i++){
            tmp = wait.front();wait.pop();
            if(tmp.x -1 >= 0) {if(arr[tmp.x-1][tmp.y][tmp.z] == 0){arr[tmp.x-1][tmp.y][tmp.z] = 1;wait.push({tmp.x-1,tmp.y,tmp.z});sum--;}}
            if(tmp.x +1 < N)  {if(arr[tmp.x+1][tmp.y][tmp.z] == 0){arr[tmp.x+1][tmp.y][tmp.z] = 1;wait.push({tmp.x+1,tmp.y,tmp.z});sum--;}}
            if(tmp.y -1 >= 0) {if(arr[tmp.x][tmp.y-1][tmp.z] == 0){arr[tmp.x][tmp.y-1][tmp.z] = 1;wait.push({tmp.x,tmp.y-1,tmp.z});sum--;}}
            if(tmp.y +1 < M)  {if(arr[tmp.x][tmp.y+1][tmp.z] == 0){arr[tmp.x][tmp.y+1][tmp.z] = 1;wait.push({tmp.x,tmp.y+1,tmp.z});sum--;}}
            if(tmp.z -1 >= 0) {if(arr[tmp.x][tmp.y][tmp.z-1] == 0){arr[tmp.x][tmp.y][tmp.z-1] = 1;wait.push({tmp.x,tmp.y,tmp.z-1});sum--;}}
            if(tmp.z +1 < H)  {if(arr[tmp.x][tmp.y][tmp.z+1] == 0){arr[tmp.x][tmp.y][tmp.z+1] = 1;wait.push({tmp.x,tmp.y,tmp.z+1});sum--;}}
        }
    }
    if(sum != 0) cout<<"-1";
    else cout<<ans<<endl;
    return 0;
}