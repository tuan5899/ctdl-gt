#include<iostream>

using namespace std;

void generate(int n, int a[]) {
	int i = n - 1;
	while (a[i] > a[i + 1]) i--;
	if (i == 0) {
		for (int i = n; i > 0; i--) cout << a[i] << " ";
		cout << endl;
	}
	else {
		int j = n;
		while (a[j] < a[i]) j--;
		swap(a[i], a[j]);
		int d = i + 1, c = n;
		while (d < c) {
			swap(a[d], a[c]);
			d++, c--;
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[1005];
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		generate(n, a);
	}
}