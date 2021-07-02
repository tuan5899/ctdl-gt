#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[25];
int ok = 0;

void init() {
	memset(a, 0, sizeof(a));
	ok = 0;
}

void sinh(int n) {
	int i = n;
	while (a[i] == 1) i--;
	if (i == 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j <= n; j++) a[j] = 0;
		string s = "";
		for (int i = 1; i <= n; i++) {
			s = s + char(a[i] + '0');
		}
		string copy = s;
		reverse(s.begin(), s.end());
		if (copy == s) {
			for (int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int n;
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	while (ok != 1) {
		sinh(n);
	}
}