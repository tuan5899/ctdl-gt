#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int n, m;
vector<int>List[1005];
bool chuaxet[1005];
bool check;

void DFS(int u, int t) {
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v])DFS(v, u);
		else if (v != t) check = true;
	}
}

void chutrinh() {
	check = false;
	for (int i = 1; i <= n; i++) {
		memset(chuaxet, true, sizeof(chuaxet));
		DFS(i, 0);
		if (check) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		chutrinh();
	}
}