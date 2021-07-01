#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool chuaxet[1005];
vector<int>List[1005];
int truoc[1005];
void Trace(int u, int v) {
	if (chuaxet[v]) {
		cout << -1;
		return;
	}
	vector<int>a;
	while (u != v) {
		a.push_back(u);
		u = truoc[u];
	}
	a.push_back(v);
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

void DFS(int u, int v) {
	if (!chuaxet[v]) return;
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int a = List[u][i];
		if (chuaxet[a]) {
			truoc[a] = u;
			DFS(a, v);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, nguon , dich;
		cin >> a >> b >> nguon >> dich;
		memset(chuaxet, true, sizeof(chuaxet));
		memset(truoc, 0, sizeof(truoc));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= b; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		DFS(nguon, dich);
		Trace(dich, nguon);
		cout << endl;
	}
}