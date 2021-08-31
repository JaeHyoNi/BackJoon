#include <bits/stdc++.h>
using namespace std;

vector <string> mytoken = { "push", "pop", "size", "empty" , "top"};

int get_type(string w) {
	for (int i = 0; i < mytoken.size(); i++) {
		if (w == mytoken[i]) return(i);
	}
	return(-1);
}

int main() {
	stack<int> box;
	int num,i,temp,what;
	string doing;
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> doing;
		what = get_type(doing);
		switch (what)
		{
			case 0:
				cin >> temp;
				box.push(temp);
				break;
			case 1:
				if (box.empty()) cout << "-1\n";
				else {cout << box.top() << endl;  box.pop();}
				break;
			case 2:
				cout << box.size() << endl;
				break;
			case 3:
				cout << box.empty() << endl;
				break;
			case 4:
				if (box.empty())	cout << "-1\n";
				else
					cout << box.top() << endl;
		}
	}

}