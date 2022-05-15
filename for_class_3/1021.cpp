#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,tmp; cin>>N>>M;
    list<int> li;
    for(int i=0;i<N;i++){li.push_back(i+1);}
    vector<int> arr(M);
    for(int i=0;i<M;i++){cin>>arr[i];}
    list<int>::iterator iter = li.begin(),iter1,iter2;
    int SUM = 0;
    for(auto K:arr){
        tmp = 0;
        iter1 = iter2 = iter;
        while(*iter1 != K && *iter2 != K){
            iter1++;
            if(iter1 == li.end()) iter1 = li.begin();
            if(iter2 == li.begin()){iter2 = li.end();}
            iter2--;
            tmp++;
        }
        SUM += tmp;
        if(*iter1 == K){
            iter1 = li.erase(iter1);
            if(iter1 == li.end()) iter1 = li.begin();
            iter = iter1;
        }
        else{
            iter2 = li.erase(iter2);
            if(iter2 == li.end()) iter2 = li.begin();
            iter = iter2;
        }
    }
    cout<<SUM<<endl;
}