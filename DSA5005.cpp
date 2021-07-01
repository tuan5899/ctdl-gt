#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[1005], dp[1005], res = 0;
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}
		cout << n - res << endl;
	}
}