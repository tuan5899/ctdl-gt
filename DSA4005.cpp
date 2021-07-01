#include<iostream>

using namespace std;
char solve(long long n, long long k, long long F[]) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k == F[n - 2]) return solve(n - 2, k, F);
	if (k > F[n - 2]) return solve(n - 1, k - F[n - 2], F);
	if (k < F[n - 2]) return solve(n - 2, k, F);
}

int main() {
	long long F[93];
	F[0] = 0, F[1] = 1, F[2] = 1;
	for (int i = 3; i < 90; i++) {
		F[i] = F[i - 2] + F[i - 1];
	}
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		cout << solve(n, k, F) << endl;
	}
}