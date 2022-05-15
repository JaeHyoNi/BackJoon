#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int now[5][5];
int temp[5][5];
int N;

void mulMatrix(bool POW){
    int tmp = 0,x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            x = 0, y = 0;
            for(int k=0;k<N;k++){
                if(POW) {tmp += (now[i][y]*now[x][j]);}
                else    {tmp += (now[x][j]*arr[i][y]);}
                printf("[%d][%d]*[%d][%d] = %d\n",i,y,x,j,tmp);
                x++; y++;
            }
            temp[i][j] = tmp%1000;
            printf("temp[%d][%d] = %d\n",i,j,temp[i][j]);
            tmp = 0;
        }
    }
    for(int i=0;i<N;i++){for(int j=0;j<N;j++){now[i][j] = temp[i][j];}}
}
void show(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<now[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}
int main(){
    long long B;
    cin>>N>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            arr[i][j] = arr[i][j]%1000;
            now[i][j] = arr[i][j];
        }
    }
    while(B!=1){
        if(B%2 == 0){mulMatrix(true); printf("MUL!\n"); show(); B/=2;}
        else{mulMatrix(false); printf("MINUS!\n");show(); B--;}
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<now[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}