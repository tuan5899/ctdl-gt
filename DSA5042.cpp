#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		long long* a = new long long [n + 5];
		long long* dp = new long long[n + 5];
		bool check = false;
		for (int i = 1; i <= n; i++) cin >> a[i];
		dp[1] = a[1];
		int dem = 2;
		for (int i = dem; i <= n; i++) {
			if (dp[i - 1] + a[i] < k) {
				dp[i] = dp[i - 1] + a[i];
			}
			else if (dp[i - 1] + a[i] == k) {
				dp[i] = dp[i - 1] + a[i];
				check = true;
				break;
			}
			else {
				i = dem++;
				dp[i] = a[i];
			}
		}
		if (check == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}