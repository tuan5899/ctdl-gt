#include<iostream>

using namespace std;
int a[1005], n, k;

void init() {
	for (int i = 0; i <= 1004; i++) {
		a[i] = 10000;
	}
}

bool check() {
	for (int i = 1; i <= k; i++) {
		if (a[i] != i) return false;
	}
	return true;
}

void solve() {
	if (check()) {
		for (int i = 1; i <= k; i++) {
			cout << n - k + i << " ";
		}
		cout << endl;
	}
	else {
		int i = k;
		while (a[i] == a[i - 1] + 1) i--;
		a[i]--;
		for (int j = i + 1; j <= k; j++) {
			a[j] = n - k + j;
		}
		for (int j = 1; j <= k; j++) cout << a[j] << " ";
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		cin >> n >> k;
		for (int i = 1; i <= k; i++) cin >> a[i];
		solve();
	}
}