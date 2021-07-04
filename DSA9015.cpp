#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

vector<int> List[1005];
bool chuaxet[1005];
bool check;
int n, m;
vector< pair <int, int> > res;

void DFS(int u, int t) {
	chuaxet[u] = false;
	for (int i = 0; i < List[u].size(); i++) {
		int v = List[u][i];
		if (chuaxet[v]) {
			DFS(v, u);
		}
		else if(v != t){
			pair<int,int> temp = { v,t };
			for (int j = 0; j < res.size(); j++) {
				if (temp == res[j]) check = true;
			}
		}
	}
}

void chutrinh() {
	check = false;
	for (int i = 1; i <= n; i++) {
		memset(chuaxet, true, sizeof(chuaxet));
		DFS(i, 0);
		if (check == true) {
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
		res.clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			res.push_back({ x,y });
			List[x].push_back(y);
		}
		chutrinh();
	}
}