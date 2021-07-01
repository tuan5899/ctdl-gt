#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		for (int i = 0; i < s.length(); i++) {
			char Max = s[s.length() - 1];
			int vt = s.size() - 1;
			for (int j = s.length() - 1; j > i && k > 0; j--) {
				if (s[j] > Max) {
					Max = s[j];
					vt = j;
				}
			}
			if (Max > s[i] && k > 0) {
				swap(s[vt], s[i]);
				k--;
			}
		}
		cout << s << endl;
	}
}