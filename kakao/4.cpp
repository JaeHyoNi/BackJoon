#include <bits/stdc++.h>
using namespace std;




int arr[6] = {1,3,7,15,31,63};

bool check(string &str){
    for(int i=1; i<str.size(); i+=2){
        if(str[i] == '0') return false;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto K:numbers){
        string str;
        int siz = 0;
        while(K != 0) {
            if (K%2 == 1) str.push_back('1');
            else    str.push_back('0');
            K /= 2;
            siz++;
        }
        reverse(str.begin(),str.end());
        string str1,str2;
        if(siz <= 3){
            if(siz == 1){
                str1 = '0' + str + '0';
                if(check(str1)){answer.push_back(1);}
            }
            else if(siz == 2){
                str1 = '0' + str;
                str2 = str + '0';
                if(check(str1) || check(str2)){answer.push_back(1);}
                else(answer.push_back(0));
                }
            else if(siz == 3){
                if(check(str)){answer.push_back(1);}
                else(answer.push_back(0));
            }
        }
        else if(siz <= 7){
            if(siz == 5){
                str1 = '0' + str + '0';
                if(check(str1)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 6){
                str1 = '0' + str;
                str2 = str + '0';
                if(check(str1) || check(str2)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 7){
                if(check(str)){answer.push_back(1);}
                else(answer.push_back(0));
            }
        }
        else if(siz <= 15){
            if(siz == 13){
                str1 = '0' + str + '0';
                if(check(str1)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 14){
                str1 = '0' + str;
                str2 = str + '0';
                if(check(str1) || check(str2)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 15){
                if(check(str)){answer.push_back(1);}
                else(answer.push_back(0));
            }
        }
        else if(siz <= 31){
            if(siz == 29){
                str1 = '0' + str + '0';
                if(check(str1)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 30){
                str1 = '0' + str;
                str2 = str + '0';
                if(check(str1) || check(str2)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 31){
                if(check(str)){answer.push_back(1);}
                else(answer.push_back(0));
            }
        }
        else if(siz <= 63){
            if(siz == 61){
                str1 = '0' + str + '0';
                if(check(str1)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            
            else if(siz == 62){
                str1 = '0' + str;
                str2 = str + '0';
                if(check(str1) || check(str2)){answer.push_back(1);}
                else(answer.push_back(0));
            }
            else if(siz == 63){
                if(check(str)){answer.push_back(1);}
                else(answer.push_back(0));
            }
        }
    }
    return answer;
}

int main(){
    vector<int> arr = solution({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16});
    for(auto K:arr){
        cout<<K<<" ";
    }
}


// bool isit(string str){
//     bool is = true;
//     int pivot = 1;
//     if(str[pivot] == '0'){return false;}
//     while(str[pivot] == '1'){
//         pivot = pivot*2+1;
//         if(pivot >= 63) break;
//     }
//     cout<<"pivot : "<<pivot<<endl;
//     for(int i=0;i<pivot;i++){
//         if(i%2 == 1){
//             if(str[i] == '0'){
//                 return false; 
//             }
//         }
//     }
//     for(int i=pivot;i<129;i++){
//         if(str[i] == '1'){
//             return false;
//         }
//     }
//     return true;
// }


// vector<int> solution(vector<long long> numbers) {
//     vector<int> answer;
//     string str;
//     for(auto K:numbers){
//         if(K==1){
//             answer.emplace_back(1);
//             continue;
//         }
//         bitset<129> num = bitset<129>(K);
//         str = num.to_string();
//         reverse(str.begin(),str.end());
//         cout<<str<<endl;
//         if(isit(str) == true){
//             answer.push_back(1);
//         }
//         else{
//             if(isit("0"+str) == true){
//                 answer.push_back(1);
//             }
//             else
//                 answer.push_back(0);
//         }
//     }

//     return answer;
// }