#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int>List[1005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= b; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		for (int i = 1; i <= a; i++) {
			cout << i << ": ";
			for (int j = 0; j < List[i].size(); j++) {
				cout << List[i][j] << " ";
			}
			cout << endl;
		}
	}
}