#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,siz; cin>>N; N--;
    string str,temp; cin>>str; siz = str.size();
    while(N--){
        cin>>temp;
        for(int i=0;i<siz;i++){if(temp[i] != str[i]){str[i] = '?';}}
    }
    cout<<str;
}