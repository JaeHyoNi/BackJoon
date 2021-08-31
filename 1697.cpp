#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	queue<pair<int, int>> visit;					// <방문번호 , 시간 >
	pair<int, int> temp;							// 임시페어
	visit.push(make_pair(n1, 0));					//초기값 집어넣음
	arr[n1] = 1;
	while (!visit.empty()) {
		temp = visit.front();					//큐 처음꺼 temp에 넣고
		visit.pop();							//temp에 들어간것은 제거

		if (temp.first == n2) {
			cout << temp.second;				//방문번호가 같으면 출력하고 끝
			break;
		}
		else
		{
			if (temp.first - 1 < 200000 && arr[(temp.first) - 1] == 0 && temp.first - 1 > -1) { // 방문번호 -되는거 검사 / 방문검사
				visit.push(make_pair((temp.first) - 1, (temp.second) + 1));						//해당되면 큐에 넣음
				arr[(temp.first) - 1] = 1;														//방문표시
			}
			if (temp.first + 1 < 200000 && arr[(temp.first) + 1] == 0) {
				visit.push(make_pair((temp.first) + 1, (temp.second) + 1));
				arr[(temp.first) + 1] = 1;		
			}
			if (temp.first * 2 < 200000 && arr[(temp.first) * 2] == 0) {
				visit.push(make_pair((temp.first) * 2, (temp.second) + 1));
				arr[(temp.first) * 2] = 1;

			}
		}

	}
}
