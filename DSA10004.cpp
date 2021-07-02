#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int>List[1005];
bool chuaxet[1005];

void DFS(int u) {
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v]) {
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
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (chuaxet[i]) {
				DFS(i);
				count++;
			}
		}
		bool check = true;
		int dinhChan = 0, dinhLe = 0;
		for (int i = 1; i <= n; i++) {
			if (List[i].size() % 2 == 0 && List[i].size() != 0) {
				dinhChan++;
			}
			else if (List[i].size() % 2 != 0) {
				dinhLe++;
			}
		}
		if (count == 1 && dinhLe == 0) {
			cout << 2 << endl;
		}
		else if (count == 1 && dinhLe == 2) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
}