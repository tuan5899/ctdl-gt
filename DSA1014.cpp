#include<iostream>

using namespace std;
int ok = 0;
int soLuong = 0;
void solve(int n, int k, int a[], int s) {
	int i = k;
	while (a[i] == n - k + i) i--;
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		int temp = 0;
		for (int j = 1; j <= k; j++) {
			temp += a[j];
		}
		if (temp == s)soLuong++;
	}
}

int main() {
	int n, k, s;
	cin >> n >> k >> s;
	while (n != 0 && k != 0 && s != 0) {
		if (k > n) {
			cout << 0 << endl;
			cin >> n >> k >> s;
		}
		else {
			int a[25];
			ok = 0;
			int temp = 0;
			soLuong = 0;
			for (int i = 1; i <= k; i++) {
				a[i] = i;
				temp += i;
			}
			if (temp == s) soLuong++;
			while (ok != 1) {
				solve(n, k, a, s);
			}
			cout << soLuong << endl;
			cin >> n >> k >> s;
		}
	}
}