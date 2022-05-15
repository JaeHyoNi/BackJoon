#include <bits/stdc++.h>
using namespace  std;
#define point pair<int,int>

int main(){
    char arr[101][101],now;
    bool nor[101][101]={false,};
    bool adnor[101][101] = {false,};
    int N,normal=0,adnormal=0,a,b;cin>>N;
    int x[4] = {-1,0,1,0},y[4] = {0,1,0,-1};
    for(int i=0;i<N;i++){for(int j=0;j<N;j++){cin>>arr[i][j];}}
    point tmp;
    queue<point> wait;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!nor[i][j]){
                wait.push({i,j});
                now = arr[i][j];
                nor[i][j] =  true;
                while(!wait.empty()){
                    tmp = wait.front();wait.pop();
                    for(int k=0;k<4;k++){
                        a=tmp.first+x[k] , b=tmp.second+y[k];
                        if(a >= 0 && a<N && b >= 0 && b<N){
                            if(now==arr[a][b] && nor[a][b]==0){
                                wait.push({a,b});
                                nor[a][b] = true;
                            }
                        }
                    }
                }
                normal++;
            }
            if(!adnor[i][j]){
                wait.push({i,j});
                now = arr[i][j];
                adnor[i][j] = true;
                while(!wait.empty()){
                    tmp = wait.front();wait.pop();
                    for(int k=0;k<4;k++){
                        a=tmp.first+x[k] , b=tmp.second+y[k];
                        if(a >= 0 && a<N && b >= 0 && b<N){
                            if((now==arr[a][b]) || (now=='R' && arr[a][b]=='G') || (now=='G' && arr[a][b]=='R')){
                                if(adnor[a][b]==0) {wait.push({a,b});adnor[a][b] = true;}
                            }
                        }
                    }
                }
                adnormal++;
            }
        }
    }
    cout<<normal<<" "<<adnormal;
}