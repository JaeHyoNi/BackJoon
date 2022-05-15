#include <bits/stdc++.h>
using namespace std;
#define INF 0
struct road{int from;int to;int val;};
int main(){
    vector<road> road,emp;
    bool came_back;
    int TC, N, M, W, a, b, c, tmp, Dis[501]; cin>>TC;
    while(TC--){
        came_back = false;
        scanf("%d %d %d",&N,&M,&W);
        fill_n(Dis,N+1,INF);
        while(M--){
            scanf("%d %d %d",&a,&b,&c);
            road.push_back({a,b,c});
            road.push_back({b,a,c});
        }
        while(W--){
            scanf("%d %d %d",&a,&b,&c);
            road.push_back({a,b,-1*c});
        }
        for (int i=0; i<N; i++) {
            for (int j = 0; j < road.size(); j++) {
                int from = road[j].from;
                int to = road[j].to;
                int val = road[j].val;
                if (Dis[from] + val < Dis[to]) {
                    Dis[to] = Dis[from] + val;
                    if(i == N-1){came_back = true; break;}
                }
            }
            if(came_back) break;
        }
        if(came_back)   {cout<<"YES\n";}
        else            {cout<<"NO\n";}
        road = emp;
    }
}