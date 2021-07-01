#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1005], F[1005] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		F[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) F[i] = max(F[i], F[j] + 1);
		}
		res = max(res, F[i]);
	}
	cout << res << endl;
}