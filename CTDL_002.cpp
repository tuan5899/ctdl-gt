#include<iostream>
using namespace std;
int ok = 0;
int soLan = 0;
void generate(int n, int k, int a[], int b[]) {
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i < 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) a[j] = 0;
		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] == 1) {
				temp = temp + b[j];
			}
		}
		if (temp == k) {
			for (int j = 0; j < n; j++) {
				if (a[j] == 1) cout << b[j] << " ";
			}
			cout << endl;
			soLan++;
		}
	}
}

int main() {
	int n, k;
	int a[20], b[20];
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) a[i] = 0;
	ok = 0;
	while (ok != 1) {
		generate(n, k, a, b);
	}
	cout << soLan;
}