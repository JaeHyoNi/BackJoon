#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    int T,siz,start,end,num,num_siz; cin>>T;
    string p,temp;
    bool pass;
    while(T--){
        start = 0;
        cin>>p;
        cin>>num;end = num-1;num_siz = num; num=0;
        cin>>temp;
        int k = 0;
        for (int i=0;i<temp.size();i++){
            if (temp[i]=='['){continue;} 
            else if (temp[i]==','||temp[i]==']'){if (num!=0){arr[k] = num;k++;}num=0;} 
            else {num=num*10+temp[i]-'0';}
        }
        pass = true;
        for(auto K:p){
            if(K == 'R'){swap(start,end);}
            else if(K=='D'){
                if(start<end) start += 1;
                else start -= 1;
                num_siz -= 1;
                if(num_siz<0){pass = false;cout<<"error\n"; break;}
            }
        }
        if(pass){
            if(num_siz == 0) {cout<<"[]"<<endl;}
            else{
                cout<<"["<<arr[start];
                if(start < end){for(int i=start+1; i<=end; i++){cout<<","<<arr[i];}}
                else {for(int i=start-1; i>=end; i--){cout<<","<<arr[i];}}
                cout<<"]"<<endl;
            }
        }
        else    {continue;}
    }
}

