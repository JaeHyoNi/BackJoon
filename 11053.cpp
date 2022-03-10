#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void){
    int N,tmp;
    cin>>N;

    vector<int> arr;
    vector<int> arr2(N,1);

    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                arr2[i] = max(arr2[i] , arr2[j]+1);
            }
        }
    }
    cout<<*max_element(arr2.begin(),arr2.end());


}
