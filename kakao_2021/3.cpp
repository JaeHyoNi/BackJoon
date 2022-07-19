#include <bits/stdc++.h>
using namespace std;



string solution(int n, int k, vector<string> cmd){
    string answer = ""; 
    list<int> arr;
    for(int i=0;i<n;i++){arr.push_back(i); answer.push_back('X');}
    auto iter = arr.begin();
    stack< pair<list<int>::iterator,int>> del;
    for(int i=0;i<k;i++) iter++;
    int temp;
    for(auto K:cmd){
        if(K[0] == 'U'){
            temp = stoi(K.substr(2));
            while(temp--){iter--;}
        }
        else if(K[0] == 'D'){
            temp = stoi(K.substr(2));
            while(temp--){iter++;}
            
        }
        else if(K[0] == 'C'){
            auto t = iter; t++;
            del.push({t,*iter});
            iter = arr.erase(iter);
            if(iter == arr.end()) iter--;
        }
        else if(K[0] == 'Z'){
            arr.insert(del.top().first , del.top().second);
            del.pop();
        }
    }
    for(auto K:arr){
        answer[K] = 'O';
    }
    return answer;
}
// string solution(int n, int k, vector<string> cmd) {
//     string answer = "";
//     vector<bool> state(n,true);
//     stack<int> recent_delete;
//     int temp;
//     set<int> ord;
//     for(int i=0;i<n;i++){ord.insert(i);}
//     auto iter = ord.find(k);
//     for(auto K:cmd){
//         if(K[0] == 'U'){
//             temp = stoi(K.substr(2));
//             while(temp--){iter--;}
//         }
//         else if(K[0] == 'D'){
//             temp = stoi(K.substr(2));
//             while(temp--){iter++;}
            
//         }
//         else if(K[0] == 'C'){
//             recent_delete.push(*iter);
//             state[*iter] = false;
//             iter = ord.erase(iter);
//             if(iter == ord.end()) iter--;
//         }
//         else if(K[0] == 'Z'){
//             state[recent_delete.top()] = true;
//             ord.insert(recent_delete.top()); 
//             recent_delete.pop();
//         }
//     }

//     for(auto K:state){
//         if(K) answer.push_back('O');
//         else{answer.push_back('X');}
//     }
//     return answer;
// }

int main(){

    //string answer = solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"});
    //string answer = solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C",});
    string answer = solution(8,2,{"C","C","C","C","C","C","C","C","Z","Z","Z","Z"});
    cout<<answer;
}