#include <bits/stdc++.h>
using namespace std;
int arr[505][505]; 
#define update(x,y) (x)>(y) ? (x):(y)
#define update3(a,b,c) update(a,update(b,c))
#define update7(a,b,c,d,e,f,g) update(a,update(b,update(c,update(d,update(e,update(f,g))))))
int main(){
    ifstream fin;
    fin.open("in.txt");
    int N,M,i,j,sum; fin>>N>>M;
    for(int i=0;i<N;i++){for(int j=0;j<M;j++){fin>>arr[i+1][j+1];}}
    int MAX = 0;
    //길쭉한거
    for(j=1; j<=M;j++){
        sum = arr[1][j]+arr[2][j]+arr[3][j]+arr[4][j];  MAX = update(MAX,sum);
        for(int i=5;i<=N;i++){
            sum = sum + arr[i][j] - arr[i-4][j];    MAX = update(MAX,sum);
        }
    }
    for(int i=1;i<=N;i++){
        sum = arr[i][1]+arr[i][2]+arr[i][3]+arr[i][4];  MAX = update(MAX,sum);
        for(int j=5;j<=M;j++){
            sum = sum + arr[i][j] - arr[i][j-4];    MAX = update(MAX,sum);
        }
    }
    //사각형 계산
    for(i=1;i<=N-1;i++){
        sum = arr[i][1]+arr[i][2]+arr[i+1][1]+arr[i+1][2];
        MAX = update(MAX,sum);
        for(j=3;j<=M;j++){
            sum = sum + arr[i][j] + arr[i+1][j] - arr[i][j-2] - arr[i+1][j-2]; MAX = update(MAX,sum);
        }
    }
    //3,4,5번 도형 세개씩 끊어서 계산
    //가로
    for(int i=1;i<=N;i++){
        sum = arr[i][1]+arr[i][2]+arr[i][3]; 
        MAX = update7(MAX,sum+arr[i+1][1],sum+arr[i+1][2],sum+arr[i+1][3],sum+arr[i-1][1],sum+arr[i-1][2],sum+arr[i-1][3]); 
        for(int j=4;j<=M;j++){
            sum = sum + arr[i][j] - arr[i][j-3];    
            MAX = update7(MAX,sum+arr[i+1][j],sum+arr[i+1][j-1],sum+arr[i+1][j-2],sum+arr[i-1][j],sum+arr[i-1][j-1],sum+arr[i-1][j-2]);
        }
    }
    //세로
    for(int j=1;j<=M;j++){
        sum = arr[1][j]+arr[2][j]+arr[3][j];
        MAX = update7(MAX,sum + arr[1][j+1],sum+arr[2][j+1],sum+arr[3][j+1],sum + arr[1][j-1],sum+arr[2][j-1],sum+arr[3][j+1]);
        for(i=4;i<=N;i++){
            sum = sum + arr[i][j]-arr[i-3][j];
            MAX = update7(MAX,sum + arr[i][j+1],sum+arr[i-1][j+1],sum+arr[i-2][j+1],sum + arr[i][j-1],sum+arr[i-1][j-1],sum+arr[i-2][j-1]);
        }
    }
    //지그재그모양
    //가로
    for(int i=2;i<=N-1;i++){
        sum = arr[i][1]+arr[i][2];
        MAX = update3(MAX,sum+arr[i-1][1]+arr[i+1][2],sum+arr[i-1][2]+arr[i+1][1]);
        for(int j=3;j<=M;j++){
            sum = sum + arr[i][j] - arr[i][j-2];
            MAX = update3(MAX,sum + arr[i-1][j]+arr[i+1][j-1],sum+arr[i-1][j-1]+arr[i+1][j]);
        }
    }
    //세로
    for(int j=2;j<=M-1;j++){
        sum = arr[1][j]+arr[2][j];
        MAX = update3(MAX,sum+arr[1][j-1]+arr[2][j+1],sum+arr[1][j+1]+arr[2][j-1]);
        for(int i=3;i<=N;i++){
            sum = sum + arr[i][j] - arr[i-2][j];
            MAX = update3(MAX,sum + arr[i-1][j-1] + arr[i][j+1],sum+arr[i-1][j+1]+arr[i][j-1]);
        }
    }
    cout<<MAX<<endl;

    fin.close();
    
}