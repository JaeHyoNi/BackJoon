#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};

int main(){
    double x, y, MIN;
    int T,N; cin>>T;
    point points[20];
    vector<bool> ord;
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){scanf("%lf %lf",&points[i].x , &points[i].y);}
        ord.clear(); ord.resize(N,1);
        for(int i=0;i<N/2;i++) ord[i] = false;
        MIN = 9999999;
        do{
            x = y = 0;
            for(int i=0;i<N;i++){
                if(ord[i]){x += points[i].x , y+=points[i].y;}
                else {x -= points[i].x , y-=points[i].y;}
            }
            MIN = min(MIN , sqrt(pow(x,2)+pow(y,2)));
        }while(next_permutation(ord.begin(),ord.end()));
        printf("%.8f\n",MIN);
    }
}