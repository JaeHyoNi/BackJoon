#include <bits/stdc++.h>
using namespace std; 
struct point{int x;int y;};
vector<vector<char>> arr;

// ostream& operator <<(ostream& a, point& val){
//     printf("[%d,%d]",val.x,val.y);
//     return a;
// }

void mark(point A){
    arr[A.x][A.y]='*';
    arr[A.x+1][A.y-1] = arr[A.x+1][A.y+1] = '*';
    arr[A.x+2][A.y-2] =arr[A.x+2][A.y-1] =arr[A.x+2][A.y] =arr[A.x+2][A.y+1] =arr[A.x+2][A.y+2] = '*';
    return;
}

void dfs(point a,point b,point c){
    if(a.x+2 == b.x){mark(a);return;}
    else{
        point d = {(a.x+b.x)/2+1 ,(a.y+b.y)/2};
        point e = {(a.x+b.x)/2+1 ,(a.y+c.y)/2+1};
        point a_2 = {d.x-1,d.y+1};
        point a_3 = {e.x-1,e.y-1};
        int tmp = (b.y+c.y)/2;
        point b_2 = {b.x,tmp-1};
        point c_2 = {c.x,tmp+1};
        dfs(a,a_2,a_3);
        dfs(d,b,b_2);
        dfs(e,c_2,c);
    }
    return;
}

int main(){
    int N; cin>>N;
    int siz,tmp,M = (2*N-1),i=0;
    arr.resize(N,vector<char>(M,' '));
    dfs( { 0,M/2 }, { N-1,0 }, {N-1 ,M-1 });
    for(auto K:arr){
        for(auto J:K){
            cout<<J;
        }cout<<endl;
    }
}