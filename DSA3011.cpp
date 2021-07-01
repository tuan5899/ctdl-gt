#include<iostream>
#include<queue>
using namespace std;

long long a[2000005] = { 0 };
queue<long long> pq;
long long mod = 1e9 + 7;
long long n;

void init() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> a[i];
	while (pq.size() > 0) {
		pq.pop();
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		long long cost = 0;
		priority_queue < long long, vector<long long>, greater<long long> > pq(a, a + n);
		while (pq.size() > 1) {
			long long value1 = pq.top();
			pq.pop();
			long long value2 = pq.top();
			pq.pop();
			cost = (cost % mod + (value1 + value2) % mod) % mod;
			pq.push((value1 + value2) % mod);
		}
		cout << cost << endl;
	}
}