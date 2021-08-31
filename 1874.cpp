#include <bits/stdc++.h>
using namespace std;

int main() {
	int num, i, j = 0, n = 1;
	cin >> num;
	stack<int> st;
	queue<char> qu;
	int* arr = new int[num];
	for (i = 1; i < num + 1; i++) {
		cin >> arr[j++];
	}
	i = 0;
	while (1) {
		while (arr[i] != n && n != num) {
			st.push(n);
			qu.push('+');
			n++;
		}
		i++;
		qu.push('+');
		qu.push('-');
		if (i == num)
			break;
		while (arr[i] < n) {
			if (arr[i] != st.top()) {
				cout << "NO";
				exit(0);
			}
			st.pop();
			qu.push('-');
			i++;
			if (i == num)
				break;
		}
		n++;
	}
	while (!qu.empty()) {
		cout << qu.front() << "\n";
		qu.pop();
	}
}