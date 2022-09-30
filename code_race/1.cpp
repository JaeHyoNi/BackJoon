#include <bits/stdc++.h>
using namespace std;

vector<int> my;
vector<vector<int>> other;

int main(){
    int N,M;
    cin>>N>>M;
    my.resize(M);
    other.resize(N-1,vector<int>(M));
    for(int i=0;i<M;i++){
        scanf("%d",&my[i]);
    }
    N--;
    int flag = N/2 + (N%2);
    int not_good = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&other[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        int s = 0;
        for(int j=0;j<M;j++){
            s += abs(other[i][j]-my[j]);
        }
        if(s > 2000){
            not_good ++;
        }
        if(not_good >= flag){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}