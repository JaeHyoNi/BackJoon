#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <char> mytoken = { 'push', 'pop', 'size', 'empty','front','back' };

int get_type(char w) {
	for (int i = 0; i < 4; i++) {
		if (w == mytoken[i]) return(i);
	}
	return(-1);
}

int main() {
	char first[600000], what,temp;
	scanf("%s", first);
	stack<char> left, right;
	int m = 0, n = strlen(first);
	for (int i = 0; i < n; i++) {
		left.push(first[i]);
	}
	scanf("%d", &m);
	while (m > 0) {
		m--;
		scanf(" %c", &what);
		int choose = get_type(what);
		switch (choose) {
		case 0:
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 1:
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case 2:
			if (!left.empty()) {
				left.pop();
			}
			break;
		case 3:
			scanf(" %c", &temp);
			left.push(temp);
			break;
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	return 0;
}