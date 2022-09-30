#include <bits/stdc++.h>
using namespace std;
int arr[500001];

int find_mother(int N){
    if(arr[N] == N){return N;}
    else{return arr[N] = find_mother(arr[N]);}
}

void update(int a,int b){
    a = find_mother(a);
    b = find_mother(b);
    if( a!= b){
        if(a >= b){arr[a] = b;}
        else{arr[b] = a;}
    }
}
       
int main(){
    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++){arr[i] = i;}
    int from,to,ans,f,t;
    bool is = false;
    for(int i=0;i<M;i++){
        cin>>from>>to;
        if(!is){
            if(from > to){swap(from,to);}
            f = find_mother(from);
            t = find_mother(to);
            if(f == t){
                ans = i+1;
                is = true;
            }
            else{update(from,to);}
        }
    }
    if(is) cout<<ans<<"\n";
    else cout<<"0\n";
}