#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, ok = 0;
int a[100], v[100];
vector< vector<int> >res;
void init() {
	res.clear();
	ok = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) a[i] = 0;
	sort(v + 1, v + n + 1);
}

void sinhNhiPhan() {
	int i = n;
	while (a[i] == 1) i--;
	if (i == 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j <= n; j++) a[j] = 0;
		bool check = false;
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j]) temp += v[j];
		}
		if (temp == k) {
			vector<int>x;
			for (int j = 1; j <= n; j++) {
				if (a[j]) x.push_back(v[j]);
			}
			res.push_back(x);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		while (ok != 1) {
			sinhNhiPhan();
		}
		if (res.size() == 0) cout << -1 << endl;
		else {
			sort(res.begin(), res.end());
			for (int i = 0; i < res.size(); i++) {
				cout << '[';
				for (int j = 0; j < res[i].size() - 1; j++) {
					cout << res[i][j] << ' ';
				}
				cout << res[i][res[i].size() - 1] << "] ";
			}
			cout << endl;
		}
	}
}
