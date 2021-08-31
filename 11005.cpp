#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<char> ans;
	int N, B,temp,mod;
	cin >> N >> B;
	while (N > B) {
		mod = N % B;
		if (mod >= 10) {
			ans.push((char)(mod + 55)); 
			printf("넣은값: %c\n", mod + 55);
		}
		else{
			printf("넣은값: %c\n", mod + 48);
			ans.push((char)(mod + 48));
		}
		N = floor(N / B);
	}
	if (N >= 10) {
		ans.push((char)(N + 55));
	}
	else {
		if (N != 0) {
			ans.push((char)(mod + 48));
		}
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}