#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int>> alpa;
int main(){
    string str,temp;
    queue<string> str_set;
    cin>>str;
    str_set.push(str);
    int answer = 0;
    while(!str_set.empty()){
        temp = str_set.front();
        str_set.pop();
		if (temp.empty()) continue;
        int siz = temp.size();
        if(siz == 1){
            answer++;
            continue;
        }
        cout<<"now check : "<<temp<<endl;
        int i = 1,j,temp_max = 1;
        int st_index=0,en_index=0 , this_max=0;
        int st,en;
        while(i<siz){
            int temp_max=1,st = i-1,en = i+1;
            while(st>=0 && en < siz && temp[st] == temp[en]){
                st -- ; en ++ ;
                temp_max += 2;
            }
            if(temp_max > this_max){
                this_max = temp_max;
                st_index = st+1, en_index = en-1;
            }
            st = i-1,en = i,temp_max = 0;
            while(st>=0 && en < siz && temp[st] == temp[en]){
                st--; en++;
                temp_max += 2;
            }
            if(temp_max > this_max){
                this_max = temp_max;
                st_index = st+1, en_index = en-1;
            }
            i++;
        }
        cout<<temp.substr(st_index , en_index-st_index+1)<<endl;
        if(st_index != 0 )    str_set.push(temp.substr(0,st_index));
        if(en_index != siz-1) str_set.push(temp.substr(en_index + 1));
        i++;       
        answer = answer + 1;
    }
	cout << answer << endl;
}