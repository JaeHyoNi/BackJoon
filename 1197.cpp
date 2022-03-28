#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

typedef struct kru{
    int from;
    int to;
    int val;
}KS;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool compare(KS &d1,KS &d2){return d1.val<d2.val;}

int main(){
    int V,E,t1,t2;
    ifstream fin;
    fin.open("test_txt/in.txt");
    fin>>V>>E;
    //scanf("%d %d",&V,&E);
    vector<KS> arr(E);
    parent.resize(V+1);
    for(int i=0;i<V+1;i++) parent[i] = i;
    for(int i=0;i<E;i++){  
        fin>>arr[i].from>>arr[i].to>>arr[i].val;
        //scanf("%d %d %d",&arr[i].from,&arr[i].to,&arr[i].val);
    }
    sort(arr.begin(),arr.end(),compare);
    int VE=0,sum=0,sma;
    for(auto K:arr){
        t1 = find(K.from);
        t2 = find(K.to);
        if(t1 != t2){
            sma = t1 > t2 ? t2 : t1;
            parent[K.from] = parent[K.to] = parent[t1] = parent[t2]  =   sma;
            sum = sum + K.val;
            VE++;
            if(VE == V-1) break;
        }
    }
    printf("%d",sum);
    return 0;
}