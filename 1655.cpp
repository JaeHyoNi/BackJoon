#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,temp,siz = 1; cin>>N;
    multiset<int> list;
    scanf("%d",&temp);
    list.insert(temp);
    auto iter = list.find(temp);
    cout<<temp<<endl;
    for(int i=1;i<N;i++){
        scanf("%d",&temp);
        list.insert(temp);
        siz ++;
        if(siz%2!=0) {if(temp >= *iter) {iter++;}}
        else {if(temp < *iter){iter--;}}
        printf("%d\n",*iter);
    }
}