#include <bits/stdc++.h>
using namespace std;

int solution(int a,int b){
    int answer = 0,t1,t2,carry=0;
    while(a != 0){
        t1 = a%10 , t2 = b%10;
        a/=10,b/=10;
        if(t1+t2+carry>9){carry = 1; answer+=1;}
        else{carry = 0;}
    }
    return answer;
}

int main(){
    int a,b; 
    while(1){
        cin>>a>>b;  if(a<b) swap(a,b);
        if(a==0 && b==0){break;}
        cout<<solution(a,b)<<"\n";
    }
}