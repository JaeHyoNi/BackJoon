#include <bits/stdc++.h>
using namespace std;
string str1,str2;
vector<int> lps,prime;
int is[1000001];

void make_lps(){
    int i = 0,j = 1,siz = str2.size();
    lps.resize(siz,0);
    while(j<siz){
        if(str2[i] == str2[j]){lps[j++] = ++i;}
        else{
            if(i != 0){i = lps[i-1];}
            else{j++;}
        }
    }
}
int gcd(int a,int b){
    int tmp,n;
    if(a<b){swap(a,b);}
    while(b!=0){
        n=a%b;
        a=b;
        b=n;
    }
    return a;
}
int main(){
    int N;cin>>N;
    char temp;
    for(int i=0;i<N;i++){cin>>temp;str1.push_back(temp);}
    str1 = str1+str1;
    for(int i=0;i<N;i++){cin>>temp;str2.push_back(temp);}
    make_lps();
    int i = 0,j=0,div=0,siz=0;
    vector<int> ans;
    while(i<2*N){
        if(j == N){
            if(i-N <= N-1){ans.push_back(i-N);}
            j = lps[j-1];
        }
        if(str1[i] == str2[j]){i++;j++;}
        else{
            if(j!=0){j = lps[j-1];}
            else i++;
        }
    }
    siz = ans.size();
    div = gcd(siz,N);
    N /=div; siz/=div;
    cout<<siz<<"/"<<N<<endl;
    return 0;
}