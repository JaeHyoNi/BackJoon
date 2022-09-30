#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans;
int N,UN;

void show(vector<int> arr){
    for(auto K:arr){
        cout<<K<<" ";
    }cout<<endl;
}

void calcul(vector<vector<int>> &users,vector<int> &emotions, vector<int> &events){
    show(events);
    vector<int> pay(UN,0);
    pair<int,int> eve = {0,0};
    for(int i=0;i<UN;i++){
        for(int j=0;j<N;j++){
            if(events[j] >= users[i][0]){
                pay[i] += emotions[j]*(100-events[j])/100;
            }
        }
        cout<<users[i][0]<<" , "<<users[i][1]<<"  - " << pay[i]<<endl;
        if(users[i][1] <= pay[i]){
            eve.first += 1;
        }
        else{
            eve.second += pay[i];
        }
    }
    cout<<"["<<eve.first<<","<<eve.second<<"]"<<endl;
    if(eve.first > ans.first) {ans = eve; 
    // show(events);
    }
    else if(eve.first == ans.first){
        if(eve.second > ans.second){
            ans = eve;
            // show(events);
        }
    }
}



void DFS(vector<vector<int>> &users,vector<int> &emotions, vector<int> events,int dep){
    // show(events);
    if(dep == N){
        calcul(users,emotions,events);
        return;
    }
    else{
        events[dep] = 10;
        DFS(users,emotions,events,dep+1);
        events[dep] = 20;
        DFS(users,emotions,events,dep+1);
        events[dep] = 30;
        DFS(users,emotions,events,dep+1);
        events[dep] = 40;
        DFS(users,emotions,events,dep+1);
    }
}



vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> events(emoticons.size(),0);
    UN = users.size();
    N = emoticons.size();
    DFS(users,emoticons,events,0);
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}


int main(){
    vector<int> arr = solution( {{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}},{1300,1500,1600,4900});
    for(auto K:arr){
        cout<<K<<" ";
    }
}