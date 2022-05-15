#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
int siz;
int max_num;
int burst_time=0;
int num;
vector<int> move_temp,line;
//미는 함수
vector<int> move(vector<int> &slide,int r){
    move_temp.clear();
    for(int i=0;i<r;i++){
        if(slide[i] == 0) continue;
        for(int j=i+1;j<r;j++){
            if(slide[i] == slide[j]) {
                move_temp.push_back(slide[i]*2);
                slide[i] = slide[j] = 0;
                break;
            }
            else if(slide[j] == 0) continue;
            else break;
        }
        if(slide[i] != 0) move_temp.push_back(slide[i]);
    }
    int k = r - move_temp.size();
    for(int i=0;i<k;i++) move_temp.push_back(0);
    return move_temp;
}
void pm(vector<vector<int>> &arr){
    for(auto K:arr){
        for (auto J:K){
            cout.width(5);
            cout<<J;
        }cout<<endl;
    }cout<<endl;
    return;
}

int check_answer(vector<vector<int>> &arr,int &r,int &c){
    int t_max;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] > t_max){
                t_max = arr[i][j];
            }
            if(arr[i][j] > max_num){
                max_num = arr[i][j];
                //pm(arr);
              //  cout<<"answer here"<<endl;
            }
        }
    }
    return t_max;
}

bool leftright(vector<vector<int>> &arr , vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<r/2;i++){
        for(int j=0;j<c/2;j++){
            if(arr[i][j] != temp[i][siz-1-j]) return false;
        }
    }
    return true;
}
bool updown(vector<vector<int>> &arr , vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<c/2+1;i++){
        for(int j=0;j<r/2;j++){
            if(arr[j][i] != temp[r-1-j][i]) return false;
        }
    }
    return true;
}

void up(vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<c;i++){
        line.clear();
        for(int j=0;j<r;j++){
            line.push_back(temp[j][i]);
        }
        line = move(line,r);
        for(int j=0;j<r;j++){temp[j][i] = line[j];}
    }
}
void left(vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<r;i++){
        temp[i] = move(temp[i],c);
    }
}
void right(vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<r;i++){ 
        line.clear();
        reverse(temp[i].begin(),temp[i].end());
        line = move(temp[i],c);
        reverse(line.begin(),line.end());
        temp[i] = line;
    }
}
void down(vector<vector<int>> &temp,int &r,int &c){
    for(int i=0;i<c;i++){
        line.clear();
        for(int j=r-1;j>=0;j--){
            line.push_back(temp[j][i]);
        }
        line = move(line,r);
        reverse(line.begin(),line.end());
        for(int j=r-1;j>=0;j--){temp[j][i] = line[j];}
    }
    
}
void construct(vector<vector<int>> &arr,int &r,int &c){
    int min_x = r,max_x = 0,min_y = c,max_y = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] != 0 ){
                if(i<min_x) min_x = i;
                if(max_x<i) max_x = i;
                if(j<min_y) min_y = j;
                if(j>max_y) max_y = j;
            }
        }
    }
    //printf("[%d,%d] , [%d,%d]\n",min_x,min_y,max_x,max_y);
    if(min_x == r ) {arr.clear(); return;}
    else{
        r = max_x-min_x+1;
        c = max_y-min_y+1;
        vector<vector<int>> temp(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[i][j] = arr[i+min_x][j+min_y];
            }
        }
        arr = temp;
        return;
    }
}

void dfs(int dep,vector<vector<int>> &arr,int r,int c){
    pm(arr);
    num++;
    // cout<<"-------------------DEP = "<<dep<<"--------------------"<<endl;
    int t_max = check_answer(arr,r,c);
    for(int i=dep;i<10;i++){
        t_max = t_max * 2;
    }
    if(t_max <= max_num) return;
    if(dep == 10){
        return;
    }
    //원래꺼 복사하고
    vector<vector<int>> temp1  = arr;
    construct(temp1,r,c);
    vector<vector<int>>temp2 = temp1,temp3 = temp1;
    //printf("r = %d , c = %d\n",r,c);
    //위로 밀기
    up(temp1,r,c);
    //pm(temp1);
    if(temp1 == temp3){check_answer(temp1,r,c);}
    else if(updown(temp1,temp3,r,c)){burst_time++;}
    else dfs(dep+1 , temp1,r,c);
    //아래로 밀기
    // pm(temp1);
    down(temp2,r,c);
    //pm(temp2);
    if(temp2 == temp3){check_answer(temp2,r,c);}
    else if(updown(temp1,temp2,r,c)){burst_time++;}
    else dfs(dep+1,temp2,r,c);
    // pm(temp2);
    //왼쪽으로 밀기
    temp1 = temp3;
    left(temp1,r,c);
    //pm(temp1);
    if(temp1 == temp3){check_answer(temp1,r,c);}
    else if(leftright(temp1,temp3,r,c)){burst_time++;}
    else dfs(dep+1,temp1,r,c);
    // pm(temp1);
    //오른쪽으로 밀기
    temp2 = temp3;
    right(temp2,r,c);
    //pm(temp2);
    if(temp2 == temp3){check_answer(temp2,r,c);}
    else if(leftright(temp1,temp2,r,c)){burst_time++;}
    else dfs(dep+1,temp2,r,c);
    // pm(temp2);
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
    // vector<int> temp;
    //time_t start,end;
    //double result;
    //start = time(NULL);
    dfs(0,arr,siz,siz);
    //end = time(NULL);
    //result = (double)(end-start);
    cout<<max_num<<endl;
    //cout<<burst_time<<" "<<num<<endl;
    //printf("%f초",result);
    return 0;
}