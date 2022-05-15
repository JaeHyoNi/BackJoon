#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
struct point{int x;int y;};
int x[4] = {-1,0,1,0} , y[4] = {0,1,0,-1};
int N2,M2;
#define gogo(x,y)   if(arr[x][y] == '.') {wait.push({x,y}); arr[x][y] = '*';}\
                    else if(arr[x][y] == '$') {wait.push({x,y}); ans++; arr[x][y] = '*';}\
                    else if(isalpha(arr[x][y]) == 2) {wait.push({x,y}); key[tonum(arr[x][y])] = true; arr[x][y] = '*';}\
                    else if(isalpha(arr[x][y]) == 1){\
                        if(key[tonum(arr[x][y])]){wait.push({x,y});}\
                        else{door[tonum(arr[x][y])].push({x,y});} \
                        arr[x][y] = '*';\
                    };

int tonum(char C){
    if(C<=90){return C-'A';}
    else return C-'a';
}
void show(){
    for(int i=0;i<N2;i++){
        for(int j=0;j<M2;j++){
            cout<<arr[i][j];
        }cout<<endl;
    }cout<<endl;
}

int main(){
    int T,N,M,ans; cin>>T;
    point tmp,tmp2;
    string str;
    char c;
    ofstream of;
    of.open("text.txt");
    while(T--){
        ans = 0;
        cin>>N>>M;
        N2 = N,M2 = M;
        queue<point> wait;
        queue<point> door[26];
        bool key[26] = {false,};
        for(int i=0;i<N;i++){for(int j=0;j<M;j++){cin>>arr[i][j];}}
        cin>>str;
        if(str == "0"){}
        else {for(auto K:str){key[tonum(K)] = true;}}

        for(int i=0;i<N;i++){gogo(i,0);     gogo(i,M-1);}
        for(int j=0;j<M;j++){gogo(0,j);     gogo(N-1,j);}
        for(int i=0;i<26;i++){
            if(key[i]){
                while(!door[i].empty()){wait.push(door[i].front()); door[i].pop();}
            }
        }
        while(!wait.empty()){
            tmp = wait.front(); wait.pop();
            for(int i=0;i<4;i++){
                tmp2 = {tmp.x+x[i],tmp.y+y[i]};
                if(tmp2.x >= 0 && tmp2.x < N && tmp2.y>=0 && tmp2.y<M){
                    c = arr[tmp2.x][tmp2.y];
                    if(c == '*') continue;
                    else if(c == '.' || c == '$'){
                        if(c == '$') {ans++;}
                        wait.push(tmp2);
                    }
                    else if(isalpha(c) == 1){
                        if(key[tonum(c)]){wait.push(tmp2);}
                        else{door[tonum(c)].push(tmp2);}
                    }
                    else if(isalpha(c) == 2){
                        if(!key[tonum(c)]){
                            key[tonum(c)] = true;
                            while(!door[tonum(c)].empty()){wait.push(door[tonum(c)].front()); door[tonum(c)].pop();}
                        }
                        wait.push(tmp2);
                    }
                    arr[tmp2.x][tmp2.y] = '*';
                }
            }
        }
        of<<ans<<endl;
        cout<<ans<<endl;
    }
    of.close();
}