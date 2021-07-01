#include<iostream>

using namespace std;

void generate(string s) {
	int i = s.length() - 1;
	while (s[i] == '0') i--;
	if (i < 0) {
		for (int i = 0; i < s.length(); i++)cout << '1';
		cout << endl;
	}
	else {
		s[i] = '0';
		for (int j = i + 1; j < s.length(); j++) {
			s[j] = '1';
		}
		for (int i = 0; i < s.length(); i++) cout << s[i];
		cout << endl;
	}

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		generate(s);
	}
}