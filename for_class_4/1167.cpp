#include <bits/stdc++.h>
using namespace std;
#define road pair<int,int>
vector<vector<road>> arr;
bool VISIT[100001];
int longest = 0 , vertex = 0;
void find_most_far(int N,int length){
    int tmp;
    VISIT[N] = true;
    for(auto K: arr[N]){
        if(VISIT[K.first] == false){
            if(length+K.second > longest){
                longest = length+K.second;
                vertex = K.first;
            }
            find_most_far(K.first ,length+K.second);
        }
    }
    VISIT[N] = false;
}
int main(){
    int k,from,to,i,N,t; cin>>N;
    arr.resize(N+1);
    vector<int> temp,emp;
    while(N--){
        scanf("%d",&i);
        while(1){
            scanf("%d",&k);
            if(k != -1) temp.push_back(k);
            else break;
        }
        for(int j=0;j<temp.size();j++){
            arr[i].push_back({temp[j],temp[j+1]}); j++;
        }
        temp.clear();
    }
    int far;
    find_most_far(1,0);
    find_most_far(vertex,0);
    cout<<longest<<endl;
}