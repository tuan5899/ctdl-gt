#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long m[100000], n[100000], k[100000];

void solve() {
	long long M, N, K;
	cin >> M >> N >> K;
	vector<long long> vt;
	vector<long long> res;
	for (int i = 0; i < M; i++) cin >> m[i];
	for (int i = 0; i < N; i++) cin >> n[i];
	for (int i = 0; i < K; i++) cin >> k[i];
	int dem = 0;
	for (int i = 0; i < M && dem < N;) {
		if (m[i] == n[dem]) {
			vt.push_back(m[i]);
			i++;
			dem++;
		}
		else if (m[i] > n[dem]) {
			dem++;
		}
		else i++;
	}
	int dem2 = 0;
	for (int i = 0; i < vt.size() && dem2 < K;) {
		if (vt[i] == k[dem2]) {
			res.push_back(vt[i]);
			i++;
			dem2++;
		}
		else if (vt[i] > k[dem2]) {
			dem2++;
		}
		else i++;
	}
	if (res.size() > 0) {
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}