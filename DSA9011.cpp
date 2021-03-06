#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int List[505][505];
bool chuaxet[505][505];
int x[] = { 0,0,1,1,1,-1,-1,-1 };
int y[] = { 1,-1,0,-1,1,0,1,-1 };

void BFS(int u, int v) {
	queue< pair<int, int> > q;
	q.push({ u,v });
	chuaxet[u][v] = false;
	while (!q.empty()) {
		pair<int, int> k = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			int a = k.first + x[i];
			int b = k.second + y[i];
			if (List[a][b] == 1 && chuaxet[a][b]) {
				chuaxet[a][b] = false;
				q.push({ a,b });
			}
		}
	}
}

void TPLT() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chuaxet[i][j] && List[i][j]) {
				res++;
				BFS(i, j);
			}
		}
	}
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> List[i][j];
				chuaxet[i][j] = true;
			}
		}
		TPLT();
	}
}