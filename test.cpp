#include <bits/stdc++.h>
using namespace std;
#define max 500000000
bool arr[max];

int main()
{
    ofstream fout;
    fout.open("test_txt/prime.txt");
    arr[0] = 1;arr[1] = 1;
    for(int i=2;i<max;i++){
        if(arr[i] == 0){
            int k = 2;
            while(k*i<max){
                arr[k*i] = 1;
                k++;
            }
        }
    }
    for(long long i=2;i<max;i++){
        if(arr[i] == 0){
            if(i*i>2000000000) {
                fout.close();
                return 0;
            }    
            fout<<i*i<<", ";
        }
    }
    fout.close();
}