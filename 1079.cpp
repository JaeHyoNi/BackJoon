#include <bits/stdc++.h>
using namespace std;
vector<int> ord;
int arr[16][16],N,her,save;
vector<int> people;
int ans = 0;

void night(int who){
    for(int i=0;i<N;i++){
        if(i==who){people[i] *= -1;}
        else{people[i] += arr[who][i];}
    }
}

void backnight(int who){
    for(int i=0;i<N;i++){
        if(i==who){people[i] *= -1;}
        else{people[i] -= arr[who][i];}
    }
}

int afternoon(){
    int who = max_element(people.begin(),people.end())-people.begin();
    people[who] *= -1;
    return who;
}
void backafternoon(int who){
    people[who] *= -1;
}


void mafia(int now){
    int who;
    if(save%2 != 0){
        who = afternoon();  save--;
        if(who == her){ans = max(ans,now);} 
        else mafia(now); 
        backafternoon(who); save++;
    }
    else{
        for(int i=0;i<N;i++){
            if(people[i] >= 0){
                night(i);   save--;
                if(i == her){ans = max(ans,now);}
                else mafia(now+1);
                backnight(i); save++;
            }
        }
    }
}
int main(){
    cin>>N; people.resize(N); save = N;
    for(int i=0;i<N;i++){cin>>people[i];}
    for(int i=0;i<N;i++){for(int j=0;j<N;j++){cin>>arr[i][j];}}
    cin>>her;
    mafia(0);
    cout<<ans;
}