#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int a[15][15];
bool check[15][15];
vector<string>res;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	memset(check, 0, sizeof(check));
	res.clear();
}

void Try(int i, int j, string s) {
	if (a[1][1] == 0 || a[n][n] == 0) return;
	if (i == n && j == n) {
		res.push_back(s);
	}
	if (i < n && a[i + 1][j] && !check[i + 1][j]) {
		check[i][j] = true;
		Try(i + 1, j, s + 'D');
		check[i][j] = false;
	}
	if (i > 0 && a[i - 1][j] && !check[i - 1][j]) {
		check[i][j] = true;
		Try(i - 1, j, s + 'U');
		check[i][j] = false;
	}
	if (j < n && a[i][j + 1] && !check[i][j + 1]) {
		check[i][j] = true;
		Try(i, j + 1, s + 'R');
		check[i][j] = false;
	}
	if (j > 0 && a[i][j - 1] && !check[i][j - 1]) {
		check[i][j] = true;
		Try(i, j - 1, s + 'L');
		check[i][j] = false;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		string s = "";
		Try(1, 1, s);
		sort(res.begin(), res.end());
		if (res.empty()) cout << -1 << endl;
		else {
			for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
			cout << endl;
		}
	}
}