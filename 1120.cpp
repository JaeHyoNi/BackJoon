#include <bits/stdc++.h>
using namespace std;

int main(){
    string A,B;
    cin>>A>>B;
    int sizA = A.size(),sizB = B.size();
    int ans=99999,temp=0;
    for(int i=0;i<sizB-sizA+1;i++){
        temp = 0;
        for(int j=0;j<sizA;j++){
            if(A[j] != B[j+i]) temp+=1;
        }
        if(temp<ans) ans = temp;
    }
    cout<<ans;
}
