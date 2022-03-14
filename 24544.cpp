#include<iostream>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;

int main(){
    int N,temp,sum=0;
    bool is;
    cin>>N;
    vector<int> interest;
    for(int i=0;i<N;i++){
        cin>>temp;
        interest.push_back(temp);
    }
    for(int i=0;i<N;i++){
        cin>>is;
        if(!is) sum = sum + interest[i];
    }
    cout<<accumulate(interest.begin(),interest.end(),0)<<endl;
    cout<<sum<<endl;
    return 0;
}
