#include <bits/stdc++.h>
using namespace std;
int arr[500][500],M,N,B;

int calcul(int K){
	int temp_B = B, work = 0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] < K){
				work += (K-arr[i][j]);
				temp_B-= (K-arr[i][j]); 
			}
			else	{
				temp_B+= (arr[i][j]-K);
				work += 2*(arr[i][j] - K);
			}
		}
	}
	if(temp_B<0){return 2100000000;}
	return work;
}


int main(){
	int temp,work=2100000000,ans = 0,MIN=210000000,MAX=0;
	cin>>M>>N>>B;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			MIN = MIN < arr[i][j] ? MIN:arr[i][j];
			MAX = MAX > arr[i][j] ? MAX:arr[i][j];
		}
	}
	for(int i=MIN;i<=MAX;i++){
		temp = calcul(i);
		if(temp <= work){
			work = temp;
			ans = i;
		}
	}
	cout<<work<<" "<<ans;
}