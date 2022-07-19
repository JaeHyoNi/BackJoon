#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    vector<pair<int,int>> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i].second>>arr[i].first;
    sort(arr.begin(),arr.end());
	int time = arr[0].first;
	int count = 1;
	for (int i=1;i<N;i++) {
		if (time <= arr[i].second ){
			count++;
			time = arr[i].first;
		}
	}
    cout<<count;
}