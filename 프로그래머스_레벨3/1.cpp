#include <bits/stdc++.h>
using namespace std;




int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> arr(n+1,vector<int>(n+1));
    for(auto K: results){
        arr[K[0]][K[1]] = 1;
        arr[K[1]][K[0]] = -1;
    }
    for(int i=1;i<=n;i++){arr[i][i] = -1;}
    for(int k=1; k<=n; k++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(arr[i][k] == 1 && arr[k][j] == 1){
                    arr[i][j] = 1;
                    arr[j][i] = -1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool is = true;
        for(int j=1;j<=n;j++){
            if(arr[i][j] == 0){
                is = false;
                break;
            }
        }
        if(is){
            answer++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout.width(3);
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return answer;
}
int main(){
    cout<<solution(5,{{4,3},{4,2},{3,2},{1,2},{2,5}});
}