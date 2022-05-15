#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a,int b){
        return abs(a) == abs(b) ? a>b : abs(a) > abs(b);
    }
};

int main(){
    int N,tmp;  cin>>N;
    priority_queue<int, vector<int> , cmp> tree;
    while(N--){
        scanf("%d",&tmp);
        if(tmp == 0){
            if(tree.empty())   printf("0\n");
            else {printf("%d\n",tree.top()); tree.pop();}
        }
        else{
            tree.push(tmp);
        }
    }
}