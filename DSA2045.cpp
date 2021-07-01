#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ok = 0;
int a[20];
vector <string>ans;

void init() {
	for (int i = 0; i < 20; i++) a[i] = 0;
	ok = 0;
	ans.clear();
}

void sinhNhiPhan(string s) {
	int n = s.length();
	int i = n - 1;
	while (a[i] == 1) i--;
	if (i < 0) ok = 1;
	else {
		a[i] = 1;
		for (int j = i + 1; j < n; j++) {
			a[j] = 0;
		}
		string temp = "";
		for (int j = 0; j < n; j++) {
			if (a[j] == 1) {
				temp += s[j];
			}
		}
		if (temp != "") ans.push_back(temp);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		string s;
		cin >> s;
		while (ok != 1) {
			sinhNhiPhan(s);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << endl;
	}
}