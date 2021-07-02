<<<<<<< HEAD
#include<iostream>
#include<string>
#include<cstring>


using namespace std;

int List[1005][1005];

int main() {
	int n;
	cin >> n;
	cin.ignore();
	memset(List, 0, sizeof(List));
	for (int i = 1; i <= n; i++) {
		string s = "";
		getline(cin, s);
		s += " ";
		int temp = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				temp = temp * 10 + int(s[j] - '0');
			}
			else if (temp > 0) {
				List[i][temp] = 1;
				List[temp][i] = 1;
				temp = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << List[i][j] << " ";
		}
		cout << endl;
	}
=======
#include<iostream>
#include<string>
#include<cstring>


using namespace std;

int List[1005][1005];

int main() {
	int n;
	cin >> n;
	cin.ignore();
	memset(List, 0, sizeof(List));
	for (int i = 1; i <= n; i++) {
		string s = "";
		getline(cin, s);
		s += " ";
		int temp = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				temp = temp * 10 + int(s[j] - '0');
			}
			else if (temp > 0) {
				List[i][temp] = 1;
				List[temp][i] = 1;
				temp = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << List[i][j] << " ";
		}
		cout << endl;
	}
>>>>>>> a5a8a68f43ab1c7cb9911d2fd691dc08ddfa3520
}