#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tomato[1001][1001];
int row,col;
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};


void pm(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<tomato[i][j];
        }cout<<endl;
    }
    cout<<endl;
}

bool check(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(tomato[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

int main(void){
    queue<pair<int,int>> wait;
    int siz,a,b,ta,tb,time = 0;
    bool is = false;
    cin>>col>>row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1){
                wait.push({i,j});
            }
        }
    }
    if(check()) {cout<<"0"; return 0;}
    while(!wait.empty()){
        siz = wait.size();
        for(int i=0;i<siz;i++){
            a = wait.front().first;
            b = wait.front().second;
            wait.pop();
            for(int j=0;j<4;j++){
                ta = a + x[j];
                tb = b + y[j];
                if(ta >= 0 && ta < row && tb < col && tb >= 0){
                    if(tomato[ta][tb] == 0){
                        tomato[ta][tb] = 1;
                        wait.push({ta,tb});
                    }
                }
            }
        }
        time = time + 1;
        if(check()) {
            is = true;
            break;
        }
    }
    if(is)  cout<<time<<endl;
    else    cout<<"-1"<<endl;
    
}
