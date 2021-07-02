#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

vector<int>List[100005];
bool chuaxet[100005];
int n, m;

void BFS(int u) {
	chuaxet[u] = false;
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < List[x].size(); i++) {
			int v = List[x][i];
			if (chuaxet[v]) {
				q.push(v);
				chuaxet[v] = false;
			}
		}
	}
}

void TPLT() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(chuaxet, true, sizeof(chuaxet));
		BFS(i);
		int dem = 0;
		for (int j = 1; j <= n; j++) {
			if (!chuaxet[j]) {
				dem++;
			}
		}
		res = max(res, dem);
	}
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 100005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		TPLT();
	}
}