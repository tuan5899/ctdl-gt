#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* a = new int[n + 5];
		int* dp = new int[n + 5];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[1] = a[1];
		int res = 0;
		for (int i = 2; i <= n; i++) {
			dp[i] = max(dp[i - 1] + a[i], a[i]);
			res = max(dp[i], res);
		}
		cout << res << endl;
	}
}