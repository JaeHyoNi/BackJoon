#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,L;
    cin>>T;
    string str;
    while(T--){
        cin>>L>>str;
        for(auto K:str){
            for(int i=0;i<L;i++){
                cout<<K;
            }
        }
        cout<<endl;
    }
}