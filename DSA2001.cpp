#include<iostream>

using namespace std;

void quayLui(int n,int a[],int b[], int k) {
	for (int i = k + 1; i < n; i++) {
		b[i] = a[i] + a[i - 1];
	}
	for (int i = 0; i < n; i++) a[i] = b[i];
	if(k + 1 <= n - 1)cout << "[";
	for (int i = k + 1; i < n - 1; i++) {
		cout << b[i] << " ";
	}
	if (k + 1 <= n - 1) {
		cout << b[n - 1] << "]";
		cout << endl;
	}
	if (k == n)return;
	else {
		quayLui(n, a, b, k + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[15], b[15];
		cin >> n;
		int k = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
		quayLui(n, a, b, k);
	}
}