#include<iostream>

using namespace std;
long long mod = 123456789;
long long solve(long long k, long long n) {
	if (n == 0) return 1;
	long long x = solve(2, n / 2);
	if (n % 2 == 0) return x * x % mod;
	return 2 * (x * x % mod) % mod;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << solve(2, n - 1) << endl;
	}
}