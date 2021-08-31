#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int num = 0, B;
	string N;
	cin >> N >> B;
	auto iter = N.rbegin();
	int size = N.size(),temp=1;
	for (int i = 0; i < size; i++) {
		if ((*iter) > 64) {
			num = num + temp * (int)((*iter) - 55);
		}
		else {
			num = num + temp * (int)((*iter) - 48);
		}
		temp *= B;
		iter++;
	}

	cout << num;
}