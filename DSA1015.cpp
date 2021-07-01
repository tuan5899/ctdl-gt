#include<iostream>

using namespace std;

string s;
bool pass = false;
int n;
int a[20] = { 0 };
int ok = 0;

int soChuSo() {
	int temp = n;
	int numOfN = 0;
	while (temp > 0) {
		temp /= 10;
		numOfN++;
	}
	return numOfN;
}

void init() {
	for (int i = 1; i < 18; i++) {
		a[i] = 0;
	}
	ok = 0;
	pass = false;
}

void sinhNhiPhan(int k) {
	int i = k;
	while (a[i] == 9) i--;
	if (i == 0) ok = 1;
	else {
		a[i] = 9;
		for (int j = i + 1; j <= k; j++) {
			a[j] = 0;
		}
		long long temp = 0;
		for (int j = 1; j <= k; j++) temp = temp * 10 + a[j];
		if (temp % n == 0) {
			pass = true;
			cout << temp << endl;
			ok = 1;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		int L = soChuSo();
		while (ok != 1) {
			sinhNhiPhan(L);
			if (pass != true && ok == 1) {
				init();
				L = L + 1;
			}
			if (pass == true) break;
		}
	}
}