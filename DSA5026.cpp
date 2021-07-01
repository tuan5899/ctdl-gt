#include<iostream>
#include<cstring>;
#include<vector>
using namespace std;

int dp[1005][1005];
struct object {
	int volume = 0;
	int value = 0;
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, v;
		vector<object>a;
		cin >> n >> v;
		a.resize(n + 5);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) cin >> a[i].volume;
		for (int i = 1; i <= n; i++) cin >> a[i].value;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= v; j++) {
				if (j < a[i].volume) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j],
					dp[i - 1][j - a[i].volume] + a[i].value);
				res = max(res, dp[i][j]);
			}
		}
		cout << res << endl;
	}
}