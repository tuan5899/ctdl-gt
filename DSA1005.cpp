#include<iostream>

using namespace std;

int ok = 0;

void generate(int n, int a[]) {
	int i = n - 1;
	while (a[i] > a[i + 1]) i--;
	if (i == 0)ok = 1;
	else {
		int j = n;
		while (a[j] < a[i])j--;
		swap(a[i], a[j]);
		int d = i + 1, c = n;
		while (d < c) {
			swap(a[d], a[c]);
			d++, c--;
		}
		for (int l = 1; l <= n; l++) cout << a[l];
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[15];
		cin >> n;
		for (int i = 1; i <= n; i++) a[i] = i;
		for (int i = 1; i <= n; i++) cout << a[i];
		cout << " ";
		ok = 0;
		while (ok != 1) {
			generate(n, a);
		}
		cout << endl;
	}
}