#include<iostream>
using namespace std;

#if 0
int main() {
	int left = 0;
	int right = 0;
	char myOperator;
	cin >> left;

	while (cin >> myOperator && myOperator != '=') {
		cin >> right;
		switch (myOperator) {
			case '+':
				left += right;
				break;
			case '-':
				left -= right;
				break;
			case '*':
				left *= right;
				break;
			case '/':{
				if (right == 0) {
					cout << "ERROR";
					return 0;
				}
				else
					left /= right;
				break;
			}
			default:
				cout << "ERROR";
				return 0;
		}
	}
	cout << left;
	return 0;
}
#endif