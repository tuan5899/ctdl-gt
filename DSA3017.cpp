#include<iostream>
#include<queue>
using namespace std;

int a[50];


void init() {
	for (int i = 0; i < 50; i++) a[i] = 0;
}

void solve() {
	int k;
	string s;
	cin >> k >> s;
	for (int i = 0; i < s.length(); i++) {
		a[int(s[i] - '0')]++;
	}
	priority_queue<int , vector<int> > pq;
	for (int i = 0; i < 50; i++) {
		if (a[i] != 0) pq.push(a[i]);
	}
	while (k > 0) {
		int value = pq.top();
		pq.pop();
		value--;
		k--;
		pq.push(value);
	}
	long long sum = 0;
	while (pq.size() > 0) {
		int temp = pq.top();
		sum += temp * temp;
		pq.pop();
	}
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		solve();
	}
}