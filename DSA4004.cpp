#include<iostream>
using namespace std;

long long solve(long long mid, long long k, long long n) {
	if (k % 2 == 1) return 1;
	else {
		long long x = (mid - 1) / 2;
		if (x + 1 == k) return n;
		if (x > k) return solve(x, k, n - 1);
		if (x < k)return solve(x, k - (x + 1), n - 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		long long F[2] = { 1 };
		for (int i = 0; i < n - 1; i++) {
			F[1] = F[0] * 2 + 1;
			F[0] = F[1];
		}
		cout << solve(F[0], k, n) << endl;
	}
}