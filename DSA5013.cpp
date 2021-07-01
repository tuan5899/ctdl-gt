#include<iostream>

using namespace std;

long long mod = 1e9 + 7;
long long res[100005];


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		res[1] = 1;
		for (int i = 1; i <= k; i++) res[i] = 1;
		for (int i = k + 1; i <= n; i++) res[i] = 0;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j < i; j++) {
				res[i] += res[j];
				res[i] = res[i] % mod;
			}
		}
		for (int i = k + 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				res[i] += res[i - j] % mod;
				res[i] %= mod;
			}
		}
		cout << res[n] << endl;
	}
}