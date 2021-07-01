#include<iostream>
#include<vector>
using namespace std;

int a[15][15];
int b[15];
int n, ok = 0, k;
vector< vector<int> > ans;
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) b[i] = i;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		temp += a[i][b[i]];
	}
	if (temp == k) {
		vector<int>v;
		v.clear();
		ans.clear();
		for (int i = 1; i <= n; i++) {
			v.push_back(b[i]);
		}
		ans.push_back(v);
	}
	ok = 0;
}

void sinhHoanVi() {
	int i = n - 1;
	while (b[i] > b[i + 1]) i--;
	if (i == 0) ok = 1;
	else {
		int j = n;
		while (b[j] < b[i])j--;
		swap(b[i], b[j]);
		int d = i + 1, c = n;
		while (d < c) {
			swap(b[d], b[c]);
			d++, c--;
		}
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += a[j][b[j]];
		}
		if (temp == k) {
			vector<int>v;
			v.clear();
			for (int i = 1; i <= n; i++) {
				v.push_back(b[i]);
			}
			ans.push_back(v);
		}
	}
}

int main() {
	init();
	while (ok != 1) {
		sinhHoanVi();
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}