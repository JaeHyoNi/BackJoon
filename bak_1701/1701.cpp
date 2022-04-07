#include <bits/stdc++.h>
using namespace std;
vector<int> lps;
string str;
void make_lps(){
    int siz = str.size(),now_siz=str.size();
    int len,test,i,MAX = 0;
    for(int i=1;i<siz;i++){
        lps.clear();
        lps.resize(now_siz,0);
        len = 0,test = 1;
        while(test<now_siz){
            if(str[len] == str[test]){
                lps[test++] = ++len;
                if(len>MAX) MAX = len;
            }
            else{
                if(len!=0){len = lps[len-1];}
                else{test++;}
            }
        }
        str = str.substr(1);
        now_siz--;
    }
    if(MAX == 1){cout<<"0";return;}
    else cout<<MAX;
}


int main(){
    //ifstream fin;
    //fin.open("../test_txt/in.txt");
    cin>>str;
    lps.resize(str.size(),0);
    make_lps();
    return 0;
}