#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//char str[101];
int main() {
	string str;
	cin >> str;
	stack<char> temp;
	int sta = 0;
	for (char x : str) {
		if (isalpha(x)) cout << x;
		else if (x == '(') {temp.push(x);}
		else if (x == ')') {
			while (temp.top() != '(') {
				cout << temp.top();
				temp.pop();
			}
			temp.pop();
		}
		else if (x == '*' || x == '/') {
			if (!temp.empty()) {
				if (temp.top() == '*' || temp.top() == '/') {
					cout << temp.top();
					temp.pop();
				}
			}
			temp.push(x);
		}
		else {
			if (!temp.empty() &&(temp.top() == '*' || temp.top() == '/')) {
				while (!temp.empty() && temp.top() != '(') {
					cout << temp.top();
					temp.pop();
				}
			}
			else if (!temp.empty() && (temp.top() == '+' || temp.top() == '-')) {
				cout << temp.top();
				temp.pop();
			}
			temp.push(x);
		}
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
}