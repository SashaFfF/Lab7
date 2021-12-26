#include <iostream>
using namespace std;

bool isInteresting(int N) {
	int sum1 = 0;
	int sum2 = 0;
	int M = N + 1;
	while (N > 0) {
		sum1 += N % 10;
		N /=10;
	}
	while (M > 0) {
		sum2 += M % 10;
		M /= 10;
	}
	if (sum2 < sum1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n, t;
	cout << "Please enter t:";
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Please enter number:";
		cin >> n;
		int amount = 0;
		for (int i = 1; i <= n; i++) {
			if (isInteresting(i)) {
				amount++;
			}
		}
		cout << "amount:" << amount << endl;
	}	
	return 0;
}
