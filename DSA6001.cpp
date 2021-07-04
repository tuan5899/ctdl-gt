#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>a;
vector<int>b;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		a.resize(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end(), cmp);
		for (int i = 0, j = a.size() - 1; i <= j; i++, j--) {
			if (i == j) cout << a[i];
			else cout << a[i] << " " << a[j] << " ";
		}
		cout << endl;
	}
}