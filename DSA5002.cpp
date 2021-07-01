#include<iostream>
#include<cstring>
using namespace std;

int dp[105][105];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i - 1] == s[j - 1] && i - 1 != j - 1) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[n][n] << endl;
	}
}