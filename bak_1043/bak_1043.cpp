#include <bits/stdc++.h>
using namespace std;
bool know[51];
vector<int> connect[51],party[51],know2;

void dfs(int n){
    know[n] = 1;
    for(auto K : connect[n]){
        for(auto J : party[K]){
            if(!know[J]) dfs(J);
        }
    }
}
int main(){
    int N,M,party_num,temp;
    scanf("%d %d",&N,&M);
    scanf("%d",&party_num);
    for(int i=0;i<party_num;i++) {
        scanf("%d",&temp);
        know2.push_back(temp);
    }
    for(int i=1;i<=M;i++){
        scanf("%d",&party_num);
        for(int j=0;j<party_num;j++){
            scanf("%d",&temp);
            connect[temp].push_back(i);
            party[i].push_back(temp);
        }
    }
 
    for(auto a : know2) {dfs(a);}
    int ans = 0;
    for(int i=1;i<=M;i++){
        bool ok = 1;
        for(auto J : party[i]) {
            if(know[J]){
                ok = 0;
                break;
            }
        }
        if(ok) ans++;
    }
    printf("%d",ans);
}