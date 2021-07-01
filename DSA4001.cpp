#include<iostream>

using namespace std;
int m = 1e9 + 7;
long long solve(long long n, long long k) {
	if (k == 0) return 1;
	long long x = solve(n, k / 2);
	if (k % 2 == 0) return x * x % m;
	return n * (x * x % m) % m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long k = n;
		long long sum = 0;
		int temp = 0;
		while (n > 0) {
			temp = n % 10;
			n = n / 10;
			sum = sum * 10 + temp;
		}
		n = k;
		cout << solve(n, sum) << endl;
	}
}