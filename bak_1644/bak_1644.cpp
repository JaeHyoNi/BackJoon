#include <bits/stdc++.h>
using namespace std;
bool arr[5000000];
int main(){
    int N,k;
    vector<int> prime;
    scanf("%d",&N);
    if(N==1) {cout<<"0";return 0;}
    for(int i=2;i<=N;i++){
        if(arr[i] == 0){
            prime.push_back(i);
            k = 2;
            while(i*k<=N){
                arr[i*k] = 1;
                k = k + 1;
            } 
        }
    }
    int ans=0,iter1=0,iter2=0,sum=prime[0],siz = prime.size();
    while(1){
        if(iter1 == siz-1) {
            if(sum==N)
                ans++;
            break;
        }
        if(sum == N){
            ans++;
            iter2++;
            sum+=prime[iter2];
        }
        if(sum < N){
            while(sum<N){
                iter2 = iter2 + 1;
                sum = sum + prime[iter2];
            }
        }
        if(sum > N){
            while(iter1 <=iter2 && sum>N){
                sum = sum - prime[iter1];
                iter1 = iter1 + 1;
            }
            if(sum>N){
                iter1++;iter2++;
                sum = prime[iter1];
            }
        }
    }
    cout<<ans;
}