#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A;
	string B;
	
	cin >> A >> B;
	cout << A*(B[2] - '0')<< endl;
	cout << A*(B[1] -'0') << endl;
	cout << A*(B[0] -'0') << endl;
	cout << A * stoi(B) << endl;
	
	return 0;
	
}
