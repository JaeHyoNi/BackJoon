#include<iostream>
#include<algorithm>
using namespace std;
 
#define N 9
#define MAX 100
int GetSum(const int *arr){
    int sum =0;
    for(int i=0; i<N; i++){
        sum += arr[i];
    }
    return sum;
}
int Solution(int *arr){
    int sum = GetSum(arr);
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(sum - (arr[i] + arr[j]) == MAX){
                arr[i] = -1;
                arr[j] = -1;
                return 0;
            }
        }
    }
    return -1;
}
int main(void){
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    Solution(arr); 
    sort(arr, arr+N);
    for(int i=2; i<N; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
