#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

vector<int>List[1005];
bool chuaxet[1005];
int truoc[1005];

void DFS(int u, int v) {
	if (chuaxet[v] == false) return;
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int y = List[u][i];
		if (chuaxet[y]) {
			DFS(y, v);
		}
	}
}

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
			List[y].push_back(x);
		}
		int test;
		cin >> test;
		while (test--) {
			memset(chuaxet, true, sizeof(chuaxet));
			int u, v;
			cin >> u >> v;
			DFS(u, v);
			if (chuaxet[v]) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
}