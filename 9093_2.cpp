#include<iostream>
#include<string>
#include<stack> // 스택 부분 추가
using namespace std;
 
int main() {
 
	int T;
	cin >> T;
 
	cin.ignore();
 
	while (T--)
	{
		string str;
		getline(cin, str);
		str += '\n';
 
		stack<char>s;
 
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else if (str[i] != ' ')
			{
				s.push(str[i]);
			}
		}
 
		cout << '\n';
	}
	return 0;
}
