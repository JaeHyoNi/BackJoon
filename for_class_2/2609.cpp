#include <bits/stdc++.h>
using namespace std;
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
    int A,B,T;
    cin>>A>>B;
    T=gcd(A,B);
    cout<<T<<endl;
    if(A>B) swap(A,B);
    cout<<B/T * A;
    
}