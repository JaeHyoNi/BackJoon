#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N,tmp;
    cin>>N;
    vector<int> temp,temp2;
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++){
            cin>>tmp;
            temp.push_back(tmp);
        }
        sort(temp.begin(),temp.end());
        cout<<temp[7]<<endl;
        temp = temp2;
    }
}
