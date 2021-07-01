#include<iostream>

using namespace std;

int ok = 0;
int a[15] = { 0 };
int n;
void generate() {
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i < 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) a[j] = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) cout << 'A';
			else cout << 'B';
		}
		cout << " ";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) a[i] = 0;
		ok = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) cout << 'A';
			else cout << 'B';
		}
		cout << " ";
		while (ok != 1) {
			generate();
		}
		cout << endl;
	}
}