#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n, m, d;

	cin >> n >> m >> d;

	int k = n * m;
	int b[10000];

	cin >> b[0];
	int r = b[0] % d;
	for (int i = 1; i < k; i++) { 
		cin >> b[i];
		if (b[i] % d != r) {
			cout << -1;
			return 0;
		}
	}
	sort(b, b + k);

	int med = b[k / 2];
	int s = 0;
	for (int j = 0; j < k; j++) s += abs(b[j] - med);
	
	if (k % 2 == 0) {
			int s2 = 0;
			for (int j = 0; j < k; j++) s2 += abs(b[j] - med);
			s = min(s, s2);
	}

	cout << s / d;
}
