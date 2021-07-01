#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void xauNhiPhanTiep(int a[], int n) {
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i > 0) {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) {
			a[j] = 0;
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			a[j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	cout << endl;
}
int main() {
	int a[1005] = { 0 };
	vector<string>str;
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		string temp;
 		cin >> temp;
		str.push_back(temp);
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < str[i].length(); j++) {
			a[j] = str[i][j] - '0';
		}
		xauNhiPhanTiep(a, str[i].length());
	}
}