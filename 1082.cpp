#include <bits/stdc++.h>
using namespace std;
vector<int> price;
int N,money,MIN=9999999,MIN_n,temp;
string answer = "";

void uping(string &str){
    for(auto &K:str){
        for(int i=N-1;i>temp;i--){
            if(money >= price[i]){
                K = i+'0'; money-=price[i];
                break;
            }
        }
    }
}

int main(){ cin>>N; price.resize(N);
    for(int i=0;i<N;i++){cin>>price[i]; if(price[i] <= MIN){ MIN_n = i , MIN = price[i];}}
    cin>>money;
    for(int i=0;i<N;i++){price[i]-=MIN;}
    for(int i=0;i<money/MIN;i++){answer.push_back(MIN_n+'0');}
    money %= MIN;
    temp = MIN_n;
    if(answer[0] == '0'){temp = 0;}
    uping(answer);
    if(answer[0] == '0'){
        bool change = false;
        while(!change){
            if(answer.empty()) break;
            for(int i=N-1;i>0;i--){
                if(money>=price[i]){
                    answer[0] = i+'0';
                    change = true;
                    break;
                }
            }
            if(!change){answer.pop_back(); money+=MIN;}
        }
    }
    uping(answer);
    if(answer.empty()) cout<<0;
    else{cout<<answer;}
    return 0;
}


    // //이건 오류나는 조건을 포함시켜서 한거
    // struct temp{int val;string ord;};

    // void show(temp cache[][51],int N,int money){
    //     for(int i=0;i<=money;i++){
    //         cout.width(3);
    //         cout<<i;
    //     }cout<<endl;
    //     for(int i=0;i<N;i++){
    //         for(int j=0;j<=money;j++){
    //             cout.width(3);
    //             cout<<cache[i][j].val;
    //         }
    //         cout<<" : "<<cache[i][money].ord<<endl;
    //     }cout<<endl;
    // }
    // int N,money; cin>>N;
    // temp cache[10][51];
    // for(int i=0;i<N;i++){for(int j=0;j<51;j++) cache[i][j] = {0,""};}
    // vector<int> price;  price.resize(N);
    // for(int i=0;i<N;i++){cin>>price[i];}
    // cin>>money;
    // for(int i=price[0];i<=money;i++){cache[0][i]= cache[0][i-price[0]]; cache[0][i].val++; cache[0][i].ord+= "0";}
    // for(int i=1; i<N;i++){
    //     for(int j=0; j<=money; j++){
    //         if(j%price[i] == 0){
    //             if(j/price[i] > 0){
    //                 if(cache[i-1][j-price[i]].val > cache[i][j-price[i]].val){
    //                     cache[i][j] = cache[i-1][j-price[i]];
    //                     cache[i][j].val += 1;
    //                     cache[i][j].ord.push_back((char)i+'0');
    //                 }
    //                 else{
    //                     cache[i][j] = cache[i][j-price[i]];
    //                     cache[i][j].val ++; cache[i][j].ord.push_back(i+'0');
    //                 }
    //             }
    //         }
    //         else if(cache[i-1][j-price[i]].val > 0){
    //             cache[i][j] = cache[i][j-price[i]];
    //             cache[i][j].val++; cache[i][j].ord.push_back(i+'0');
    //         }
    //         else if(cache[i-1][j].val > cache[i][j].val){
    //             cache[i][j] = cache[i-1][j];
    //         }
    //     }
    // }
    // for(int i=price[0];i<=money;i++){
    //     if(cache[N-1][i-price[0]].val != 0){
    //         cache[0][i] = cache[N-1][i-price[0]];
    //         cache[0][i].val++;
    //         cache[0][i].ord.push_back('0');
    //     }
    // }