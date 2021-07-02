#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[105], res[105];

bool kiemTra(int *a, int *res) {
	for (int i = 1; i <= n; i++) {
		if (a[i] != res[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		a[i] = temp;
		res[i] = temp;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i - 1; j++) {
			if (res[j] > res[j + 1]) {
				swap(res[j], res[j + 1]);
			}
		}
		cout << "Buoc " << i << ": ";
		for (int k = 1; k <= n; k++) {
			cout << res[k] << " ";
		}
		cout << endl;
		if (kiemTra(a, res)) {
			break;
		}
	}
}