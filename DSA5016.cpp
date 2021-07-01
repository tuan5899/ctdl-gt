#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long sang(long long n) {
	long long *ugly = new long long [n];
	long long i1 = 0, i2 = 0, i3 = 0;
	ugly[0] = 1;
	for (int i = 1; i < n; i++) {
		ugly[i] = min(ugly[i1] * 2,min( ugly[i2] * 3, ugly[i3] * 5));
		if (ugly[i] == ugly[i1] * 2)
			i1++;
		if (ugly[i] == ugly[i2] * 3)
			i2++;
		if (ugly[i] == ugly[i3] * 5)
			i3++;
	}
	return ugly[n - 1];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << sang(n) << endl;
	}
}