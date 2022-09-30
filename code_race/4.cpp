#include <bits/stdc++.h>
using namespace std;
int arr[2][500000];
bool jum(char A,char B){
    if(A>B) swap(A,B);
    if(A=='l' && B=='l') return true;
    if(A=='o' && B=='o') return true;
    if(A=='x' && B=='x') return true;
    if(A=='s' && B=='s') return true;
    if(A=='z' && B=='z') return true;
    if(A=='n' && B=='u') return true;
    if(A=='b' && B=='q') return true;
    if(A=='d' && B=='p') return true;
    return false;
}
bool gua(char A,char B){
    if(A>B) swap(A,B);
    if(A=='p' && B=='q') return true;
    if(A=='b' && B=='d') return true;
    if(A=='o' && B=='o') return true;
    if(A=='w' && B=='w') return true;
    if(A=='i' && B=='i') return true;
    if(A=='m' && B=='m') return true;
    if(A=='v' && B=='v') return true;
    if(A=='l' && B=='l') return true;
    if(A=='x' && B=='x') return true;
    return false;
}


int main(){
    string str; cin>>str;
    int siz = str.size();
    int MAX = 0;
    for(int i=0;i<siz;i++){
        if(str[i] == 'o' || str[i] == 'l' || str[i] == 'x' || str[i] == 's' || str[i] == 'z'){
            arr[0][i] = 1;
        }
        if(str[i] == 'o' || str[i] == 'l' || str[i] == 'x'){
            arr[1][i] = 1;
        }
    }
    //1은 점대칭
    //2는 거울대칭
    for(int i=1;i<siz;i++){
        if(arr[0][i-1] != 0){
            int temp;
            int flag = arr[0][i-1];
            flag = i-flag-1;
            if(flag >= 0 && jum(str[i],str[flag])){
                arr[0][i] = arr[0][i-1] + 2;
            }
        }
    }






    // for(int i=0;i<siz;i++){
    //     if(str[i] == 'o' || str[i] == 'l' || str[i] == 'x' || str[i] == 's' || str[i] == 'z'){
    //         int temp = 1;
    //         int f = i-1 , b = i+1;
    //         while(f>=0 && b<siz && jum(str[f],str[b])){
    //             f--; b++; temp+=2;
    //         }
    //         MAX = max(MAX,temp);
    //     }
    //     if(str[i] == 'o' || str[i] == 'l' || str[i] == 'x'){
    //         int temp = 1;
    //         int f = i-1 , b = i+1;
    //         cout<<str[0] <<" "<<str[2]<<endl;
    //         while(f>=0 && b<siz && gua(str[f],str[b])){
    //             f--; b++; temp+=2;
    //         }
    //         MAX = max(MAX,temp);
    //     }
    //     if(i+1<siz){
    //         if(jum(str[i],str[i+1])){
    //             int temp = 2;
    //             int f = i-1 , b = i+2;
    //             while(f>=0 && b<siz && jum(str[f],str[b])){
    //                 f--; b++; temp+=2;
    //             }
    //             MAX = max(MAX,temp);
    //         }
    //         if(gua(str[i],str[i+1])){
    //             int temp = 2;
    //             int f = i-1 , b = i+2;
    //             while(f>=0 && b<siz && gua(str[f],str[b])){
    //                 f--;b++;temp+=2;
    //             }
    //             MAX = max(MAX,temp);
    //         }
    //     }
    // }
    if(MAX == 0){cout<<"NOANSWER";}
    else cout<<MAX;
}