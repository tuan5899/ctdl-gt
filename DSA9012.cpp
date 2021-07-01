#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

vector<int>List[1005];
bool check[1005];

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
			List[y].push_back(x);
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				BFS(i);
				count++;
			}
		}
		for (int i = 1; i <= n; i++) {
			memset(check, true, sizeof(check));
			check[i] = false;
			int ncount = 0;
			for (int j = 1; j <= n; j++) {
				if (check[j]) {
					ncount++;
					BFS(j);
				}
			}
			if (ncount > count) cout << i << " ";
		}
		cout << endl;
	}
}