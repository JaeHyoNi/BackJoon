#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> narr;
int N,M;

void show(){
    for(auto K:narr){
        for(auto J:K){
            cout<<J<<" ";
        }cout<<endl;
    }cout<<endl;
}

int main(){
    cin>>N>>M;
    arr.resize(N,vector<char>(M));
    narr.resize(N,vector<int>(M,-1));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    int flag = 0,x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            x = i , y = j;
            if(narr[i][j] != -1) continue;
            else{
                queue<pair<int,int>> wait;
                narr[i][j] = flag;
                wait.push({i,j});
                while(1){
                    show();
                    wait.push({x,y});
                    if(arr[x][y] == 'U'){x--;}
                    else if(arr[x][y] == 'D'){x++;}
                    else if(arr[x][y] == 'L'){y--;}
                    else if(arr[x][y] == 'R'){y++;}
                    
                    if(narr[x][y] == -1){narr[x][y] = flag;}
                    else if(narr[x][y] == flag){flag++; break;}
                    else {
                        while(!wait.empty()){
                            narr[wait.front().first][wait.front().second] = narr[x][y];
                            wait.pop();
                        }
                        break;
                    }
                }
            }
        }
    }
    cout<<flag<<"\n";
}