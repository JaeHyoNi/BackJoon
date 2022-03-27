#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

typedef struct {int x; int y; int z;} point;
vector<pair<int,int>> x,y,z;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool compare(point &d1,point &d2){
    return d1.z<d2.z;
}

int main(){
    int N,t1,t2,temp;
    ifstream fin;
    fin.open("test_txt/in.txt");
    scanf("%d",&N);
    vector<point> road;
    parent.resize(N+1);
    x.resize(N),y.resize(N),z.resize(N);
    for(int i=0;i<N;i++) parent[i] = i;
    for(int i=0;i<N;i++){  
        scanf("%d %d %d",&x[i].first,&y[i].first,&z[i].first);
        x[i].second = y[i].second = z[i].second = i;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    for(int i=0;i<N-1;i++){
        road.push_back({x[i].second ,x[i+1].second ,abs(x[i+1].first-x[i].first)});
        road.push_back({y[i].second ,y[i+1].second ,abs(y[i+1].first-y[i].first)});
        road.push_back({z[i].second ,z[i+1].second ,abs(z[i+1].first-z[i].first)});
    }
    sort(road.begin(),road.end(),compare);
    int VE = 0;
    int sum = 0;
    for(auto K:road){
        t1 = find(K.x); t2 = find(K.y);
        temp = t1>t2 ? t2:t1;
        if(t1 != t2){
            sum = sum + K.z;
            VE = VE + 1;
            parent[t1] = parent[t2] = parent[K.x] = parent[K.y] = temp;
            if(VE == N-1) break;
        }
    }
    printf("%d",sum);
    return 0;
}