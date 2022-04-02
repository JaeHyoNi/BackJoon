#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<pair<int,int>> point;

vector<vector<int>> solution(vector<vector<int>> dist) {
    vector<vector<int>> answer;
    int siz = dist[0].size();
    int max = 0;
    int maxX,maxY;    
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            if(dist[i][j] > max){
                max = dist[i][j];
                maxX = i; maxY = j;
            }
        }
    }
    for(int i=0;i<siz;i++){point.push_back({dist[maxX][i],i});}
    sort(point.begin(),point.end());
    for(auto K:point){arr.push_back(K.second);}
    answer.push_back(arr);
    reverse(arr.begin(),arr.end());
    answer.push_back(arr);
    return answer;
}

int main(){
    vector<vector<int>> answer;
    answer = solution({{0,2,3,1},{2,0,1,1},{3,1,0,2},{1,1,2,0}});
    for(auto K:answer){
        for(auto J:K){
            cout<<J;
        }cout<<endl;
    }
}