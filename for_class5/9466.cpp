#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,N,tmp; cin>>T;
    while(T--){
        int answer = 0;
        scanf("%d",&N);
        vector<int> arr(N+1);
        vector<bool> VISIT(N+1,false);
        for(int i=1;i<=N;i++){
            scanf("%d",&arr[i]);
            if(arr[i] == i){ VISIT[i] = true;}
        }
        for(int i=1;i<=N;i++){
            bool find = false;
            if(VISIT[i]) continue;
            tmp = i;
            map<int,int> temp;
            while(arr[tmp] != tmp && temp[tmp] == 0){
                if(VISIT[tmp]){break;}
                temp[tmp]++;
                tmp = arr[tmp];
                if(tmp == i){
                    i = tmp;
                    find = true;
                    for(auto K:temp){if(K.second > 0){VISIT[K.first] = true;}}
                    find = true;
                    break;
                }
            }
            if(find) continue;
            int tmp2 = i;
            while(tmp2 != tmp){
                answer++;
                VISIT[tmp2] = true;
                tmp2 = arr[tmp2];
            }
        }
        cout<<answer<<endl;
    }
}

