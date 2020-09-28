#include<iostream>
#include<vector>
using namespace std;

int MaxSubSeqSum1(vector<int>& v);
int MaxSubSeqSum2(vector<int>& v);
int MaxSubSeqSum3(vector<int>& v);
int MaxSubSeqSum4(vector<int>& v);
int Max3(int a, int b, int c);
int DivideAndConquer(vector<int>& v, int left, int right);

int N = 0;

int main() {
	int i = 0;
	int temp=0;
	int maxSum = 0;

	cin >> N;
	vector<int> v;
	for (i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	maxSum = MaxSubSeqSum3(v);
	cout << maxSum;
	return 0;
}


/*憨憨解法(我就是那个憨憨)*/
int MaxSubSeqSum1(vector<int>& v) {
	int thisSum = 0;
	int maxSum = 0;
	for (vector<int>::iterator it1 = v.begin(); it1 != v.end();it1++) {
		for (vector<int>::iterator it2 = it1; it2 != v.end();it2++) {
			thisSum = 0;
			for (vector<int>::iterator it3 = it1; it3 != it2;it3++) {
				thisSum += *it3;
				if (thisSum > maxSum)
					maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

/*常规解法:算法1中最内层循环根本没必要,终点一边向后移动一边计算thisSum*/
int MaxSubSeqSum2(vector<int>& v){
	int thisSum = 0;
	int maxSum = 0;
	for (vector<int>::iterator it1 = v.begin(); it1 != v.end(); it1++) {
		thisSum = 0;
		for (vector<int>::iterator it2 =it1; it2 != v.end(); it2++) {
			thisSum += *it2;
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

/*分而治之(不好理解还不是最优)*/
int DivideAndConquer(vector<int>& v, int left, int right) {
	int MaxLeftSum, MaxRightSum;				//存放左右子问题的解
	int MaxLeftBorderSum, MaxRightBorderSum;	//存放跨分界线的结果
	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) {
		if (v[left] > 0)
			return v[left];
		else
			return 0;
	}

	center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(v, left, center);
	MaxRightSum = DivideAndConquer(v, center + 1, right);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = center; i >= left; i--) {
		LeftBorderSum += v[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) {
		RightBorderSum += v[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubSeqSum3(vector<int>& v){
	return DivideAndConquer(v,0,N-1);
}

int Max3(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

/*在线处理:O(N)复杂度*/
int MaxSubSeqSum4(vector<int>& v){
	int thisSum = 0;
	int maxSum = 0;
	for (vector<int>::iterator it1 = v.begin(); it1 != v.end(); it1++) {
		thisSum += *it1;
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}
