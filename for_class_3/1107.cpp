#include <bits/stdc++.h>
using namespace std;

bool fuck[10];

int main(){
    int iter = 0,ans = 0,siz,N,M,tmp,biggest,smallest,now=100;cin>>N>>M;
    for(int i=0;i<M;i++){cin>>tmp; fuck[tmp] = true;}
    tmp = 9; while(fuck[tmp] == 1){tmp--;} biggest = tmp;
    tmp = 0; while(fuck[tmp] == 1){tmp++;} smallest = tmp;
    string str = to_string(N);
    siz = str.size();
    string big,small,mid = "0",mid2;
    if(fuck[1] == 1){mid2.push_back(smallest);}
    else mid2.push_back('1');
    if(N == 100) {cout<<"0";return 0;}
    while(fuck[str[iter]-'0'] == 0){
        big.push_back(str[iter]);
        small.push_back(str[iter]);
        iter++;
        ans++;
        if(iter==siz) break;
    }
    if(iter != siz){
        int tmp1,tmp2;
        tmp1 = tmp2 = str[iter]-'0';
        while(tmp1 < 10 && fuck[tmp1] == 1) tmp1++;
        while(tmp2 >= 0 && fuck[tmp2] == 1) tmp2--;
        if(tmp1 > 9 && tmp2 < 0){ans = 2100000000;}
        else{
            if(tmp1 < 10) big.push_back(tmp1+'0');
            else big.push_back(tmp2+'0');
            if(tmp2 >=0) small.push_back(tmp2+'0');
            else small.push_back(tmp1+'0');
            iter++;
            iter = siz-iter;
            for(int i=0;i<iter;i++){
                big.push_back(smallest+'0');
                small.push_back(biggest+'0');
            }
            int big_num = stoi(big);
            int small_num = stoi(small);
            if(abs(big_num-N) > abs(small_num-N)){ans = (abs(small_num-N)+to_string(small_num).size());}
            if(abs(big_num-N) <= abs(small_num-N)){ans = (abs(big_num-N)+to_string(big_num).size());}
        }
    }
    for(int i=0;i<siz;i++){mid2.push_back(smallest+'0');}
    int mid2_num = stoi(mid2);
    tmp = abs(mid2_num-N)+to_string(mid2_num).size();
    ans = min(ans,tmp);
    for(int i=0;i<siz-1;i++){mid.push_back(biggest+'0');}
    int mid_num = stoi(mid);
    tmp = abs(mid_num-N)+to_string(mid_num).size();
    ans = min(ans,tmp);
    ans = ans < abs(N-100) ? ans : abs(N-100);    
    cout<<ans;
}