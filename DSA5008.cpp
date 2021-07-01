#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		int a[50000] = { 0 };
		int temp;
		a[0] = 1;
		for (int i = 1; i <= n; i++) {
			cin >> temp;
			a[temp] = 1;
			for (int j = s; j >= temp; j--) {
				if (a[j - temp] == 1) a[j] = 1;
			}
		}
		if (a[s] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}