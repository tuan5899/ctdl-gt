#include<iostream>

using namespace std;

int binarySearch(int x, int l, int r, int a[]) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) return binarySearch(x, l, mid - 1, a);
		return binarySearch(x, mid + 1, r, a);
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int* a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		int ans = binarySearch(x, 0, n - 1, a);
		if (ans == -1)cout << "NO" << endl;
		else cout << ans + 1 << endl;
	}
}