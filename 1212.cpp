#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	string ans = "";
	cin >> str;
	string arr[8] = { "000","001", "010", "011", "100", "101", "110","111" };
	auto iter = str.begin();
	while(iter!=str.end()){
		ans.append(arr[(*iter) - '0']);
		iter++;
	}
	int n = 0;
	auto iiter = ans.begin();
	int num = ans.size() - 1;
	while (iiter != ans.end()) {
		if (*iiter == '1') {
			cout << ans.substr(n, num - n + 1);
			exit(0);
		}
		else { n++; iiter++; }
	}
	cout << "0";
}