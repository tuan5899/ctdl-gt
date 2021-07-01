#include<iostream>
using namespace std;

void generate(int n, int k, int a[]) {
	int i = k;
	while (a[i] == n - k + i) i--;
	if (i == 0) for (int i = 1; i <= k; i++) cout << i << " ";
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		for (int l = 1; l <= k; l++) cout << a[l] << " ";
		cout << endl;
	}
}

int main() {
	int t, n, k, a[1005];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) a[i] = i;
		for (int i = 1; i <= k; i++) cin >> a[i];
		generate(n, k, a);
	}
}