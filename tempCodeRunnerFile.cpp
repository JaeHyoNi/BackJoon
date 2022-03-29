#include <bits/stdc++.h>
using namespace std; 

int N, M, K;
vector<int> connect[100001];

int main(void) {
	int num,sc,from,to;
	double ans=0;
	cin >> N >> M >> K;
	vector<int> score(N+1, 0);
	vector<bool> is(N + 1, 0);
	for (int i = 0; i < M; i++) {
		cin >> num >> sc;
		score[num] = sc;
		is[num] = 1;
	}
	for (int i = 0; i < K; i++) {
		cin >> from >> to;
		connect[from].push_back(to);
		connect[to].push_back(from);
	}
	for (int i = 1; i < N + 1; i++) {
		if (is[i] == 1) continue;
		vector<bool> vis(N + 1, 0);
		int sum = 0, tmp = 0;
		queue<int> gogo;
		int K;
		for (auto t : connect[i]) {
			gogo.push(t);
		}
		while(!gogo.empty()){
			K = gogo.front();
			gogo.pop();
			vis[K] = 1;
			if (is[K] == 1) {
				sum = sum + score[K];
				tmp = tmp + 1;
			}
			for (auto t : connect[K]) {
				if (vis[t] == 0) {
					gogo.push(t);
				}
			}
		}
		if(tmp != 0)	sum = sum / tmp;
		score[i] = sum;
	}
	int tmp = 0;
	for (int i = 1; i < N + 1; i++) {
		ans = ans + score[i];
		if (score[i] != 0) tmp = tmp + 1;
	}
	printf("%.2f", ans / tmp);
}

// vector<int> arr; 
// int main() { 
//     int temp,N,C; 
//     scanf("%d %d",&N,&C);
//     for (int i = 0; i < N; i++) { 
//         scanf("%d",&temp); 
//         arr.push_back(temp); 
//     } 
//     sort(arr.begin(), arr.end()); 

//     int start = 1; 
//     int end = arr[N-1] - arr[0]; 
//     int result = 0; 
//     while (start <= end) { 
//         int mid = (start+end) / 2; 
//         int cnt = 1; 
//         int prev_house = arr[0]; 
//         for (int i = 1; i < N; i++) { 
//             if (arr[i] - prev_house >= mid) { 
//                 cnt++; 
//                 prev_house = arr[i]; 
//             } 
//         }  
//         if (cnt >= C) { 
//             result = max (result, mid); 
//             start = mid+1; 
//         }
//         else end = mid-1; 
//     } 
//     cout << result; 
//     return 0; 
// }

