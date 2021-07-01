#include<iostream>

using namespace std;

int ok = 0;

void solve(string s, int a[]) {
	int n = s.length();
	int i = n - 1;
	while (a[i] > a[i + 1]) i--;
	if (i == 0) {
		ok = 1;
	}
	else {
		int j = n;
		while (a[j] < a[i])j--;
		swap(a[i], a[j]);
		int d = i + 1, c = n;
		while (d < c) {
			swap(a[d], a[c]);
			d++, c--;
		}
		for (int k = 1; k <= n; k++) {
			cout << s[a[k] - 1];
		}
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int* a = new int[s.length() + 1];
		for (int i = 1; i <= s.length(); i++) {
			a[i] = i;
		}
		ok = 0;
		cout << s << " ";
		while (ok != 1) {
			solve(s, a);
		}
		cout << endl;
	}
}