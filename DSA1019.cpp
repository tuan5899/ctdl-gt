#include<iostream>

using namespace std;

int ok = 0;

void genarate(int n,int a[]) {
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i < 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) a[j] = 0;
		bool check = false;
		if (a[0] == 1 && a[n - 1] == 0) {
			for (int k = 0; k < n - 1; k++) {
				if (a[k] == a[k + 1] && a[k + 1] == 1) {
					check = true;
					break;
				}
			}
			if (check == false) {
				for (int k = 0; k < n; k++) {
					if (a[k] == 1) cout << 'H';
					else cout << 'A';
				}
				cout << endl;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[20];
		for (int i = 0; i < n; i++) a[i] = 0;
		ok = 0;
		while (ok != 1) {
			genarate(n,a);
		}
	}
}