#include <bits/stdc++.h>
using namespace std;
#define MAX 99999999
int N;
int road[16][16];
int d[1<<16][16];
int TSP(int visit, int now){
    visit |= (1<<now);
    if(visit == (1<<N) -1){
        if(road[now][0] != 0){
            return road[now][0];
        }
        else return MAX;
    }
    int& ret = d[visit][now];
    if(ret > 0){return ret;}
    ret = MAX;
    for(int i=0;i<N;i++){
        if( i != now && (visit&(1<<i))==0 && road[now][i] > 0){
            int temp = TSP(visit,i) + road[now][i];
            if(ret > temp){
                ret = temp;
            }
        }
    }
    return ret;
}

int main(){
    int ans; cin>>N;
    for(int i=0;i<N;i++){for(int j=0;j<N;j++){cin>>road[i][j];}}
    ans = TSP(0,0);
    if(ans == MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}