#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a;
		vector<int> b;
		vector<int> giao;
		vector<int> hop;
		giao.resize(n + m);
		hop.resize(n + m);
		a.resize(n); b.resize(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		vector<int> ::iterator it;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), giao.begin());
		giao.resize(it - giao.begin());
		it = set_union(a.begin(), a.end(), b.begin(), b.end(), hop.begin());
		hop.resize(it - hop.begin());
		for (int i = 0; i < hop.size(); i++) cout << hop[i] << " ";
		cout << endl;
		for (int i = 0; i < giao.size(); i++) cout << giao[i] << " ";
		cout << endl;
	}
}