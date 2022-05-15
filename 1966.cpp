#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,siz,ans,target,local_max;cin>>N;
    vector<int> pri;
    priority_queue<int> temp,emp;

    while(N--){
        ans = 0;
        cin>>siz>>target;
        pri.resize(siz);
        temp = emp;
        for(int i=0;i<siz;i++){
            cin>>pri[i];
            temp.push(pri[i]);
        }
        int iter = 0;
        while(1){
            local_max = temp.top(); temp.pop();
            while(pri[iter%siz] != local_max){
                iter++;
            }
            pri[iter%siz] = -1;
            ans += 1;
            if(iter%siz == target){
                cout<<ans<<endl;
                break;
            }
        }
    }
}