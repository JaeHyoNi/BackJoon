#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> temp;
	if (n == 0) {
		cout << "0";
		exit(0);
	}
	if (n == 1) {
		cout << "1";
		exit()
	}
	while (n != 1) {
		if (n<0 && n % 2 != 0) {
			if (n == -1) {
				n = 1;
				temp.push(1);
				temp.push(1);
				break;
			}
			n -= 1;
			temp.push(1);
		}
		else {
			temp.push(n % -2);
		}
		n = n/ -2;
		if (n == 1) {
			temp.push(1);
			break;
		}
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
}