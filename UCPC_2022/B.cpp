#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define point pair<long long,long long>
struct line{point a;point b;};
vector<line> li; //베기 리스트
vector<vector<int>> nesting; //중첩되는것  
vector<pair<long long,long long>> w; // [weight, 순서]
vector<int> ord; //연결된것들 개수

//선분 겹침 확인
int ccw(const point &a,const point &b,const point &c){
    ll temp = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
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
    int N; cin>>N;
    line temp;
    nesting.resize(N);
    ord.resize(N,0);
    w.resize(N);
    for(int i=0;i<N;i++){
        cin>>temp.a.first>>temp.a.second>>temp.b.first>>temp.b.second>>w[i].first; 
        w[i].second = i; 
        li.emplace_back(temp);
        for(int j=0;j<i;j++){
            if(slicing(li[j],temp)){
                nesting[i].emplace_back(j);
                nesting[j].emplace_back(i);
                ord[i]++; ord[j]++;
            }
        }
    }
    ll SUM = 0;
    //무게순으로 정렬
    sort(w.begin(),w.end(), [](pair<ll,ll> &a,pair<ll,ll> &b) {return a.first<=b.first;});
    //w에 대해서 weight순으로 정렬된 순서대로 검법 발동
    for(auto K:w){
        // printf("[%d %d %d %d %d] : %d\n",t.a.first,t.a.second,t.b.first,t.b.second,K.first,(ord[K.second]+1)*K.first);
        SUM += (ord[K.second]+1)*K.first;
        //중첩됬던거 제거
        for(auto J:nesting[K.second]){ord[J]--;}
    }    
    cout << SUM << "\n";
}