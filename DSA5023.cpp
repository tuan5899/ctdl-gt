#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		long long res = 0;
		for (int i = 0; i < s.length(); i++) {
			long long temp = 0;
			for (int j = i; j < s.length(); j++) {
				temp = temp * 10 + int(s[j] - '0');
				res += temp;
			}
		}
		cout << res << endl;
	}
}