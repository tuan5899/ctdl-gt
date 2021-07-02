#include<iostream>
#include<vector>
#include<cstring>

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
			truoc[y] = u;
			DFS(y, v);
		}
	}
}

void Trace(int u, int v) {
	if (chuaxet[v]) {
		cout << -1 << endl;
		return;
	}
	else {
		vector<int>a;
		while (v != u) {
			a.push_back(v);
			v = truoc[v];
		}
		a.push_back(v);
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m >> u >> v;
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		DFS(u, v);
		Trace(u, v);
	}
}