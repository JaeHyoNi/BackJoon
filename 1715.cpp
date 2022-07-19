#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ANS=0,n1,n2,temp; cin>>N;
    priority_queue<int, vector<int> , greater<>> wait;; 
    for(int i=0;i<N;i++){cin>>temp; wait.push(temp);}
    for(int i=0;i<N-1;i++){
        n1 = wait.top(); wait.pop(); 
        n2 = wait.top(); wait.pop();
        ANS+=(n1+n2); wait.push(n1+n2);
    }
    cout<<ANS;
}