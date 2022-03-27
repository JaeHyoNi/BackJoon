#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

typedef struct kru{
    int from;int to;int val;
}KS;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool compare(KS &d1,KS &d2){return d1.val<d2.val;}

int main(){
    int N,t1,t2,temp;
    scanf("%d",&N);
    vector<KS> road;
    vector<KS> vertex(N+1);
    parent.resize(N+1);
    for(int i=1;i<N+1;i++) parent[i] = i;
    for(int i=1;i<N+1;i++){  
        scanf("%d %d %d",&vertex[i].from,&vertex[i].to,&vertex[i].val);
        for(int j=1;j<i;j++){
            temp = min(abs(vertex[j].from-vertex[i].from) , min(abs(vertex[j].to-vertex[i].to),abs(vertex[j].val-vertex[i].val)));
            road.push_back({i,j,temp});
        }
    }
    sort(road.begin(),road.end(),compare);
    int VE=0,sum=0,sma;
    for(auto K:road){
        t1 = find(K.from);
        t2 = find(K.to);
        if(t1 != t2){
            sma = t1 > t2 ? t2 : t1;
            parent[K.from] = parent[K.to] = parent[t1] = parent[t2]  =   sma;
            sum = sum + K.val;
            VE++;
            if(VE == N-1) break;
        }
    }
    printf("%d",sum);
    return 0;
}