#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main() {
	string str;
	getline(cin, str);
	stack<char> temp;
	string::iterator iter = str.begin();
	while (iter != str.end()) {
		if (*iter == '<') {
			while (*iter != '>') {
				cout << *iter;
				iter++;
			}
			cout << *iter++;
		}
		else if (*iter == ' ') {
			printf(" ");
			iter++;
		}
		else {
			while (iter != str.end() &&*iter != ' ' && *iter !='<') {
				temp.push(*iter);
				iter++;
			}
			while (!temp.empty()) {
				cout << temp.top();
				temp.pop();
			}
		}
	}

}