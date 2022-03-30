#include <bits/stdc++.h>
#define MAX 21000000
using namespace std;

int arr[101][101];

int main(){
    int n,m,from,to,price;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = MAX;
            if(i==j) arr[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&from,&to,&price);
        arr[from][to] = min(arr[from][to],price);
    }
    for(int mid=1;mid<=n;mid++){
        for(from=1;from<=n;from++){
            for(to=1;to<=n;to++){
                if(arr[from][mid]!= 0 && 0!= arr[mid][to]){
                    arr[from][to] = min(arr[from][to] , arr[from][mid] + arr[mid][to]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] == MAX){ cout<<"0 ";}
            else cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}