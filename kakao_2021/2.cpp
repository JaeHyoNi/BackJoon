#include <bits/stdc++.h>
using namespace std;
int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool corona = false;
    int a,b,aa,bb;
    for(auto K:places){
        corona = false;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(K[i][j] == 'P'){
                    for(int k=0;k<4;k++){
                        a = i+x[k] , b = j+y[k];
                        if(a>=0 && a<5 && b>=0 && b<5){
                            if(K[a][b] == 'X') continue;
                            else if(K[a][b] == 'P'){
                                corona = true;
                                break;
                            }
                            else if(K[a][b] == 'O'){
                                for(int l=0;l<4;l++){
                                    aa = a+x[l],bb = b+y[l];
                                    if(aa == i && bb == j) continue;
                                    else if(aa>=0 && aa<5 && bb>=0 && bb<5){
                                        if(K[aa][bb] == 'P'){
                                            corona = true;
                                            break;
                                        }
                                    }
                                }
                                if(corona) break;
                            }
                        }                       
                    }
                    if(corona) break;
                }
            }
            if(corona) break;
        }
        if(corona){answer.push_back(0);}
        else{answer.push_back(1);}
    }
    return answer;
}

int main(){
    vector<int> answer = solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                    {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                    {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                    {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                    {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    for(auto K:answer){
        cout<<K;
    }
}