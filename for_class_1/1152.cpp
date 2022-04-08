#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int ans = 1;
    getline(cin,str);
    for(auto K:str){
        if(K==' '){
            ans++;
        }
    }
    if(str[0] == ' ') ans--;
    if(str[str.size()-1] == ' ') ans --;
    cout<<ans;
}