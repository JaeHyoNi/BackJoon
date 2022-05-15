#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int siz1 = a.size(),siz2 = b.size();
    while(siz1<siz2){
        if(b[siz2-1] == 'A'){
            b.pop_back();
            siz2--;
        }
        else{
            b.pop_back();
            siz2--;
            reverse(b.begin(),b.end());
        }
    }
    if(a==b) cout<<"1";
    else cout<<"0";
}