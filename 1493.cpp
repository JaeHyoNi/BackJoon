#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cubes;
int answer = 0;
int val[20];

bool solution(int l,int w,int h){
    int K = min(l,min(w,h));
    for(auto &K:cubes){
        if(K.second == 0) continue;
        int N = val[K.first];
        if(l==0 || w==0 || h==0) return true;
        if(l>=N && w>=N && h>=N){
            K.second--;
            if(!solution(l-N,N,N)){K.second++; continue;};
            if(!solution(l,w-N,N)){K.second++; continue;}
            if(!solution(l,w,h-N)){K.second++; continue;}
            answer++;
            return true;
        }
    }
    return false;
}

int main(){
    for(int i=0;i<20;i++){val[i] = pow(2,i);}
    int L,W,H,N,t1,t2; cin>>L>>W>>H;
    cin>> N;
    for(int i=0;i<N;i++){cin>>t1>>t2;  cubes.push_back({t1,t2}); }
    reverse(cubes.begin(),cubes.end());
    //int answer = solution(L,W,H);
    if(solution(L,W,H))   cout<<answer;
    else cout<<"-1";
}