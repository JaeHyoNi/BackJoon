#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    string temp;
    int siz = s.size();
    for(int i=0;i<siz;i++){
        if(isdigit(s[i])){
            temp.push_back(s[i]);
        }
        else if(s[i] == 'z'){temp.push_back('0');i+=3;}
        else if(s[i] == 'o'){temp.push_back('1');i+=2;}
        else if(s[i] == 'e'){temp.push_back('8');i+=4;}
        else if(s[i] == 'n'){temp.push_back('9');i+=3;}
        else if(s[i] == 't'){
            if(s[i+1] == 'w'){temp.push_back('2');i+=2;}
            else if(s[i+1] == 'h'){temp.push_back('3');i+=4;}
        }
        else if(s[i] == 'f'){
            if(s[i+1] == 'o'){temp.push_back('4');i+=3;}
            else if(s[i+1] == 'i'){temp.push_back('5');i+=3;}
        }
        else if(s[i] == 's'){
            if(s[i+1] == 'i'){temp.push_back('6');i+=2;}
            else if(s[i+1] == 'e'){temp.push_back('7');i+=4;}
        }
    }
    int answer = stoi(temp);
    return answer;
}
int main(){
    string str; cin>>str;
    cout<<solution(str);
}