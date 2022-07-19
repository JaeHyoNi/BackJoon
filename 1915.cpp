#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int main() {
	int N,M,MAX = 0; cin>>N>>M;
	string str; 
	for(int i=0;i<N;i++){
		cin>>str;
		for(int j=0;j<M;j++){
			arr[i][j] = str[j]=='0'? 0 : 1;
			if(arr[i][j]!=0){
				if(MAX == 0) MAX = 1;
				if(i-1>=0 && j-1>=0){
					if(arr[i-1][j]!=0 && arr[i][j-1]!=0 && arr[i-1][j-1]!=0){
						arr[i][j] = min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
						MAX = max(arr[i][j],MAX);
					}
				}
			}
		}
	}
	cout<<MAX*MAX;
}

