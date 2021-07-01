#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

vector<int>List[1005];
int truoc[1005];
bool check[1005];

void Trace(int u, int v) {
	if (check[v]) {
		cout << -1 << endl;
	}
	else {
		vector<int>a;
		while (u != v) {
			a.push_back(v);
			v = truoc[v];
		}
		a.push_back(v);
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	}
}

void BFS(int u, int v) {
	check[u] = false;
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		if (!check[v]) return;
		int x = q.front(); q.pop();
		for (int i = 0; i < List[x].size(); i++) {
			int y = List[x][i];
			if (check[y]) {
				check[y] = false;
				q.push(y);
				truoc[y] = x;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m >> u >> v;
		for (int i = 0; i < 1005; i++) List[i].clear();
		memset(check, true, sizeof(check));
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		BFS(u, v);
		Trace(u, v);
	}
}