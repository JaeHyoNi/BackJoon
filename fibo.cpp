#include <iostream>
#include <vector>
using namespace std;
vector<int> fibo;
int main(void){
    int N;
    cin>>N;
    fibo.push_back(0);fibo.push_back(1);
    int k=2;
    if(N==1 || N==2) {cout<<fibo[N-1];}
    else{
        while(N+1!=k){
            fibo.push_back(fibo[k-1]+fibo[k-2]);
            k++;
        }
    }
    cout<<fibo[k-1];
}
