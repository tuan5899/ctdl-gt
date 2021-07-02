<<<<<<< HEAD
#include<iostream>

using namespace std;

int List[1005][1005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> List[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (List[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
=======
#include<iostream>

using namespace std;

int List[1005][1005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> List[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (List[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
>>>>>>> a5a8a68f43ab1c7cb9911d2fd691dc08ddfa3520
}