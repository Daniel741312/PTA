#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*100000位的整数,远远超出了计算机数据类型的表示范围*/

int main() {
	int A = 0;						//题目里的A:1-9
	int N = 0;						//题目里的N:0-100000
	int i = 0;
	int temp = 0;					//本位和+进位的值
	int x = 0;						//本位
	int carry= 0;					//进位
	vector<int> v;

	cin >> A >> N;
	if (N == 0) {					//检查N值,N=0直接输出0返回
		cout << 0;
		return 0;
	}

	for (i = N; i >=0; i--) {
		temp = A * i+carry;
		x = temp % 10;
		carry = temp / 10;
		v.push_back(x);
	}

	reverse(v.begin(), v.end());	//逆序输出
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		/*
			*跳过前导0(前面至多会出现一个0)
			*当然更规矩的做法是在插入的时候判断,不过感觉这样更清晰
		*/
		if ((it == v.begin()) && (*it == 0))
			continue;
		cout << *it;
	}
	return 0;
}