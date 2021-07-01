#include<iostream>

using namespace std;
int n, m;
long long way = 0;
int a[105][105];
void Try(int i, int j){
	if(i == n && j == m && a[i][j] == 1){
		way++;
		return;
	}
	if(i < n) Try(i + 1, j);
	if(j < m) Try(i, j + 1);
	if(i > n || j > m) return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		way = 0;
		for(int i = 0; i < n*m; i++){
			int temp;
			cin >> temp;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				a[i][j] = 1;
			}
		}
		Try(1,1);
		cout << way << endl;
	}
}