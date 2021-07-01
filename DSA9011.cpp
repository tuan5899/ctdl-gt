#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int>List[1005];
bool check[1005];

void DFS(int u) {
	check[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (check[v]) {
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
		int count = 0;
		memset(check, true, sizeof(check));
		for (int i = 0; i < 1005; i++) List[i].clear();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int temp;
				cin >> temp;
				if (temp == 1 && i != j) {
					List[i].push_back(j);
				}
				if (temp == 1 && i == j) {
					count++;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				count++;
				DFS(i);
			}
		}
		cout << count << endl;
	}
}