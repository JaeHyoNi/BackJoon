#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
	int temp, n;
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}


int main() {
	int s, n, s1, s2, s3;
	cin >> n >> s;
	int* arr = new int[n];
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr2[i] = abs(s - arr[i]);
	}
	for (int i = 0; i < n-1; i++) {
		arr2[i + 1] = gcd(arr2[i], arr2[i + 1]);
	}
	cout << arr2[n - 1];

}