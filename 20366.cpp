#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end()); 
	int answer = INT_MAX;
	for (int i = 0; i < N - 3; ++i) {
		for (int j = i + 3; j < N; ++j) {
			int left = i + 1;
			int right = j - 1;
			while (left < right) {
                int st = arr[i] + arr[j];
                int en = arr[left] + arr[right];
				int result = en - st;
				answer = min(answer, abs(result)); 
				if (result > 0)  
					right = right - 1;
				else 
					left = left + 1;
			}
		}
	}
	cout << answer<<"\n";
}