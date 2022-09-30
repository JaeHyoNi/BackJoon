#include <bits/stdc++.h>
using namespace std;

int MAX = 0,N;
int flags[10] = {1024,516,256,128,64,32,16,8,4,2};

int find_max(int arr[][20]){
    int num = 0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            num = max(arr[i][j],num);
        }
    }
    return num;
}

void slide_left(int arr[][20],int result[][20]){
    for(int H=0; H<20; H++){
        int flag = -1,k = 0;
        for(int i=0;i<20;i++){
            if(arr[H][i] != 0){
                if(flag == -1){flag = arr[H][i];}
                else{
                    if( flag == arr[H][i]){result[H][k++] = flag*2;    flag = -1;}
                    else{result[H][k++] = flag;  flag = arr[H][i];}
                }
            }
        }
        if(flag != -1){result[H][k++] = flag;}
        while(k<20){result[H][k++] = 0;}
    }
}

void slide_right(int arr[][20],int result[][20]){
    for(int H=0;H<20;H++){
        int flag = -1, k = 19 ;
        for(int i=19; i>=0; i--){
            if(arr[H][i] != 0){
                if(flag == -1){flag = arr[H][i];}
                else{
                    if(flag == arr[H][i]){
                        result[H][k--] = flag*2;
                        flag = -1;
                    }
                    else{
                        result[H][k--] = flag;
                        flag = arr[H][i];
                    }
                }
            }
        }
        if(flag != -1){result[H][k--] = flag;}
        while(k>=0){result[H][k--] = 0;}
    }
}

void slide_down(int arr[][20],int result[][20]){
    for(int H=0;H<20;H++){
        int flag = -1, k = 19 ;
        for(int i=19; i>=0; i--){
            if(arr[i][H] != 0){
                if(flag == -1){flag = arr[i][H];}
                else{
                    if(flag == arr[i][H]){
                        result[k--][H]  = flag*2;
                        flag = -1;
                    }
                    else{
                        result[k--][H] = flag;
                        flag = arr[i][H];
                    }
                }
            }
        }
        if(flag != -1){result[k--][H] = flag;}
        while(k>=0){result[k--][H] = 0;}
    }
}


void slide_up(int arr[][20],int result[][20]){
    for(int H=0; H<20; H++){
        int flag = -1,k = 0;
        for(int i=0;i<20;i++){
            if(arr[i][H] != 0){
                if(flag == -1){flag = arr[i][H];}
                else{
                    if( flag == arr[i][H]){result[k++][H] = flag*2;    flag = -1;}
                    else{result[k++][H] = flag;  flag = arr[i][H];}
                }
            }
        }
        if(flag != -1){result[k++][H] = flag;}
        while(k<20){result[k++][H] = 0;}
    }
}

bool compare(int arr[][20],int arr2[][20]){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(arr[i][j] != arr2[i][j]) return false;
        }
    }
    return true;
}

void next_step(int arr[][20],int dep){
    if(dep == 10){
        MAX =  max(find_max(arr),MAX);
        return;
    }
    int now_max = find_max(arr);
    if(now_max * flags[dep] <= MAX) {return;}
    int temp[20][20];
    slide_right(arr,temp); 
    if(!compare(arr,temp)) next_step(temp,dep+1);
    slide_left(arr,temp);
    if(!compare(arr,temp)) next_step(temp,dep+1);
    slide_up(arr,temp);
    if(!compare(arr,temp)) next_step(temp,dep+1);
    slide_down(arr,temp);
    if(!compare(arr,temp)) next_step(temp,dep+1);
}


int main(){
    cin>>N;
    int arr[20][20] = {0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    next_step(arr,0);
    cout<<MAX<<"\n";
}