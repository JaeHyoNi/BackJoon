#include <bits/stdc++.h>
using namespace std;

int main(){
    string p;
    scanf("%s",p);
    cout<<p<<endl;
    
    vector<int> temp(4);
    scanf("[%d,%d,%d,%d]",&temp[0],&temp[1],&temp[2],&temp[3]);
    for(auto K:temp){
        cout<<K<<" ";
    }
}