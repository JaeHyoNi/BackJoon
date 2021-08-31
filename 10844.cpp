#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000000;
long long arr[10][100];


int main() {
	int num;
	cin >> num;
	for (int i = 0; i < 10; i++) {arr[i][1] = 1;}
	for (int i = 2; i <num+1; i++) {
		arr[0][i] = arr[1][i - 1];
		arr[1][i] = (arr[0][i-1] + arr[2][i-1])%mod;
		arr[2][i] = (arr[1][i-1] + arr[3][i-1]) % mod;
		arr[3][i] = (arr[2][i-1] + arr[4][i-1]) % mod;
		arr[4][i] = (arr[3][i-1] + arr[5][i-1]) % mod;
		arr[5][i] = (arr[4][i-1] + arr[6][i-1]) % mod;
		arr[6][i] = (arr[5][i-1] + arr[7][i-1]) % mod;
		arr[7][i] = (arr[6][i-1] + arr[8][i-1]) % mod;
		arr[8][i] = (arr[7][i-1] + arr[9][i-1]) % mod;
		arr[9][i] = (arr[8][i - 1] ) % mod;
	}
	cout << (arr[1][num] + arr[2][num] + arr[3][num] + arr[4][num] + arr[5][num] + arr[6][num] + arr[7][num] + arr[8][num] + arr[9][num])%mod;
}
