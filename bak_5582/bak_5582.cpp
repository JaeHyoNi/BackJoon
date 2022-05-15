#include <bits/stdc++.h>
using namespace std;
int arr[4001][4001];
int main(){
    int MAX=0;
    string a,b;
    cin>>a>>b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
                if(arr[i][j]>MAX)
                    MAX = arr[i][j];
            }
        }
    }
    cout<<MAX;
}