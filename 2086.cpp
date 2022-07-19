#include <bits/stdc++.h>
using namespace std;
const int divide = 1e9;

void power(long long N[][2]){
    long long temp[2][2]={{0,0},{0,0}};
    temp[0][0] = N[0][0]*N[0][0] + N[0][1]*N[1][0];
    temp[0][1] = N[0][0]*N[0][1] + N[0][1]*N[1][1];
    temp[1][0] = N[1][0]*N[0][0] + N[1][1]*N[1][0];
    temp[1][1] = N[1][0]*N[0][1] + N[1][1]*N[1][1];
    for(int i=0;i<2;i++){for(int j=0;j<2;j++){N[i][j] = temp[i][j]%divide;}}
}
void NEXT(long long N[][2]){
    long long temp[2][2] = {{0,0},{0,0}};
    temp[0][0] = N[0][0]+N[0][1];
    temp[0][1] = temp[1][0] = N[0][0];
    temp[1][1] = N[1][0];
    for(int i=0;i<2;i++){for(int j=0;j<2;j++){N[i][j] = temp[i][j]%divide;}}
}
int main(){
    long long START[2][2] = {{1,1},{1,0}};
    long long END[2][2] = {{1,1},{1,0}};
    long long N,M; cin>>N>>M;   M += 2; N+=1;
    stack<bool> cal1,cal2;
    while(M>1){
        if(M%2==0) {cal1.push(true);M/=2;}
        else {cal1.push(false);M-=1;}
    }
    while(N>1){
        if(N%2==0) {cal2.push(true); N/=2;}
        else {cal2.push(false);N-=1;}
    }
    while(!cal2.empty()){
        if(cal2.top()) {power(START);}
        else{NEXT(START);}
        cal2.pop();
    }
    while(!cal1.empty()){
        if(cal1.top()) {power(END);}
        else{NEXT(END);}
        cal1.pop();
    }
    long long answer = END[1][0] - START[1][0];
    if(answer < 0) answer += divide;
    cout<<answer;
}