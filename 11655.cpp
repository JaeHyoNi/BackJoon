#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int x : str) {
		if (!isalpha(x)) cout << (char)x;
		else {
			if (isalpha(x) == 1) {
				x += 13;
				if (isalpha(x) != 1) {
					x -= 26;
				}
				cout << char(x);
			}
			else {
				x += 13;
				if (!isalpha(x))
					x -= 26;
				cout << char(x);
			}
		}
	}
}