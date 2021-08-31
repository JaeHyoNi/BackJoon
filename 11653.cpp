#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[20000000];

void make_prime(int n, vector<int>& prime, int fir) {
	int temp;
	while (1) {
		temp = fir;
		while (fir < n + 1) {
			if (arr[fir] == 0) { arr[fir] = 1; }
			fir += temp;
		}
		temp++;
		while (temp < n + 1) {
			if (arr[temp] == 0 || arr[temp] == 2) {
				fir = temp;
				arr[fir] = 2;
				prime.push_back(fir);
				break;
			}
			temp++;
		}
		if (temp > n)  break;
	}
}
int main() {
	int num;
	cin >> num;
	if (num == 1) exit(0);
	vector<int> prime;
	prime.push_back(2);
	make_prime(num, prime, 2);
	auto iter = prime.begin();
	while (num != 1) {
		if (num % (*iter) == 0) {
			num = num / (*iter);
			cout << *iter << "\n";
		}
		else iter++;
	}
}