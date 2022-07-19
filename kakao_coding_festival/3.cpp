#include <bits/stdc++.h>
using namespace std;
bool arr[2000][2000] = {false,};

int main(){
    int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};
    int N,M,num=0,a,b,answer=1;    cin>>N>>M; 
    bool plus;
    string str;
    for(int i=0; i<N; i++){ cin>>str;
        for(int j=0; j<M; j++){
            arr[i][j] = (str[j] == 'W') ? true : false;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            plus = true;
            for(int k=0; k<4; k++){
                a = i+x[k] , b = j+y[k];
                if(a>=0 && b>=0 && a<N && b<M){
                    if(arr[a][b] != arr[i][j]){
                        plus = false; break;
                    }    
                }
            }
            if(plus) num++;
        }
    }
    for(int i=0;i<num;i++){
        answer *= 2;
        answer %= 1000000007;
    }
    cout<<answer;
}

// int N,M;
// bool arr[2000][2000] = {false,},VISIT[2000][2000] = {false,};
// int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};

// long long solution(int a,int b){
//     long long answer = 0;
//     int xx,yy,xxx,yyy;
//     bool flag = arr[a][b] ,able = false;
//     queue<pair<int,int>> point; point.push({a,b});
//     VISIT[a][b] = true;
//     while(!point.empty()){
//         xx = point.front().first , yy = point.front().second; point.pop();
//         able = true;
//         for(int i=0;i<4;i++){
//             xxx = xx+x[i] , yyy = yy+y[i];
//             if(xxx>=0 && yyy>=0 && xxx<N && yyy<M){
//                 if(arr[xxx][yyy] == flag){
//                     if(VISIT[xxx][yyy]) continue;
//                     point.push({xxx,yyy,});
//                     VISIT[xxx][yyy] = true;
//                 }
//                 else{able = false;}
//             }
//         }
//         if(able) answer+=1;
//     }
//     return answer;
// }

// int main(){
//     cin>>N>>M;
//     string str;
//     for(int i=0;i<N;i++){
//         cin>>str; for(int j=0;j<M;j++){arr[i][j] = str[j]=='W' ? true : false;}
//     }
//     long long answer = 0,temp = 0;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             if(!VISIT[i][j])    answer += solution(i,j);
//         }
//     }
//     if(answer == 0) cout<<"1";
//     else{
//         temp = 1;
//         for(int i=0;i<answer;i++){
//             temp *= 2;
//             temp %= 1000000007;
//         }
//         cout<<temp;
//     }
// }