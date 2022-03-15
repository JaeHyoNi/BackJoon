#include <iostream>
#include <bitset>
using namespace std;


int main(void){
    int N1,N2,ans=0;
    cin>>N1;
    N2 = N1 * (-1);
    bitset<32> bs1(N1);
    bitset<32> bs2(N2);
    for( int i = 0; i < 32; i++ ){
        if(bs1[i] != bs2[i]) ans = ans + 1;
    }
    cout<<ans;
}
