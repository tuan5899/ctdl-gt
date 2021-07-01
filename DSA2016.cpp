#include<iostream>

using namespace std;

bool c[22],h[22],xuoi[22],nguoc[22];
int n, soLan;
void init() {
	cin >> n;
	for (int i = 1; i <= 21; i++) {
		c[i] = false;
		h[i] = false;
		xuoi[i] = false;
		nguoc[i] = false;
	}
	soLan = 0;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!h[i] && !c[j] && !xuoi[i + j - 1] && !nguoc[i - j + n]) {
			h[i] = c[j] = xuoi[i + j - 1] = nguoc[i - j + n] = true;
			if (i == n)
				soLan++;
			else Try(i + 1);
			h[i] = c[j] = xuoi[i + j - 1] = nguoc[i - j + n] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		init();
		Try(1);
		cout << soLan << endl;
	}
}