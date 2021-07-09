#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[25], b[25];
int n, s;
vector< vector<int> > res;
 void Try(int i, int sum, vector<int> v) {
	 if (sum > s) return;
	 if (sum == s) {
		 res.push_back(v);
		 return;
	 }
	 for (int j = i; j <= n; j++) {
		 if (sum + a[j] <= s) {
			 v.push_back(a[j]);
			 Try(j, sum + a[j], v);
			 v.pop_back();
		 }
	 }
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		vector<int>v;
		res.clear();
		Try(1, 0, v);
		if (res.size() == 0) {
			cout << -1 << endl;
		}
		else {
			cout << res.size() << " ";
			for (int i = 0; i < res.size(); i++) {
				cout << "{";
					for (int j = 0; j < res[i].size() - 1; j++) {
						cout << res[i][j] << " ";
					}
					cout << res[i][res[i].size() - 1] << "} ";
			}
			cout << endl;
		}
	}
}