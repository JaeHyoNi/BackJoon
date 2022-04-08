#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char,int> temp;
    char a;int MAX=0;
    string str;
    cin>>str;
    for(auto K:str){
        temp[tolower(K)]++;
        if(temp[tolower(K)] > MAX) {
            a = toupper(K);
            MAX = temp[tolower(K)];
        }

    }
    int i = 1;
    for(auto K:temp){
        if(K.second == MAX){i--;}
    }
    if(i<0) cout<<"?";
    else cout<<a;
    return 0;
}