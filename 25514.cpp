#include <bits/stdc++.h>
using namespace std;

struct loc{int x; int y; int now; int time;};
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
int arr[5][5];
int done[5][5][6];
int ans = 999999;

bool check(int x,int y){return (x>=0 && x<5 && y>=0 && y < 5);}

bool update(loc &T){
    if(arr[T.x][T.y] == T.now + 1){
        T.now +=1;
        if(T.now == 6){
            ans = min(T.time,ans);
            return false;
        }
    }
    if(done[T.x][T.y][T.now] < T.time) return false;
    else {
        done[T.x][T.y][T.now] = T.time;
        return true;
    }
}

void logging(loc K){
    printf("[%d,%d] - now : %d / time : %d\n",K.x,K.y,K.now,K.time);
}

int main(){
    loc now;
    for(int i=0;i<5;i++){for(int j=0;j<5;j++){for(int k=0;k<6;k++){done[i][j][k] = 99999;}}}
    for(int i=0;i<5;i++){for(int j=0;j<5;j++){cin>>arr[i][j];}}
    cin>>now.x>>now.y;
    now.now = 0 , now.time = 0;
    int a,b;
    bool is = true;
    loc temp,temp2,temp3;
    queue<loc> wait;
    wait.push(now);
    while(!wait.empty()){
        now = wait.front(); wait.pop();
        // cout<<"-------"<<"["<<now.x<<","<<now.y<<"]  /  "<<now.now<<"-------"<<endl;
        if(now.time+1 >= ans) continue;
        for(int i=0;i<4;i++){
            a = now.x + x[i] , b = now.y + y[i];
            if(check(a,b) && (arr[a][b] != -1)){
                temp = {a,b,now.now,now.time+1};
                if(update(temp)){
                    // logging(temp);
                    wait.push(temp);
                }
                while(check(a+x[i],b+y[i]) && arr[a+x[i]][b+y[i]] != -1){
                    a += x[i] , b += y[i];
                    if(arr[a][b] == 7) break;
                }
                if(check(a,b)){
                    temp = {a,b,now.now,now.time+1};
                    if(update(temp)){
                        // logging(temp);
                        wait.push(temp);
                    }
                }
            }
           
        }
    }
    if(ans == 999999){cout<<"-1\n";}
    else cout<<ans<<endl;
}