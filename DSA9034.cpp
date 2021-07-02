#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

int List[105][105];
bool chuaxet[105][105];
int x[] = { -1,-1,-1,0,0,1,1,1 };
int y[] = { -1,0,1,-1,1,-1,0,1 };

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

int main() {
	int n, m;
	cin >> n >> m;
	memset(List, 0, sizeof(List));
	memset(chuaxet, false, sizeof(chuaxet));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'W')List[i][j] = 1;
			chuaxet[i][j] = true;
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (List[i][j] && chuaxet[i][j]) {
				count++;
				BFS(i, j);
			}
		}
	}
	cout << count << endl;
}
