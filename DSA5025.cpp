#include<iostream>

using namespace std;

long long F[60];

int main() {
	int t;
	cin >> t;
	F[1] = 1, F[2] = 2, F[3] = 4;
	for (int i = 4; i <= 55; i++) {
		F[i] = F[i - 1] + F[i - 2] + F[i - 3];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << F[n] << endl;
	}
}