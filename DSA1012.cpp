#include<iostream>

using namespace std;

int a[15], n, ok = 0;

void init() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		a[i] = 0;
		if (i != n) cout << a[i];
	}
	cout << " ";
	ok = 0;
}

void sinhNhiPhan() {
	int i = n;
	while (a[i] == 1) i--;
	if (i == 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			a[j] = 0;
		}
		int gray[15];
		for (int i = 1; i <= n; i++) {
			gray[i] = a[i] xor a[i - 1];
			cout << gray[i];
		}
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		while (ok != 1) {
			sinhNhiPhan();
		}
		cout << endl;
	}
}