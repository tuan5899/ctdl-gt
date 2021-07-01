#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > st;
bool cmp(vector<int> a, vector<int> b) {
	if (a.size() < b.size()) return true;
	if (a.size() == b.size()) return true;
	return false;
}
void quayLui(int n, int a[], int b[], int k) {
	for (int i = k + 1; i < n; i++) {
		b[i] = a[i] + a[i - 1];
	}
	for (int i = 0; i < n; i++) a[i] = b[i];
	vector<int>temp;
	temp.clear();
	for (int i = k + 1; i < n; i++) temp.push_back(b[i]);
	if (temp.size() != 0) {
		st.push_back(temp);
	}
	if (k == n)return;
	else {
		quayLui(n, a, b, k + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[15], b[15];
		cin >> n;
		int k = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int>temp;
		temp.clear();
		st.clear();
		for (int i = 0; i < n; i++)temp.push_back(a[i]);
		st.push_back(temp);
		quayLui(n, a, b, k);
		sort(st.begin(), st.end(), cmp);
		for (int i = 0; i < st.size(); i++) {
			cout << '[';
			for (int j = 0; j < st[i].size() - 1; j++) {
				cout << st[i][j] << " ";
			}
			cout << st[i][st[i].size() - 1] << "] ";
		}
		cout << endl;
	}
}