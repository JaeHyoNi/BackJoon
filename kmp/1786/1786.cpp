#include <bits/stdc++.h>
using namespace std;

string T,P;
vector<int> lps;
vector<int> ans;
void make_lps(){
    int i = 0,j = 1,siz = P.size();
    while(j<siz){
        if(P[i] == P[j]){lps[j++] = ++i;}
        else{if(i!=0) i=lps[i-1];
             else {lps[j] = 0;j++;}
        }
    }
}

void match(){
    int sizT = T.size(),sizP=P.size();
    int i=0,j=0;
    while(i<sizT){
        if(j==sizP){ans.push_back(i-sizP+1);j = lps[j-1];}
        if(T[i] == P[j]){i++;j++;}
        else{
            if(j!=0){
                j= lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==sizP){ans.push_back(i-sizP+1);}
}

int main(){
    ifstream fin;
    // fin.open("../../test_txt/in.txt");
    getline(cin,T);
    getline(cin,P);
    lps.resize(P.size(),0);
    make_lps();
    match();
    cout<<ans.size()<<endl;
    for(auto K:ans){cout<<K<<" ";}
    return 0;
}