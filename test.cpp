#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> a;
	vector< vector<int> > res;
	int n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a.clear();
		for (int i = 0; i < n; i++) {
			int temp = 0;
			a.push_back(temp);
		}
		res.push_back(a);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) cout << res[i].size() << " ";
}