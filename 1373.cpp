#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int two_ten(int num) {
	int result = 0, mul = 1;
	while (num > 0) {if (num % 2) result += mul;mul *= 2;num /= 10;}
	return result;
}

int main() {
	string str,temp;
	cin >> str;
	int n = str.size() % 3;
	if (n == 1)			{str = "00" + str;}
	else if (n == 2)	{ str = "0" + str; }
	auto iter = str.begin();
	while (iter != str.end()) {
		temp = "";
		for (int i = 0; i < 3; i++) {
			temp.push_back(*(iter++));
		}
		stringstream ss(temp);
		ss >> n;
		cout << oct << two_ten(n);
	}
}