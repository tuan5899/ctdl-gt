#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

vector<int>List[1005];
int check[1005];

void BFS(int u) {
	check[u] = false;
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < List[x].size(); i++) {
			int y = List[x][i];
			if (check[y]) {
				check[y] = false;
				q.push(y);
			}
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
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				count++;
				BFS(i);
			}
		}
		if (count >= 2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}