#include<iostream>

using namespace std;

int a[15], n, ok = 0;

void init() {
	a[0] = 0;
	string s;
	cin >> s;
	n = s.length();
	for (int i = 0; i < s.length(); i++) {
		a[i + 1] = int(s[i] - '0');
	}
	for (int i = 1; i <= n; i++) {
		cout << (a[i] xor a[i - 1]);
	}
	cout << endl;
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
			cout << a[i];
		}
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		//sinhNhiPhan();
	}
}