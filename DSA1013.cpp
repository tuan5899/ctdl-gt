#include<iostream>


using namespace std;

void solve() {
	string s;
	int gray[15] = { 0 };
	int bin[15] = { 0 };
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		gray[i + 1] = int(s[i] - '0');
	}
	for(int i = 1; i <= s.length(); i++){
		bin[i] = bin[i - 1] xor gray[i];
		cout << bin[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}