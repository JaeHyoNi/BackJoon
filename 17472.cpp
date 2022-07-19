#include <bits/stdc++.h>
using namespace std;
#define MAX  999
int arr[10][10];
struct po{int x;int y;};
struct graph{int from;int to;int val;};
int  num=2;
vector<vector<int>> road;
int parent[50];

int getParent(int son){
    if(parent[son] == son) return son;
    else return getParent(parent[son]);
}    

int main(){
    int N,M; cin>>N>>M;
    int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1} ,xx,yy,xxx,yyy,temp;
    int answer = 0,start,end,plus = 0;
    for (int i=0;i<N;i++){for(int j=0;j<M;j++){cin>>arr[i][j];}}
    queue<po> wait;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==1){   
                wait.push({i,j});
                while(!wait.empty()){
                    xx = wait.front().x, yy=wait.front().y; wait.pop();
                    arr[xx][yy] = num;
                    for(int k=0;k<4;k++){
                        xxx= xx+x[k] , yyy=yy+y[k];
                        if(xxx>=0 && yyy>=0 && xxx<N && yyy<M){
                            if(arr[xxx][yyy]==1){wait.push({xxx,yyy});}
                        }
                    }
                }
                num+=1;
            }
        }
    }
    for(int i=0;i<N;i++){for(int j=0;j<M;j++){if(arr[i][j]>1) arr[i][j]--;}}
    num -= 2;
    for(int i=1;i<=num;i++){parent[i] = i;}
    road.resize(num+1,vector<int>(num+1,MAX));
    pair<int,int> direct[4] = {{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] != 0){
                for(int k=0;k<4;k++){
                    temp = 0, xx = i+direct[k].first, yy= j+direct[k].second;
                    while(xx>=0 && xx<N && yy>=0 && yy<M && arr[xx][yy]==0){
                        xx += direct[k].first , yy += direct[k].second , temp++; 
                    }
                    if(xx>=0 && xx<N && yy>=0 && yy<M && arr[xx][yy]>0 && arr[xx][yy] != arr[i][j] && temp>=2){
                        road[arr[i][j]][arr[xx][yy]] = min(road[arr[i][j]][arr[xx][yy]] , temp);
                    }
                }
            }
        }
    }
    vector<graph> roads;
    for(int i=1;i<=num;i++){
        for(int j=1;j<i;j++){
            if(road[i][j]!=MAX){
                roads.push_back({j,i,road[i][j]});
            }
        }
    }
    sort(roads.begin(),roads.end(),[](graph &a, graph &b){return a.val<=b.val;});
    for(auto K: roads){
        if(plus == num-1){break;}
        start = getParent(K.from);
        end = getParent(K.to);
        if(start != end){
            answer += K.val;
            parent[end] = start;
            plus++;
        }
    }
    if(answer == 0 || plus != num-1){cout<<"-1";}
    else cout<<answer<<endl;
}