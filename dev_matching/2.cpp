#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};

char arr[9][9];
vector<pair<int,int>> point;
int row,column;
//최대 2^9번까지
//하나씩 바꾸고 dfs후 판별

bool check(){
    bool temp[9][9] = {0,};
    queue<pair<int,int>> tt;
    int tx,ty;
    bool visit[3] = {0,0,0};
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            if(temp[i][j] == 0){
                tt.push({i,j});
                if(arr[i][j] == 'a') {
                    if(visit[0] == 1) return false;
                    visit[0] = 1;
                }
                else if(arr[i][j] == 'b') {
                    if(visit[1] == 1) return false;
                    visit[1] = 1;
                }
                else {
                    if(visit[2] == 1) return false;
                    visit[2] = 1; 
                }
                while(!tt.empty()){
                    for(int k=0;k<4;k++){
                        tx = tt.front().first + x[k];
                        ty = tt.front().second + y[k];
                        if(tx >= 0 && ty >= 0 && tx < column && ty < row){
                            if(temp[tx][ty] == 0 && arr[tx][ty] == arr[i][j]){
                                temp[tx][ty] = 1;
                                tt.push({tx,ty});
                            }
                        }
                    }
                    tt.pop();
                }
            }
        }
    }
    return true;
}

int ans,siz;
void dfs(int dep){
    if(dep == siz){
        if(check()) ans++;
        return;
    }
    arr[point[dep].first][point[dep].second] = 'a';
    dfs(dep+1);
    arr[point[dep].first][point[dep].second] = 'b';
    dfs(dep+1);
    arr[point[dep].first][point[dep].second] = 'c';
    dfs(dep+1);
    return;
}


int solution(vector<string> grid) {
    row = grid[0].size();
    column = grid.size();
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            arr[i][j] = grid[i][j];
            if(arr[i][j] == '?'){
                point.push_back({i,j});
            }
        }
    }
    siz = point.size();
    sort(point.begin(),point.end());
    dfs(0);
    return ans;
}

int main(){
    solution({"aa?"});

    cout<<ans;
}