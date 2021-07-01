#include<iostream>
#include<queue>
using namespace std;

void solve() {
	long long n;
	cin >> n;
	int soLan7 = 0, soLan4 = 0;
	bool check = false;
	for (int i = n / 7; i >= 0; i--) {
		if ((n - 7 * i) % 4 == 0) {
			check = true;
			soLan7 = i;
			soLan4 = (n - 7 * i) / 4;
			break;
		}
	}
	if (check == true) {
		for (int i = 0; i < soLan4; i++) cout << 4;
		for (int i = 0; i < soLan7; i++) cout << 7;
		cout << endl;
	}
	else cout << -1 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}