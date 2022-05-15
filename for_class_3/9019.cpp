#include <bits/stdc++.h>
using namespace std;
char VISIT[10000];
int siz,from,to,d;

int main(){
    int N;  cin>>N;
    queue<pair<int,string>> wait;
    bool find = false;
    int temp; pair<int,string> tmp;
    string emp = "";
    while(N--){
        cin>>from>>to;
        siz = to_string(from).size();
        wait.push({from,emp});
        find = false;
        while(!wait.empty()){
            siz = wait.size();
            while(siz--){
                tmp = wait.front();wait.pop();
                temp = (tmp.first*2)%10000;
                if(temp == to) {find = true;cout<<tmp.second+'D'<<endl;break;}
                if(!find && VISIT[temp] == false){
                    VISIT[temp] = true;
                    wait.push({temp,(tmp.second + 'D')});
                }
                temp = tmp.first/1000 + (tmp.first*10)%10000;
                if(temp == to) {find = true;cout<<tmp.second+'L'<<endl;break;}
                if(!find && VISIT[temp] == false){
                    VISIT[temp] = true;
                    wait.push({temp,(tmp.second + 'L')});
                }
                temp = tmp.first/10 + 1000*(tmp.first%10);
                if(!find && temp == to) {find = true;cout<<tmp.second+'R'<<endl;break;}
                if(VISIT[temp] == false){
                    VISIT[temp] = true;
                    wait.push({temp,(tmp.second + 'R')});
                }
                temp = tmp.first-1;
                if(temp == -1) temp = 9999;
                if(temp == to) {find = true;cout<<tmp.second+'S'<<endl;break;}
                if(!find && VISIT[temp] == false){
                    VISIT[temp] = true;
                    wait.push({temp,(tmp.second + 'S')});
                }
            }
            if(find) {
                while(!wait.empty()) wait.pop();
                memset(VISIT,false,10000);
                break;
            }
        }        
    }
}
