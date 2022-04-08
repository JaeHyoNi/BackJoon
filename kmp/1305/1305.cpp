#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> lps;
int siz;
void make_lps(){
    int i = 0,j = 1;
    siz = str.size();
    while(j<siz){
        if(str[i] == str[j]){lps[j++] = ++i;}
        else{if(i!=0) i=lps[i-1];
             else {lps[j] = 0;j++;}
        }
    }
    cout<<endl;
}

int main(){
    int N;cin>>N;
    cin>>str;
    lps.resize(str.size());
    make_lps();
    int ans = siz;
    ans -=lps[siz-1];
    cout<<ans;
    return 0; 
}