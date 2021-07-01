#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

vector<int>List[1005];

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		s += " ";
		int so = 0;
		int j = 0;
		while (j < s.size()) {
			if (s[j] >= '0' && s[j] <= '9')
				so = 10 * so + int(s[j] - '0');
			else if (so > 0) {
				List[i].push_back(so);
				so = 0;
			}
			j++;
		}
	}
	for (int i = 1; i <= n; i++)
		sort(List[i].begin(), List[i].end());
	int d[100][100];
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < List[i].size(); j++) {
			if (!d[i][List[i][j]] && !d[List[i][j]][i]) {
				cout << i << " " << List[i][j] << endl;
			}
			d[i][List[i][j]] = d[List[i][j]][i] = 1;
		}
	}
}