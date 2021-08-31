#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[2000000];

void make_prime(int n, vector<int>& prime,int fir) {
	int temp;
	while (1) {
		temp = fir;
		while (fir < n + 1) {
			if (arr[fir] == 0) { arr[fir] = 1; }
			fir += temp;
		}
		temp++;
		while (temp < n + 1) {
			if (arr[temp] == 0 || arr[temp]==2) {
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
	int num, ans=0;
	cin >> num;
	int n,temp,temp2, fir = 2;
	vector<int> prime;
	vector<int>::iterator iter;
	arr[2] = 2;
	
	for (int i = 0; i < num; i++) {
		cin >> temp;
		n = 0;
		if (temp > fir) {
			vector<int> tmp;
			tmp.push_back(2);
			make_prime(temp, tmp, 2);
			prime = tmp;
		}
		iter = prime.begin();
		if (arr[temp / 2] == 2) n++;
		while (*iter < temp / 2) {
			if (arr[temp - (*iter)] == 2) {
				n++;
			}
			iter++;
		}
		cout << n << "\n";
	}
}