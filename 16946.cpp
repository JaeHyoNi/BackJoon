#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000];
bool arr[1000][1000],visited[1000][1000];
int N,M;
int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};
struct point{int x; int y;};
int flag = 0;

bool valid(int x,int y){return (x >= 0 && y >= 0 && x < N && y < M);}

vector<int> size_cache;
void BFS(int a,int b){
    if(visited[a][b]) return;
    if(arr[a][b]) {
        ans[a][b] = -1; 
        return;
    }
    queue<point> wait;
    visited[a][b] = true;
    wait.push({a,b});
    int siz = 0;
    point temp;
    while(!wait.empty()){
        temp = wait.front(); wait.pop(); 
        ans[temp.x][temp.y] = flag;  
        siz++;     
        for(int i=0; i<4; i++){
            if(valid(temp.x+x[i], temp.y+y[i])){
                if(!arr[temp.x+x[i]][temp.y+y[i]] && !visited[temp.x+x[i]][temp.y+y[i]]){
                    wait.push({temp.x+x[i] , temp.y+y[i]});
                    visited[temp.x+x[i]][temp.y+y[i]] = true;
                }
            }
        }
    }
    flag++;
    size_cache.push_back(siz);
}

int main(){
    cin>>N>>M;
    int temp;
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<M;j++){
            if(str[j] == '0') arr[i][j] = false;
            else arr[i][j] = true;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0; j<M; j++){
            BFS(i,j);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(ans[i][j] == -1){
                temp = 0;
                set<int> t;
                for(int k=0;k<4;k++){
                    if(valid(i+x[k],j+y[k]) && ans[i+x[k]][j+y[k]] != -1){
                        t.insert(ans[i+x[k]][j+y[k]]);
                    }
                }
                for(auto K:t){temp += size_cache[K];}
                cout<<(temp+1)%10;
            }
            else{cout<<"0";}
        }
        cout<<"\n";
    }
}