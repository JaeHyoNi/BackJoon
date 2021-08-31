#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;




bool comp(const string& s1, const string& s2) {
	if (s1 == s2) {
		return s1.size() < s2.size();
	}
	return s1 < s2;
}
int main() {
	vector<string> arr;
	string str;
	cin >> str;
	int size = str.size(), i = 0;
	for (i = 0; i < size; i++) {
		arr.push_back(str.substr(i, size - i));
	}
	sort(arr.begin(), arr.end(), comp);
	for (string x : arr) {
		cout << x << "\n";
	}
}