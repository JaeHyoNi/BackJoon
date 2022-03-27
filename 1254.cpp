#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int iter1,iter2,iter3,iter4,ans = 999999,siz = str.size()/2,temp,full = str.size();
    while(siz != full){
        iter1 = siz-1; iter2 = siz+1,iter3 = siz;
        while(iter1 >= 0 && iter2 < full && str[iter1] == str[iter2]){iter1--;iter2++;}
        if(iter2 == full){ans = min(ans,full+iter1+1);}
        iter1 = siz-1;
        while(iter1>=0 && iter3<full && str[iter1]==str[iter3]){iter1--;iter3++;}
        if(iter3 == full){ans = min(ans,full+iter1+1);}
        siz++;
        if(ans != 999999) break;
    }
    cout<<ans;
}