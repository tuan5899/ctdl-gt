#include<iostream>

using namespace std;

bool stop;
int n, k, a[100];

void init() {
	cin >> n;
	stop = 0;
	k = 1;
	a[k] = n;
}

void print() {
	for (int i = 1; i <= k; i++) {
		if (i == 1) cout << "(";
		cout << a[i];
		if (i < k) cout << " ";
		else cout << ") ";
	}
}

void sinh() {
	int i = k;
	while (i > 0 && a[i] == 1) i--;
	if (i == 0) stop = 1;
	else {
		a[i]--;
		int d = k - i + 1;
		k = i;
		for (int j = i + 1; j <= i + d / a[i]; j++) {
			a[j] = a[i];
		}
		k += d / a[i];
		if (d % a[i]) {
			a[++k] = d % a[i];
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		while (stop != 1) {
			print();
			sinh();
		}
		cout << endl;
	}
}