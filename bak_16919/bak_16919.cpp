#include <bits/stdc++.h>
using namespace std;
vector<int> lps;
string str,str1,str2;


void make_lps(){
    int len = 0,i = len+1,siz=lps.size();
    while(i<siz){
        if(str2[len] == str2[i])    lps[i++] = ++len;
        else{
            if(len!=0) len = lps[len-1];
            else{lps[i++] = 0;}
        }
    }
}

int main(){
    cin>>str>>str2;
    int siz = str.size();
    for(int i=0;i<siz;i++){
        if(isalpha(str[i])) str1.push_back(str[i]);
    }
    lps.resize(str2.size());
    make_lps();
    int iter = 0,i=0;
    while(iter < str1.size()){
        if(str1[iter] == str2[i]){
            iter++;i++;
        }
        else{
            if(i!=0){
                i = lps[i-1];
            }
            else{
                iter++;
            }
        }
        if(i == str2.size()){
            cout<<"1";
            return 0;
        }
    }
    cout<<"0";
    return 0;
}
