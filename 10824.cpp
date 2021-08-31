#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	string n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	n1 += n2;
	n3 += n4;
	cout << stoll(n1) + stoll(n3);
}