#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ok = 0, n, k;	
int a[20];
vector<string>ans;
void init() {
	cin >> n >> k;
	string temp = "";
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= k; i++) {
		temp += char('A' + i - 1);
	}
	ok = 0;
	ans.clear();
	ans.push_back(temp);
}

void solve() {
	int i = k;
	while (a[i] == n - k + i) i--;
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
		string temp = "";
		for (int j = 1; j <= k; j++) {
			temp += char('A' + a[j] - 1);
		}
		ans.push_back(temp);
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		while (ok != 1) {
			solve();
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
}