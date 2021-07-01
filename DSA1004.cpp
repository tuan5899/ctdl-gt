#include<iostream>

using namespace std;

int ok = 0;

void generate(int n, int k, int a[]) {
	int i = k;
	while (a[i] == n - k + i) i--;
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		for (int l = 1; l <= k; l++) cout << a[l];
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, a[20];
		cin >> n >> k;
		for (int i = 1; i <= n; i++) a[i] = i;
		ok = 0;
		for (int i = 1; i <= k; i++) cout << a[i];
		cout << " ";
		while (ok != 1) {
			generate(n, k, a);
		}
		cout << endl;
	}
}