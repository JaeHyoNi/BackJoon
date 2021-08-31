#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	char arr1[18] = { '1','-','3','-','5','-','7','-','1','0','-','1','3','-','1','6','-' };
	char arr2[18] = { '-','2','-','4','-','6','-','8','-','1','1','-','1','4','-','1','7' };
	int T;
	int a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		long long temp = a * pow(10, b);
		if (temp >= 21) {
			a = 17;
		}
		else {
			a = temp;
		}
		while (temp > 0) {
			temp = temp - 1 - floor(log10(temp) + 1);
		}
		if (temp == 0) {
			for (int j = 0; j < a; j++)
				cout << arr2[j];
			cout << endl;
		}
		else {
			for (int j = 0; j < a; j++) {
				cout << arr1[j];
			}
			cout << endl;
		}
	}
}
