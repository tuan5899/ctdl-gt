#include<iostream>
#include<vector>
#include<cstring>
#include <climits>
using namespace std;

bool check[20];
int n;
int a[20];
int res = INT_MAX;
vector<string>s;

int same(string s1, string s2) {
	int temp = 0;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) temp++;
		}
	}
	return temp;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!check[j]) {
			check[j] = true;
			a[i] = j;
			if (i == n) {
				int temp = 0;
				for (int k = 1; k <= n - 1; k++) {
					temp += same(s[a[k]], s[a[k + 1]]);
				}
				res = min(res, temp);

			}
			else Try(i + 1);
			check[j] = false;
		}
	}
}

int main() {
	cin >> n;
	s.resize(n + 5);
	memset(check, false, sizeof(check));
	for (int i = 1; i <= n; i++) cin >> s[i];
	Try(1);
	cout << res << endl;
}