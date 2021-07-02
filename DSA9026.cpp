#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

vector<int>List[1005];
bool chuaxet[1005];
int truoc[1005];

void BFS(int u, int v){
	chuaxet[u] = false;
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < List[x].size(); i++) {
			int y = List[x][i];
			if (chuaxet[y]) {
				chuaxet[y] = false;
				truoc[y] = x;
				q.push(y);
			}
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
		BFS(u, v);
		Trace(u, v);
	}
}