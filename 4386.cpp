#include <bits/stdc++.h>
using namespace std;

struct star{double from; double to;};
struct road{double val;int from; int to;};
vector<star> stars;
vector<road> roads;

double distance(star &a , star &b){return sqrt(pow(a.from-b.from,2)+pow(a.to-b.to,2));}
int arr[101];

int find_mother(int num){
    if(arr[num] == num){return num;}
    else{return arr[num] = find_mother(arr[num]);}
}

void uni(int a,int b){
    a = find_mother(a);
    b = find_mother(b);
    if(a!=b){
        if(a>=b) arr[a] = b;
        else arr[b] = a;
    }
}


int main(){
    int N; cin>>N;
    stars.resize(N);
    double temp,ans=0;
    for(int i=0;i<N;i++){cin>> stars[i].from >> stars[i].to;}
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            temp = distance(stars[i],stars[j]);
            roads.push_back( {temp, i , j} );
        }
    }
    sort(roads.begin(),roads.end(),[](road &a, road &b){return a.val < b.val;});
    for(int i=0;i<N;i++){arr[i] = i;}
    cout<<endl;
    //for(auto K: roads){cout<<K.val<<" "<<K.from<<" "<<K.to<<"\n";}
    int siz = 0;
    for(auto K: roads){
        if(find_mother(K.from)!=find_mother(K.to)){
            siz++;
            ans += K.val;
            uni(K.from,K.to);
        }
        if(siz == N-1) break;
    }
    cout<<ans<<"\n";
}