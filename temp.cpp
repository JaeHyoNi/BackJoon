#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

typedef struct kru{
    int x;int y;int z;
}point;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool compare(point &d1,point &d2){
    return d1.x<d2.x;
}

int main(){
    int N,t1,t2,temp;
    ifstream fin;
    fin.open("test_txt/in.txt");
    fin>>N;
    vector<point> road;
    vector<point> vertex(N+1);
    parent.resize(N+1);
    for(int i=1;i<N+1;i++) parent[i] = i;
    for(int i=1;i<N+1;i++){  
        fin>>vertex[i].x>>vertex[i].y>>vertex[i].z;
    }
    sort(vertex.begin(),vertex.end(),compare);
    for(auto K:vertex){
        printf("[%d,%d,%d]\n",K.x,K.y,K.z);
    }    
    return 0;
}