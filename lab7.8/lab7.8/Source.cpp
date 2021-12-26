#include <iostream>
#include <string>
using namespace std;

void swap_cod(string& two_decimal) {
	for (int j = 0, j1 = two_decimal.length() - 1; j < two_decimal.length() / 2; j++, j1--)
		swap(two_decimal[j], two_decimal[j1]);
}

string to_two_decimal(string s, string two_decimal, int t, int k, int c) {
	for (;;) {
		for (int u = 0; u < s.length() - 1; u++) {
			if (s[u] == '0') {
				k = 0;
			}
			else {
				k = 1;
				break;
			}
		}
		if (s[s.length() - 1] == '1' && !k) {
			two_decimal += '1';
			break;
		}
		if (s[s.length() - 1] == '0' && !k) {
			two_decimal += '0';
			break;
		}

		for (int e = 0; e < s.length(); e++) {
			c = s[e] - '0';
			if (c % 2) {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 1;
			}
			else {
				c = (c + t * 10) / 2;
				s[e] = c + '0';
				t = 0;
			}
			if (e == s.length() - 1) {
				if (t) two_decimal += '1';
				else  two_decimal += '0';
				t = 0;
			}
		}
	}

	for (int j = 0, j1 = two_decimal.length() - 1; j < two_decimal.length() / 2; j++, j1--) {
		swap(two_decimal[j], two_decimal[j1]);
	}

	return two_decimal;
}

int main() {
	string s, two_decimal1, two_decimal2, buf, buf2;
	int number;
	cout << "Please enter number:";
	cin >> number;
	while (cin.fail() || number < 1 || number > 10000) {
		cin.clear();
		cin.ignore(9999, '\n');
		cout << "Incorrect value, please enter number:";
		cin >> number;
	}
	s = to_string(number);

	if (number == 1) {
		cout << 1;
		return 0;
	}
	int h, h2;
	two_decimal1 = to_two_decimal(s, two_decimal1, 0, 0, 0);
	buf = two_decimal1;
	buf2 = s;
	swap_cod(buf);
	swap_cod(buf2);
	h = two_decimal1.length();
	h2 = s.length();
	buf.erase(h2, h);
	if (buf2 != buf) {
		cout << two_decimal1;
		return 0;
	}

	two_decimal1 = to_two_decimal(two_decimal1, two_decimal2, 0, 0, 0);
	swap_cod(two_decimal1);
	two_decimal1.erase(0, h2);
	two_decimal1.erase(h, two_decimal1.length());
	swap_cod(two_decimal1);
	while (two_decimal1[0] == '0') two_decimal1.erase(0, 1);
	cout << two_decimal1;
    return 0;
}