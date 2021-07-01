#include<iostream>

using namespace std;

void solve(int n, int k, int a[], int b[]) {
	int i = k;
	while (a[i] == n - k + i) i--;
	if (i == 0) {
		cout << k << endl;
	}
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		int count = 0;
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++) {
				if (a[j] == b[l]) count++;
			}
		}
		cout << k - count << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, a[45], b[45];
		cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		solve(n, k, a, b);
	}
}