#include <bits/stdc++.h>
using namespace std;
int connect[101];
bool VISIT[101];

int gogo(int K){
    if(connect[K] == K) return K;
    else{
        while(connect[K] != K){K = connect[K];}
        return K;
    }
}
int main(){
    int siz,N,M,from,ans=0,temp,to;cin>>N>>M; N=N+M;
    bool find = false;
    for(int i=0;i<=100;i++){connect[i] = i;}
    while(N--){cin>>from>>to; connect[from] = to;}
    queue<int> wait; wait.push(1);
    while(1){
        siz = wait.size();
        ans+=1;
        for(int i=0;i<siz;i++){
            from = wait.front();wait.pop();
            for(int j=1;j<=6;j++){
                temp = from + j;
                if(temp == 100) {find = true;break;}
                to = gogo(temp);
                if(to == 100) {find = true;break;}
                if(VISIT[to]){}
                else{VISIT[to] = true; wait.push(to);}
            }
            if(find) break;
        }
        if(find) break;
    }
    cout<<ans;
    return 0;
}