#include <bits/stdc++.h>
using namespace std;

int main() {
	int num,i;
	string sen;
	int po=0, se=0;
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> sen;
		string::iterator iter = sen.begin();
		while (iter != sen.end()) {
			if (*iter == '(')	po++;
			if (*iter == ')')	po--;
			if (po < 0) {
				break;
			}
			iter++;
		}
		if (po == 0)	cout << "YES" << endl;
		else            cout << "NO"  << endl;
		po = 0; se = 0;
	}
}