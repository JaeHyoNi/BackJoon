#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
double arr[100];
int main() {
	int num, temp;
	double tmp1, tmp2;
	cin >> num;
	string str;
	cin >> str;
	vector<double> number;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		number.push_back(temp);
	}
	stack<double> cal;
	vector<double>::iterator iiter = number.begin();
	map<char, double> dic;
	string::iterator iter = str.begin();
	while (iter != str.end()) {
		if (isalpha(*iter)) {
			if (dic.count(*iter) == 0) {
				dic[*iter] = *iiter;
				cal.push(*iiter++);
			}
			else {
				cal.push(dic[*iter]);
			}
			iter++;
		}
		else {
			tmp2 = cal.top();
			cal.pop();
			tmp1 = cal.top();
			cal.pop();
			if (*iter == '+') {
				cal.push(tmp1 + tmp2);
			}
			else if (*iter == '-') {
				cal.push(tmp1 - tmp2);
			}
			else if (*iter == '*') {
				cal.push(tmp1 * tmp2);
			}
			else if (*iter == '/') {
				cal.push(tmp1 / tmp2);
			}
			tmp1 =cal.top();
			iter++;
		}
	}
	printf("%.2f", cal.top());
}