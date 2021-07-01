#include<iostream>
#include<algorithm>
using namespace std;

struct task {
	int start, finish;
};

task st[1005];

bool cmp(task a, task b) {
	return a.finish < b.finish;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> st[i].start;
		}
		for (int i = 0; i < n; i++) {
			cin >> st[i].finish;
		}
		sort(st, st + n, cmp);
		int count = 1, i = 0;
		for (int j = 1; j < n; j++) {
			if (st[j].start >= st[i].finish) {
				count++;
				i = j;
			}
		}
		cout << count << endl;
	}
}