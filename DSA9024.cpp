#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

vector<int>List[1005];
bool chuaxet[1005];

void BFS(int u) {
	chuaxet[u] = false;
	cout << u << " ";
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < List[x].size(); i++) {
			int v = List[x][i];
			if (chuaxet[v]) {
				q.push(v);
				cout << v << " ";
				chuaxet[v] = false;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, u;
		cin >> n >> m >> u;
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		BFS(u);
		cout << endl;
	}
}