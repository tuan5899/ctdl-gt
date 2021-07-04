#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	stack<int>stk;
	while (t--) {
		string s = "";
		cin >> s;
		if (s == "PUSH") {
			int n;
			cin >> n;
			stk.push(n);
		}
		else if (s == "POP" && !stk.empty()) stk.pop();
		else if (s == "PRINT") {
			if (stk.empty()) cout << "NONE" << endl;
			else cout << stk.top() << endl;
		}
	}
}