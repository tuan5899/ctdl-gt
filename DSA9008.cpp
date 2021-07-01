#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

vector<int>List[1005];
bool check[1005];

void DFS(int u) {
	check[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (check[v]) {
			DFS(v);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(check, true, sizeof(check));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				count++;
				DFS(i);
			}
		}
		cout << count << endl;
	}
}