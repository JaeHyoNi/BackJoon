#include <bits/stdc++.h>
using namespace std;
//(100+1+ | 01)+

bool check(string &str){
    int i = 0;
    int siz = str.size();
    bool pre = false;
    while(i < siz){
        if(i+2 < siz && str[i] == '1' && str[i+1] == '0' && str[i+2] == '0'){
            i+=3;
            while(str[i]!='1') {
                if(i>=siz){return false;}
                i+=1;
            }
            i+=1;
            pre = true;
        }
        else if(pre && str[i] == '1'){i++;}
        else if(i+1<siz && str[i] == '0' && str[i+1] == '1'){i += 2;pre = false;}
        else{return false;}
    }
    return true;
}

int main(){
    int T;
    string str;
    cin>>T;
    while(T--){
        cin>>str;
        if(check(str)){cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
    return 0;
}