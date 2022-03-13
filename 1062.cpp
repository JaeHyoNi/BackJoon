#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<char,bool> dic;
vector<string> str;
vector<char> al;
bool visit[26] = {1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0}; // a c n t i
int max_num;
bool is;

void check(){
    for(int i=0;i<26;i++){
        if(visit[i] == 1){
            cout<<(char)(i+'a')<<" ";
        }
    }cout<<endl;
    int num=0;
    for(auto k:str){
        is = true;
        for(auto j:k){
            if(visit[j-'a'] == 0){
                is = false;
                break;
            }
        }
        if(is) {
            num++;
            cout<<"success! : "<<k<<endl;
        }
        else{
            cout<<"fail : "<<k<<endl;
        }
    }
    if(num>max_num) max_num = num;
}




int main(void){
    int N,K;
    string tmp,tmp2;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>tmp;
        tmp = tmp.substr(4,tmp.size()-8);
        for(auto k:tmp){
            is = true;
            if(!visit[k-'a'])   {
                tmp2.push_back(k);
                dic[k] = 1;
                is = false;
            }
        }
        if(is) {max_num++;cout<<"max++"<<endl;}
        if(!tmp2.empty()) str.push_back(tmp2);
        tmp2.clear();
    }
    if(K<5){cout<<0<<endl;return 0;}
    K -= 5;
    for(auto k:dic){
        al.push_back(k.first);
    }
    sort(al.begin(),al.end());
    for(auto k:str) cout<<k<<endl;

    for(auto k:al) cout<<k<<" ";
    cout<<endl;
    int siz = al.size();
    vector<bool> edu(al.size()-K);
    for(int i=0;i<K;i++) edu.push_back(1);
    do{
        for(int i=0;i<siz;i++){ if(edu[i] == 1){visit[al[i]-'a'] = 1;}}
        check();
        for(int i=0;i<siz;i++){ if(edu[i] == 1){visit[al[i]-'a'] = 0;}}
    }while(next_permutation(edu.begin(),edu.end()));
    cout<<"max : "<<max_num<<endl;
    return 0;

}
