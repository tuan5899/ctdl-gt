#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* a = new int[n];
		int k = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			k += a[i];
		}
		if (k % 2 == 1) cout << "NO" << endl;
		else {
			int s = k / 2;
			int* dp = new int[s + 1];
			for (int i = 0; i < s + 1; i++) {
				dp[i] = 0;
			}
			dp[0] = 1;
			for (int i = 0; i < n; i++) {
				for (int j = s; j >= a[i]; j--) {
					if (dp[j - a[i]] == 1) {
						dp[j] = 1;
					}
				}
			}
			if (dp[s] == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
