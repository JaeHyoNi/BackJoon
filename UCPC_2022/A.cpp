#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    string answer;
    while(N!=0){answer += "long "; N-=4;}
    answer+="int";
    cout<<answer;
}