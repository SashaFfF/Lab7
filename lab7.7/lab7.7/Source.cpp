#include <iostream>
using namespace std;

void divisibility(int number, int n) {
	bool result = false;
	for (int i = 0; i <= number; i += n) {
		if (i == number) {
			result = true;
		}
	}
	if (result) {
		cout << "The number is divisible by " << n << endl;
	}
	else {
		cout << "The number is not divisible by " << n << endl;
	}
}


int main() {
	int number;
	cout << "Please enter number:";
	cin >> number;
	bool result = false;
	divisibility(number, 7);
	divisibility(number, 79);
	divisibility(number, 107);

	return 0;
}

