#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> tree,temp;
    int MIN,MAX,N,tmp,num;cin>>N;
    char task;
    while(N--){
        cin>>num;
        while(num--){
            cin>>task>>tmp;
            if(task == 'I'){tree[tmp] += 1;}
            else{
                if(tmp == 1){
                    if(!tree.empty()){
                        tmp = (--tree.end())->first;
                        tree[tmp]-=1;
                        if(tree[tmp] == 0){
                            tree.erase(tmp);
                        }
                    }
                }
                else if(tmp == -1){
                    if(!tree.empty()){
                        tmp = tree.begin()->first;
                        tree[tmp]-=1;
                        if(tree[tmp]==0){
                            tree.erase(tmp);
                        }
                    }
                }
            }
        }
        tmp = tree.size();
        if(tree.empty()){cout<<"EMPTY"<<endl;continue;}
        MIN = tree.begin()->first;
        MAX = (--tree.end())->first;
        cout<<MAX<<" "<<MIN<<endl;
        tree = temp;
    }
    return 0;
}