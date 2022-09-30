#include <bits/stdc++.h>
using namespace std;


int siz;
bool can(long long &now,int &a, int &b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t){
    long long power = 0,time;
    int gold = 0,  silver = 0,temp,temp2;
    for(int i=0; i<siz; i++){
        time = now/t[i];
        if(now%t[i] >= t[i]/2) time++;
        temp = g[i]+s[i];
        temp2 = time*w[i];
        power += min(temp,temp2);
        gold += min(g[i],temp2);
        silver += min(s[i],temp2);
        if(power >= (a+b) && gold >= a && silver >= b){
            cout<<"\na+b : "<<a+b<<" power : "<<power << " gold : "<<gold<<" silver : "<<silver<<"\n";
            return true;
            }
    }
    cout<<"\na+b : "<<a+b<<" power : "<<power << " gold : "<<gold<<" silver : "<<silver<<"\n";
    return false;
}


struct truck{int gold;int silver;int time;};
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    for(auto &K:t){K *= 2;}
    siz = g.size();
    
    long long st = 0;
    long long en = 10000000;
    long long answer = en;
    while(st <= en){
        auto m = (st+en)/2;
        cout<<"check "<<m<<" : " << can(m,a,b,g,s,w,t)<<endl;
        if(can(m, a, b, g, s, w, t)){
            answer = min(answer,m);
            en = m-1;
        }
        else st = m + 1;
    }
    return answer;
}

int main(){
    cout<<solution(90,500,{70,70,0},{0,0,500},{100,100,2},{4,8,1});
}