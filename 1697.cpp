#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	queue<pair<int, int>> visit;					// <�湮��ȣ , �ð� >
	pair<int, int> temp;							// �ӽ����
	visit.push(make_pair(n1, 0));					//�ʱⰪ �������
	arr[n1] = 1;
	while (!visit.empty()) {
		temp = visit.front();					//ť ó���� temp�� �ְ�
		visit.pop();							//temp�� ������ ����

		if (temp.first == n2) {
			cout << temp.second;				//�湮��ȣ�� ������ ����ϰ� ��
			break;
		}
		else
		{
			if (temp.first - 1 < 200000 && arr[(temp.first) - 1] == 0 && temp.first - 1 > -1) { // �湮��ȣ -�Ǵ°� �˻� / �湮�˻�
				visit.push(make_pair((temp.first) - 1, (temp.second) + 1));						//�ش�Ǹ� ť�� ����
				arr[(temp.first) - 1] = 1;														//�湮ǥ��
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
