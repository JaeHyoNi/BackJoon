#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long A,B,siz,tmp1,tmp2,ans = 0;
    bool is = false;
    cin>>A>>B;
    queue<long long> wait;
    wait.push(A);
    while(1){
        siz = wait.size();
        ans = ans + 1;
        for(int i=0;i<siz;i++){
            tmp1 = wait.front() * 2;
            tmp2 = wait.front() * 10 + 1;
            if(tmp1 == B || tmp2 == B) {
                is = true;
                break;
            }
            if(tmp1 < B) wait.push(tmp1);
            if(tmp2 < B) wait.push(tmp2);
            wait.pop();  
        }
        if(is) break;
        if(wait.empty()){
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans+1;
    return 0;
}
