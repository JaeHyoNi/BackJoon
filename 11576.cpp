#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main() {
	int A, B, n, num=0, temp,mod;
	string N;
	stack<int> ans;
	cin >> A >> B;
	cin >> n;
	int temp2 = n-1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		num += temp*(int)pow(A, temp2--);
	}
	while (num >= B) {
		mod = num % B;
		ans.push(mod);
		num = floor(num / B);
	}
	ans.push(num);
	while (!ans.empty()) {
		cout << ans.top()<<" ";
		ans.pop();
	}
}