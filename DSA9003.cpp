#include<iostream>
#include<vector>
using namespace std;

vector<int>List[1005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			cout << i << ": ";
			for (int j = 0; j < List[i].size(); j++) {
				cout << List[i][j] << " ";
			}
			cout << endl;
		}
	}
}