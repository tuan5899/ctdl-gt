#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct dat{
	int first, second, i;
};

bool cmp(dat a, dat b) {
	if (a.second == b.second) return a.i < b.i;
	return a.second < b.second;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<dat> res;
		res.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> res[i].first;
			res[i].second = abs(res[i].first - x);
			res[i].i = i;
 		}
		sort(res.begin(), res.end(), cmp);
		for (int i = 0; i < n; i++) cout << res[i].first << " ";
		cout << endl;
	}
}