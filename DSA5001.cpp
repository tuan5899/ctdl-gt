#include<iostream>

using namespace std;

int a[1005][1005];
void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			a[i][j] = 0;
		}
	}
	int res = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
			else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			res = max(res, a[i][j]);
		}
	}
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

