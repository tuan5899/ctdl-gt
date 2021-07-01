#include<iostream>
#include<vector>
using namespace std;

int a[20] = { 0 };
int ok = 0;
int n, k;
vector<string>str;
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
	}
	ok = 0;
	str.clear();
}

void sinhNhiPhan() {
	int i = n;
	while (a[i] == 1) i--;
	if (i == 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j <= n; j++) a[j] = 0;
		int count = 0;
		for (int j = 1; j <= n; j++) {
			int temp = 0;
			while (j <= n && a[j] == 0) {
				temp++;
				j++;
			}
			if (temp == k) {
				count++;
			}
		}
		if (count == 1) {
			string s = "";
			for (int j = 1; j <= n; j++) {
				if (a[j] == 0) s += 'A';
				else s += 'B';
			}
			str.push_back(s);
		}
	}
}

int main() {
	init();
	if (n == k) {
		cout << 1 << endl;
		for (int i = 1; i <= n; i++) cout << 'A' << endl;
	}
	else {
		while (ok != 1) {
			sinhNhiPhan();
		}
		cout << str.size() << endl;
		for (int i = 0; i < str.size(); i++) {
			cout << str[i] << endl;
		}
	}
}