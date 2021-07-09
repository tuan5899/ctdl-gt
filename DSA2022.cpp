#include<iostream>
#include<cstring>
using namespace std;

int a[20][20];
int res = INT_MAX;
bool check[20];
int n;

bool het(){
	for(int i = 1; i <= n; i++){
		if(!check[i]) return false;
	}
	return true;
}

void Try(int i, int sum) {
	for (int j = 1; j <= n; j++) {
		if (!check[j] && i != j) {
			check[j] = true;
			if (i == n && het()) {
				res = min(sum, res);
			}
			else Try(i + 1, sum + a[i][j]);
			check[j] = false;
		}
	}
}

int main() {
	cin >> n;
	memset(check, false, sizeof(check));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	Try(1, 0);
	cout << res << endl;
}
