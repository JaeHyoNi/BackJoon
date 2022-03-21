/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N,S,tmp,sum=0;
    int ans = 9999;
    bool pass = false;
    cin>>N>>S;
    vector<long long> wait;
    for(int i=0;i<N;i++){
        cin>>tmp;
        wait.push_back(tmp);
    }
    sum = wait[0];
    int start=0,end=0;
    while(start <= end && end < N){
        if(sum < S){
            end = end + 1;
            sum = sum + wait[end];
        }
        else if(sum == S){
            ans = min(ans , end - start + 1);
            end = end + 1;
            sum = sum + wait[end];
            pass = true;
        }
        else if(sum > S){
            ans = min(ans , end - start +1);
            sum = sum - wait[start];
            start = start + 1;
            pass = true;
        }
        printf("S : %2d   E : %2d   sum = %3d ans : %3d\n",start,end,sum,ans); 
    }
    if(pass)    cout<<ans;
    else cout<<"0";
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001]; 
const int INF = 987654321;
int main(void) {
    int N, S;
    int length = INF;
    int low = 0; 
    int high = 0;
    int sum = 0;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    } 
    sum = arr[0];
    while (low <= high && high < N) { 
        if (sum < S){ 
            sum += arr[++high]; 
        } 
        else if(sum == S) { 
            length = min(length, (high - low + 1)); 
            sum += arr[++high]; 
        } 
        else if (sum > S) { 
            length = min(length, (high - low + 1)); 
            sum -= arr[low]; low++; 
        }
        printf("S : %2d   E : %2d   sum = %3d ans : %3d\n",low,high,sum,length); 
    } 
    if (length == INF)
        cout << 0 << endl; 
    else cout << length << endl; 
    return 0; 
}
