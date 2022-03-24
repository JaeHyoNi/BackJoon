#include <bits/stdc++.h>

using namespace std;

vector<long long> ans;
void solution(vector<long long> &prices){
    auto iter = prices.end();
    iter = iter - 1;
    int max_price = *iter;
    long long sum = 0;
    stack<string> ans;
    do{
        iter = iter - 1;
        if((*iter) < max_price){
            ans.push("BUY");
            sum = sum + max_price - *iter;
        }
        else if(*iter > max_price){
            ans.push("SELL");
            max_price = *iter;
        }
        else{
            ans.push("NO");
        }
    }while(iter != prices.begin());
    while(!ans.empty()){
        cout.width(8);
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
    cout<<sum<<endl;
}




int main(void){
    int N,M,tmp;
    cin>>N;
    vector<long long> prices,temp;
    for(int i=0;i<N;i++){
        cin>>M;
        for(long long j=0;j<M;j++){
            cin>>tmp;
            prices.push_back(tmp);  
        }
        for(auto K:prices){
            printf("%8d ",K);
        }cout<<endl;
        solution(prices);
        prices = temp;
    }
    for(auto K: ans){
        cout<<K<<endl;
    }
}
