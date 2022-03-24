#include <bits/stdc++.h>
using namespace std;

int main(){
    long long flag_num=0,tmp;
    string str;
    vector<long long> arr;
    int N;
    cin>>N>>str;
    char flag = str[0];
    for(int i=0;i<N;i++){
        cin>>tmp;
        if( flag != str[i] ){
            arr.push_back(flag_num);
            flag_num = tmp;
            flag = str[i];
        }
        else{
            if(tmp > flag_num){
                flag_num = tmp;
            }
        }
    }
    if(N == 1) {
        cout<<"0";
        return 0;
    }
    if(arr.size() == 0) {
        cout<<"0";
        return 0;
    }
    arr.erase(arr.begin());
    sort(arr.begin(),arr.end(),greater<long long>());
    int siz = arr.size();

    long long ans = 0;
    siz = siz / 2 + siz % 2;
    for(int i=0;i<siz;i++){
        ans = ans + arr[i];
    }
    cout<<ans;
    return 0;
}
