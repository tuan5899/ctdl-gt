#include<iostream>

using namespace std;

int ok = 0, a[25] = { 0 }, n, k;
void in() {
	for (int i = 0; i < n; i++) cout << a[i];
	cout << endl;
}

void sinh() {
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i < 0) {
		ok = 1;
	}
	else {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) a[j] = 0;
		int check = 0;
		for (int i = 0; i < n; i++) if (a[i] == 1) check++;
		if (check == k) in();
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) a[i] = 0;
		ok = 0;
		while (ok != 1) {
			sinh();
		}
	}
}