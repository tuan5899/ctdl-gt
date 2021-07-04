#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<char>stk;
		int dem = 0;
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') stk.push(s[i]);
			else {
				if (stk.empty())	dem++;
				else {
					stk.pop();
				}
			}
		}
		if (dem % 2 == 0)  res += dem / 2;
		else res += dem / 2 + 2;
		int count = 0;
		while (!stk.empty()) {
			count++;
			stk.pop();
		}
		res += count / 2;
		cout << res << endl;
	}
}