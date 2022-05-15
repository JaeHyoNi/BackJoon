#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int arrtrue[1001][1001];
int arrfalse[1001][1001];
struct point{int x;int y;int dis;bool chance;};
int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};
int main(){
    int N,M,a,b,siz,ans=0; cin>>N>>M;
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<M;j++){
            arr[i][j] = str[j]-'0';
            arrtrue[i][j] = arrfalse[i][j] = 2100000000;
        }
    }
    if(N==1 && M==1 ) {cout<<1;return 0;}
    bool find = false;
    queue<point> wait;
    point tmp;
    wait.push({0,0,0,true});
    while(!wait.empty()){
        siz = wait.size();
        while(siz--){
            tmp = wait.front(); wait.pop();
            for(int i=0;i<4;i++){
                a = tmp.x + x[i] , b = tmp.y + y[i];
                if(!(a>=0 && b>=0 && a<N && b<M)) continue;
                if((a == N-1) && (b == M-1)){find = true;ans = tmp.dis+2; break;}

                if(tmp.chance){if(arrtrue[a][b] <= tmp.dis+1) continue;}
                else          {if(arrtrue[a][b] <= tmp.dis+1 || arrfalse[a][b] <= tmp.dis+1) continue;}
                if(arr[a][b] == 0){
                    if(tmp.chance != false) arrtrue[a][b] = tmp.dis+1;
                    arrfalse[a][b] = tmp.dis+1;
                    wait.push({a,b,tmp.dis+1,tmp.chance});
                }
                else if(tmp.chance == true){
                    arrfalse[a][b] = tmp.dis+1;
                    wait.push({a,b,tmp.dis+1,false});
                }
            }
            if(find){break;}
        }
        if(find){break;}    
    }
    if(find)    cout<<ans;
    else cout<<"-1";
}