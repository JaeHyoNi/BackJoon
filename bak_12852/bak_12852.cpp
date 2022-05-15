#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int main(){
    queue<int> next_num;
    int siz,N,k,ans_num=0;scanf("%d",&N);
    next_num.push(N);
    if(N==1){printf("0\n1");return 0;}
    while(arr[1]==0){
        siz = next_num.size();
        while(siz--){
            k = next_num.front();
            if(k%3==0 && arr[k/3]==0) {
                arr[k/3] = 3;
                next_num.push(k/3);
            }
            if(k%2==0 && arr[k/2]==0) {
                arr[k/2] = 2;
                next_num.push(k/2);
            }
            if(arr[k-1] == 0){
                arr[k-1] = 1;
                next_num.push(k-1);
            }
            next_num.pop();
        }
        ans_num++;
    }
    stack<int> ans;
    k=1;
    while(k!=N){
        ans.push(k);
        if(arr[k]==1) k++;
        else if(arr[k]==2) k = k*2;
        else if(arr[k]==3) k = k*3;
    }
    ans.push(N);
    printf("%d\n",ans_num);
    while(!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
    return 0;
}


// 단순 개수
// #include <bits/stdc++.h>
// using namespace std;
// queue<int> arr;
// int main(){
//     int siz,N,k,ans=0,n1,n2,n3;scanf("%d",&N);
//     arr.push(N);
//     while(1){
//         siz = arr.size();
//         while(siz--){
//             k = arr.front();
//             n1 = k%3==0 ? k/3 : 0;
//             n2 = k%2==0 ? k/2 : 0;
//             n3 = k-1;
//             if(!(n1 ^ 1 )|| !(n2 ^ 1 ) || !(n3 ^ 1 )){cout<<ans+1;return 0;}
//             if(n1) arr.push(n1);
//             if(n2) arr.push(n2);
//             if(n3) arr.push(n3);
//             arr.pop();
//         }
//         ans++;
//     }
// }