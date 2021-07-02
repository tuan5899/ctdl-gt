#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

vector<int>List[1005];
bool chuaxet[1005];
bool check;
int n;

void DFS(int u, int t) {
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v]) {
			DFS(v, u);
		}
		else if (v != t) {
			check = true;
		}
	}
}

void chutrinh() {
	check = false;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (chuaxet[i]) {
			DFS(i, 0);
			res++;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(chuaxet, true, sizeof(chuaxet));
		DFS(i, 0);
	}
	if (res == 1 && !check) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(chuaxet, true, sizeof(chuaxet));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		chutrinh();
	}
}