#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	stack<int>stk;
	while (1) {
		string s = "";
		getline(cin, s);
		string s1 = "", s2 = "";
		if (s.length() == 3) {
			if (!stk.empty()) {
				stk.pop();
			}
			else {
				cout << "empty" << endl;
				break;
			}
		}
		else if (s.length() == 4) {
			if (!stk.empty()) {
				vector<int>vt;
				vt.clear();
				while (!stk.empty()) {
					int temp = stk.top();
					stk.pop();
					vt.push_back(temp);
				}
				for (int i = vt.size() - 1; i >= 0; i--) {
					cout << vt[i] << " ";
					stk.push(vt[i]);
				}
				cout << endl;
			}
			else {
				cout << "empty" << endl;
				break;
			}
		}
		else if (s.length() > 4) {
			int temp = 0;
			for (int i = 5; i < s.length(); i++) {
				temp = temp * 10 + int(s[i] - '0');
			}
			stk.push(temp);
		}

	}
}