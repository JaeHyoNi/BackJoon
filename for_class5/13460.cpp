#include <bits/stdc++.h>
using namespace std;

pair<int,int> hole;
char arr[10][10];
int VISIT[10][10][10][10],ans = 99999999,N,M;
bool operator==(const pair<int,int> &a, const pair<int,int> &b){return (a.first == b.first)&(a.second == b.second);}

//0:위 1:왼 2:오른 3:아래
void DFS(int direct, int deep, pair<int,int> &R, pair<int,int> &B){
    if(deep > 10 || deep >= ans) return;
    pair<int,int> r = R , b = B;
    int x,y;
    if( direct == 0)    {x = -1,y =  0;}
    else if(direct == 1){x =  0,y = -1;}
    else if(direct == 2){x =  0,y =  1;}
    else if(direct == 3){x =  1,y =  0;}
    bool gor=true,gob=true;
    while(1){
        gor = gob = false;
        if(arr[r.first + x][r.second + y] == '.' && (r.first+x != b.first || r.second+y != b.second)){
            r.first+=x; r.second+=y;
            gor = true;
            if(r == hole){
                while(arr[b.first+x][b.second+y] == '.'){
                    b.first+=x; b.second+=y;
                    if(b==hole) return;
                }
                ans = deep;
                return;
            }
        }
        if(arr[b.first + x][b.second + y] == '.' && (b.first+x!=r.first || b.second+y != r.second)){
            gob = true;
            b.first+=x; b.second+=y;
            if(b == hole){return;}
        }
        if(gor == false && gob == false){break;}
    }
    if(VISIT[r.first][r.second][b.first][b.second] > deep){
        VISIT[r.first][r.second][b.first][b.second] = deep;
    }
    else{return;}
    if(R==r && B==b) return;
    for(int i=0;i<4;i++){DFS(i, deep+1, r, b);}
    DFS(0, deep+1, r, b);
    DFS(1, deep+1, r, b);
    DFS(2, deep+1, r, b);
    DFS(3, deep+1, r, b);
}

int main(){
    cin>>N>>M;
    memset(VISIT,11,10*10*10*10*sizeof(int));
    pair<int,int> B,R;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'B') {B = {i,j}; arr[i][j] = '.';}
            else if(arr[i][j] == 'R') {R = {i,j}; arr[i][j] = '.';}
            else if(arr[i][j] == 'O') {hole = {i,j}; arr[i][j] = '.';}
        }
    }
    VISIT[R.first][R.second][B.first][B.second] = 1;
    for(int i=0;i<4;i++){DFS(i, 1, R, B);}

    if(ans == 99999999){cout<<"-1";}
    else cout<<ans<<endl;
}