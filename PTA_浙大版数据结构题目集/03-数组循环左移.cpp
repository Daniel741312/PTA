#include<iostream>
#include<queue>
using namespace std;

int N = 0;
unsigned int m = 0;

int main() {
	int i = 0;
	int temp = 0;
	queue<int> q;
	cin >> N>>m;
	m = m % N;						//当m过大时

	/*读入数组*/
	for (i = 0; i < N; i++) {
		cin >> temp;
		q.push(temp);
	}


	/*进行循环移位*/
	while (m--) {
		q.push(q.front());
		q.pop();
	}

	/*Output*/
	cout << q.front();
	q.pop();

	for (i = 1; i < N; i++) {
		cout <<" "<<q.front();
		q.pop();
	}

	return 0;
}