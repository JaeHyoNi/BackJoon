#include <bits/stdc++.h>
using namespace std;
int arr[101][101][101];
int main(){
    int MAX = 0;
    string a,b,c;
    cin>>a>>b>>c;
    int s1 = a.size(),s2 = b.size(),s3 = c.size();
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                if(a[i=1] == b[j-1] && b[j-1]== c[k-1]){
                    arr[i][j][k] = arr[i-1][j-1][k-1] + 1;
                    if(arr[i][j][k] > MAX){
                        MAX = arr[i][j][k];
                    }
                }
                else {
                   arr[i][j][k] = max(arr[i-1][j][k],max(arr[i][j-1][k],arr[i][j][k-1]));
                }
            }
        }
    }
    cout<<MAX;
}