#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[100001];
struct road{int from;int to;int val;};

int find_mother(int num){
    if( arr[num] == num) return num;
    else{return arr[num] = find_mother(arr[num]);}
}

void uni(int a,int b){
    a = find_mother(a);
    b = find_mother(b);
    if( a!= b){
        if(a >= b){arr[a] = b;}
        else{arr[b] = a;}
    }
}

int main(){
    cin>>N>>M;
    vector<road> roads;
    roads.resize(M);
    for(int i=1;i<=N;i++){arr[i] = i;}
    for(int i=0;i<M;i++){
        cin>>roads[i].from>>roads[i].to>>roads[i].val;
        if(roads[i].from > roads[i].to) swap(roads[i].from,roads[i].to);
    }
    sort(roads.begin(),roads.end(), [](road &a, road&b){
            return a.val < b.val;
    });
    int answer = 0;
    int siz = 0;
    for(auto K:roads){
        if(find_mother(K.from) != find_mother(K.to)){
            uni(K.from,K.to);
            answer += K.val;
            siz ++;
        }
        if(siz == N-2) break;
    }
    cout<<answer<<"\n";
}