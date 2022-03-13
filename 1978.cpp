#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
 
 
bool isPrime(int num){
    if(num<2) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i == 0) return false;
    }
    return true;
}

int main(void){
    int N,t,sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>t;
        if(isPrime(t)) sum++; 
    }
    cout<<sum<<endl;
}
