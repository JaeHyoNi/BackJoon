#include <bits/stdc++.h>
using namespace std;
int arr[3][3][1000],original[3][1000];


int main(){
    int N,answer;   cin>>N;
    for(int i=0;i<N;i++){cin>>original[0][i]>>original[1][i]>>original[2][i];}
    for(int i=0;i<3;i++){
        arr[i][0][0] = arr[i][1][0] = arr[i][2][0] = 900000000;
    } 
    for(int i=0;i<3;i++){
        arr[i][i][0] = original[i][0];
    }
    for(int i=0;i<3;i++){
        for(int j=1;j<N;j++){
            arr[i][0][j] = min(arr[i][1][j-1] , arr[i][2][j-1]) + original[0][j];
            arr[i][1][j] = min(arr[i][0][j-1] , arr[i][2][j-1]) + original[1][j];
            arr[i][2][j] = min(arr[i][0][j-1] , arr[i][1][j-1]) + original[2][j];
        }
    }
    for(int i=0;i<3;i++){
        cout<<endl<<endl;
        for(int j=0;j<N;j++){
            cout<<arr[i][0][j]<<" "<<arr[i][1][j]<<" "<<arr[i][2][j]<<"\n";
        }
    }
    answer = min(arr[0][1][N-1] , arr[0][2][N-1]);
    answer = min(min(arr[1][0][N-1] , arr[1][2][N-1]) , answer);
    answer = min(min(arr[2][0][N-1] , arr[2][1][N-1]) , answer);
    cout<<answer<<"\n";
}