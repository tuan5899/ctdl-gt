#include<iostream>

using namespace std;

int res = INT_MAX;

void Try(int n) {
	int ans = 0;
	if (n == 1) {
		res = min(res, ans);
	}
	else if ((n - 1) % 3 == 0 && n > 0) {
		ans++;
		cout << n << endl;
		Try(n - 1);
		ans--;
	}
	else if (n % 3 == 0 && n  > 0) {
		ans++;
		cout << n << endl;
		Try(n / 3);
		ans--;
	}
	else if ((n - 1) % 2 == 0 && n > 0) {
		ans++;
		cout << n << endl;
		Try(n - 1);
		ans--;
	}
	else if (n % 2 == 0 && n > 0) {
		ans++;
		cout << n << endl;
		Try(n / 2);
		ans--;
	}
	else if( n > 0){
		ans++;
		cout << n << endl;
		Try(n - 1);
		ans--;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		res = 0;
		Try(n);
		cout << res << endl;
	}
}