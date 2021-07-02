<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int>List[1005];
bool chuaxet[1005];

void DFS(int u) {
	chuaxet[u] = false;
	cout << u << " ";
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v]) DFS(v);
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
		DFS(u);
		cout << endl;
	}
=======
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int>List[1005];
bool chuaxet[1005];

void DFS(int u) {
	chuaxet[u] = false;
	cout << u << " ";
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v]) DFS(v);
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
		DFS(u);
		cout << endl;
	}
>>>>>>> a5a8a68f43ab1c7cb9911d2fd691dc08ddfa3520
}