#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> d(n + 1);
	d.assign(n + 1, 99999);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i],min(a[i], d[i - j] + a[j]));
		}   
	}
	cout << d[n] << '\n';
	return 0;
}