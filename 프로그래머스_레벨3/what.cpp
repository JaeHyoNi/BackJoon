#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int div = s/n;
    int offset = s%n;
    for(int i=0;i<n;i++){
        answer.emplace_back(div);
    }
   for(int i=n-offset;i<n;i++){answer[i]++;}
    

    //가장 큰 수를 나누면 된다
    // priority_queue<int> waiting;
    // waiting.push(s);
    // int siz = 1;
    // while(siz != n){
    //     int temp = waiting.top();
    //     waiting.push(temp/2);
    //     if(temp/2 == 0){
    //         answer.emplace_back(-1);
    //         return answer;
    //     }
    //     waiting.push(temp/2 + temp%2);
    //     waiting.pop();
    //     siz++;
    // }
    // while(!waiting.empty()){
    //     answer.emplace_back(waiting.top());
    //     waiting.pop();
    // }
    // reverse(answer.begin(),answer.end());
    return answer;
}

int main(){
    int n,s; cin>>n>>s;
    vector<int> arr = solution(n,s);
    for(auto K:arr){
        cout<<K<<" ";
    }
}