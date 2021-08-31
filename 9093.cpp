#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int num;
	stack<char> temp;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		getline(cin, str);
		auto iter = str.begin();
		while (iter != str.end()) {
			if (*iter != ' ') {temp.push(*iter);}
			if (*iter == ' ') { while (!temp.empty()) { cout << temp.top(); temp.pop(); }cout << " "; }
			iter++;
		}
		while (!temp.empty()) { cout << temp.top(); temp.pop(); }cout <<endl;
	}
}