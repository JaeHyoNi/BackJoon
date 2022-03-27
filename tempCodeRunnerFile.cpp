#include <bits/stdc++.h>
using namespace std; 

vector<int> arr; 
int main() { 
    int temp,N,C; 
    scanf("%d %d",&N,&C);
    for (int i = 0; i < N; i++) { 
        scanf("%d",&temp); 
        arr.push_back(temp); 
    } 
    sort(arr.begin(), arr.end()); 

    int start = 1; 
    int end = arr[N-1] - arr[0]; 
    int result = 0; 
    while (start <= end) { 
        int mid = (start+end) / 2; 
        int cnt = 1; 
        int prev_house = arr[0]; 
        for (int i = 1; i < N; i++) { 
            if (arr[i] - prev_house >= mid) { 
                cnt++; 
                prev_house = arr[i]; 
            } 
        }  
        if (cnt >= C) { 
            result = max (result, mid); 
            start = mid+1; 
        }
        else end = mid-1; 
    } 
    cout << result; 
    return 0; 
}

