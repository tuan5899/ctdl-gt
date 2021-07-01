#include<iostream>

using namespace std;

string solve(string s) {
	int n = s.length();
	int i = n - 2;
	while (i >= 0 && s[i] >= s[i + 1]) i--;
	if (i < 0) {
		return "BIGGEST";
	}
	else {
		int j = n - 1;
		while (s[j] <= s[i]) j--;
		swap(s[i], s[j]);
		int d = i + 1, c = n - 1;
		while (d < c) {
			swap(s[d], s[c]);
			d++, c--;
		}
		return s;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int useL;
		cin >> useL >> s;
		cout << useL << " " <<solve(s) << endl;
	}
}