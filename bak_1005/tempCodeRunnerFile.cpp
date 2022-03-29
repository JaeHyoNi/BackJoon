#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}


int main(){
    int T,N,K,from,to,target,now;
    int planet_time[1001] = {0,};   //건설시간 저장하는 배열
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&K);
        int planet[1001] = {0,};        //연결된 간선개수 세는 배열
        vector<int> road[1001];
        vector<int> answer(N+1,0);
        int visit[1001] = {0,};
        for(int i=1;i<=N;i++) scanf("%d",&planet_time[i]);
        for(int i=0;i<K;i++){
            scanf("%d %d",&from,&to);
            planet[to]  ++;
            road[from].push_back(to);
        }
        scanf("%d",&target);
        queue<int> wait;
        for(int i=1;i<=N;i++){
            if(planet[i] == 0){
                wait.push(i); 
                answer[i] = planet_time[i];
            }
        }
        while(!wait.empty()){
            now = wait.front();
            visit[now] = 1;
            wait.pop();
            for(auto K:road[now]){
                planet[K]--;
                answer[K] = max( answer[K] , planet_time[K] + answer[now] );
            }
            for(int i=1;i<=N;i++){
                if(visit[i] == 0 && planet[i] == 0){
                    wait.push(i);
                }
            }
        }
        textcolor(4);
        printf("%d\n",answer[target]);
        textcolor(7);
    }
}