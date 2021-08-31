#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[20];

int fun(int n) {
	if (arr[n] != 0) return arr[n];
	else {
		if (arr[n - 1] == 0) { arr[n - 1] = fun(n - 1); }
		if (arr[n - 2] == 0) { arr[n - 2] = fun(n - 2); }
		if (arr[n - 3] == 0) { arr[n - 3] = fun(n - 3); }
		return arr[n - 1] + arr[n - 2] + arr[n - 3];
	}
}

int main() {
	int ans,num, temp;
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		ans = fun(temp);
		cout << ans<<"\n";
	}
}