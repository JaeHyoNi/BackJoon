#include <bits/stdc++.h>
using namespace std;
#define point pair<int,int>
struct line{point a;point b;};
vector<bool> VISIT;
vector<line> lines;
vector<vector<int>> connect;
int ccw(const point &a,const point &b,const point &c){
    int temp = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
    return (temp > 0 ) ? 1 : temp == 0 ? 0 : -1;
}
bool slicing(line a, line b){
    int is1,is2;
    is1 = ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b);
    is2 = ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b);
    if(is1==0 && is2==0){
        if(a.a>a.b) swap(a.a,a.b);
        if(b.a>b.b) swap(b.a,b.b);
        return a.a<=b.b && b.a<=a.b;
    }
    else if(is1<=0 && is2<=0) return true;
    else return false;
}

int main(){
    int N,group_num = 0,now,MAX = 0; cin>>N;
    VISIT.resize(N,false);
    connect.resize(N);
    line temp;
    for(int i=0;i<N;i++){
        cin>>temp.a.first>>temp.a.second>>temp.b.first>>temp.b.second;
        lines.emplace_back(temp);
        for(int j=0;j<i;j++){
            if(slicing(lines[j],temp)){
                connect[i].push_back(j);
                connect[j].push_back(i);                
            }
        }
    }
    queue<int> wait;
    for(int i=0;i<N;i++){
        if(VISIT[i] == false){
            int t = 0;  group_num++;    wait.push(i);
            VISIT[i] = true;
            while(!wait.empty()){
                now = wait.front(); wait.pop(); 
                t++;
                for(auto K:connect[now]){
                    if(VISIT[K] == false){
                        VISIT[K] = true;
                        wait.push(K);
                    }
                }
            }
            if(t>MAX) MAX = t;
        }
    }
    cout<<group_num<<"\n"<<MAX;
}