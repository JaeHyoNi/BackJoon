#include <bits/stdc++.h>
using namespace std;
using ll  = long long;


int arr[20][20],siz;
int max_num;

//미는 함수
vector<int> move(vector<int> slide){
    vector<int> temp;
    for(int i=0;i<siz;i++){
        if(slide[i] == 0) continue;
        for(int j=i+1;j<siz;j++){
            if(slide[i] == slide[j]) {
                temp.push_back(slide[i]*2);
                slide[i] = slide[j] = 0;
                break;
            }
            else if(slide[j] == 0) continue;
            else break;
        }
        if(slide[i] != 0) temp.push_back(slide[i]);
    }
    int k = siz - temp.size();
    for(int i=0;i<k;i++) temp.push_back(0);
    return temp;
}


// void pm(vector<vector<int>> &arr){
//     for(auto K:arr){
//         for (auto J:K){
//             cout.width(2);
//             cout<<J;
//         }cout<<endl;
//     }cout<<endl;
//     return;
// }
void check_answer(vector<vector<int>> &arr){
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            if(arr[i][j] > max_num){
                max_num = arr[i][j];
            }
        }
    }
    return;
}

void dfs(int dep,vector<vector<int>> arr){
    //cout<<"-------------------DEP = "<<dep<<"--------------------"<<endl;
    if(dep == 5){
        check_answer(arr);
        return;
    }
    //원래꺼 복사하고
    vector<vector<int>> temp = arr;
    vector<int>  line;
    //위로 밀기
    for(int i=0;i<siz;i++){
        line.clear();
        for(int j=0;j<siz;j++){line.push_back(temp[j][i]);}
        line = move(line);
        for(int j=0;j<siz;j++){temp[j][i] = line[j];}
    }
    // pm(temp);
    if(temp == arr){
        check_answer(temp);
        // cout<<"this is same!"<<endl;
    }
    else dfs(dep+1 , temp);

    //왼쪽으로 밀기
    temp = arr;
    for(int i=0;i<siz;i++){
        temp[i] = move(temp[i]);
    }
    // pm(temp);
    if(temp == arr){
        check_answer(temp);
        // cout<<"this is same!"<<endl;
    }
    else dfs(dep+1,temp);
    //오른쪽으로 밀기
    temp = arr;
    for(int i=0;i<siz;i++){ 
        line.clear();
        reverse(temp[i].begin(),temp[i].end());
        line = move(temp[i]);
        reverse(line.begin(),line.end());
        temp[i] = line;
    }
    // pm(temp);
    if(temp == arr){
        check_answer(temp);
        // cout<<"this is same!"<<endl;
    }
    else dfs(dep+1,temp);
    //아래로 밀기
    temp = arr;
    for(int i=0;i<siz;i++){
        line.clear();
        for(int j=siz-1;j>=0;j--){line.push_back(temp[j][i]);}
        line = move(line);
        reverse(line.begin(),line.end());
        for(int j=siz-1;j>=0;j--){temp[j][i] = line[j];}
    }
    // pm(temp);
    if(temp == arr){
        check_answer(temp);
        // cout<<"this is same!"<<endl;
    }
    else dfs(dep+1,temp);
    return;
}

int main(){
    scanf("%d",&siz);
    vector<vector<int>> arr(siz,vector<int>(siz,0));
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //pm(arr);
    dfs(0,arr);
    cout<<max_num<<endl;
    return 0;
}