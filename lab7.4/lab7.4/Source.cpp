#include <iostream>
#include <string>
using namespace std;

string is(int a)
{   string b;
	if (a == 18)
		return (b = "0");
	else if (a == 17)
		return (b = "H");
	else if (a == 16)
		return (b = "G");
	else if (a == 15)
		return (b = "F");
	else if (a == 14)
		return (b = "E");
	else if (a == 13)
		return (b = "D");
	else if (a == 12)
		return (b = "C");
	else if (a == 11)
		return (b = "B");
	else if (a == 10)
		return (b = "A");
	else return (b = a + 48);
}

int eighteenDigit(char num) {
	switch (toupper(num)) {
	case 'H': return 17;
	case 'G': return 16;
	case 'F': return 15;
	case 'E': return 14;
	case 'D': return 13;
	case 'C': return 12;
	case 'B': return 11;
	case 'A': return 10;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 0;
	}
}

int len(string str)
{
	int length;
	for (length = 0; str[length]; length++);
	return length;
}

string sum(string a, string b) {
	string c = "", c1 = "";
	int counter = 0, tmp;
	int len_a, len_b;
	len_a = len(a);
	len_b = len(b);


	for (int i = len_a - 1, j = len_b - 1; i >= 0 && j >= 0; --i, --j) {
		int tmp_a = eighteenDigit(a[i]);
		int tmp_b = eighteenDigit(b[j]);
		tmp = tmp_a + tmp_b + counter;
		if (tmp <= 18){
			if (is(tmp) == "0") {
				counter = 1;
			}
			else {
				counter = 0;
			}
			c += is(tmp);
		}
		else{
			counter = tmp / 18;
			tmp %= 18;
			c += is(tmp);
		}
	}
	int difference;
	difference = abs(len_a - len_b);
	for (int i = difference - 1; i >= 0; i--) {
		if(len_a > len_b){
			c += a[i] + counter;
		}
		else {
			c += b[i] + counter;
		}
	}
	for (int i = c.size() - 1; i >= 0; i--) {
		c1 += c[i];
	}
	return c1;
}

void more(int& a, int& b){
	int tmp = a;
	if (a < b){
		a = b;
		b = tmp;
	}
}

string ras(string a, string b) {
	string c = "", c1 = "";
	int counter = 0, tmp;
	int len_a, len_b;
	len_a = len(a);
	len_b = len(b); 
	for (int i = len_a - 1, j = len_b - 1; j >= 0 && i >= 0; --i, --j) {
		int tmp_a = eighteenDigit(a[i]);
		int tmp_b = eighteenDigit(b[j]);
		tmp = tmp_a - tmp_b;
		if (tmp < 0)
		{
			a[i - 1] = a[i - 1] - 1;
			tmp_a = eighteenDigit(a[i]);
			tmp_b = eighteenDigit(b[j]);
			tmp = tmp_a - tmp_b + 18;
		}

		if (tmp <= 18)
		{
			c += is(tmp);
		}
	}
	int difference;
	difference = abs(len_a - len_b);
	for (int i = difference - 1; i >= 0; i--) {
		if (len_a > len_b) {
			c += a[i];
		}
		else {
			c += b[i];
		}
	}
	int len_c;
	len_c = len(c);
	for (int i = len_c - 1; i >= 0; i--) {
		c1 += c[i];
	}
	return c1;
}

int str_to_int(string str)
{
	int i, s, k, p; s = 0;
	p = str.length() - 1;
	for (i = 0; str[i] != '\0'; i++) {
		k = eighteenDigit(str[i]);
		s = s + k * pow(18, p);
		p--;
	}
	return s;
}

int main()
{
	string a, b, c, r;
	cout << "Please enter a, b:\n";
	cin >> a >> b;

	int sign = 1;
	int a_int, b_int;
	a_int = str_to_int(a);
	b_int = str_to_int(b);
	if (a_int < 0 && b_int > 0 && (abs(a_int) > abs(b_int)))
	{
		a_int *= -1;
		string an;
		more(a_int, b_int);
		an = a_int + '0';
		b = b_int + '0';
		r = sum(an, b);
		c = ras(an, b);
		cout << "Difference is:\n";
		cout << '-' << r << '\n';

		cout << "Sum is:\n";
		cout << '-' << c << '\n';
	}
	else if (a_int < 0 && b_int > 0 && (abs(a_int) < abs(b_int)))
	{
		a_int *= -1;
		string an;
		more(a_int, b_int);
		an = a_int + '0';
		b = b_int + '0';
		r = sum(an, b);
		c = ras(an, b);
		cout << "Difference is:\n";
		cout << '-' << r << '\n';

		cout << "Sum is:\n";
		cout << c << '\n';
	}
	else if (a_int > 0 && b_int < 0 && (abs(a_int) > abs(b_int)))
	{
		b_int *= -1;
		string bn;
		more(a_int, b_int);
		a = a_int + '0';
		bn = b_int + '0';
		r = sum(a, bn);
		c = ras(a, bn);
		cout << "Difference is:\n";
		cout << r << '\n';

		cout << "Sum is:\n";
		cout << c << '\n';
	}
	else if (a_int > 0 && b_int < 0 && (abs(a_int) < abs(b_int)))
	{
		b_int *= -1;
		string bn;
		more(a_int, b_int);
		a = a_int + '0';
		bn = b_int + '0';
		r = sum(a, bn);
		c = ras(a, bn);
		cout << "Difference is:\n";
		cout << r << '\n';

		cout << "Sum is:\n";
		cout << '-' << c << '\n';
	}
	else if (a_int > b_int && a_int > 0 && b_int > 0) {
		more(a_int, b_int);
		a = a_int + '0';
		b = b_int + '0';
		r = ras(a, b);
		c = sum(a, b);
		cout << "Difference is:\n";
		cout << r << '\n';

		cout << "Sum is:\n";
		cout << sum << '\n';
	}
	else if (a_int < 0 && b_int < 0 && a_int > b_int)
	{
		a_int *= -1;
		b_int *= -1;
		string an, bn;
		more(a_int, b_int);
		an = a_int + '0';
		bn = b_int + '0';
		r = ras(an, bn);
		c = sum(an, bn);
		cout << "Difference is:\n";
		cout << r << '\n';

		cout << "Sum is:\n";
		cout << '-' << c << '\n';
	}
	else if (a_int < 0 && b_int < 0 && a_int < b_int)
	{
		a_int *= -1;
		b_int *= -1;
		string an, bn;
		more(a_int, b_int);
		an = a_int + '0';
		bn = b_int + '0';
		r = ras(an, bn);
		c = sum(an, bn);
		cout << "Difference is:\n";
		cout << '-' << r << '\n';

		cout << "Sum is:\n";
		cout << '-' << c << '\n';
	}
	else if (abs(a_int) == abs(b_int))
	{
		if (a_int == b_int && b_int > 0)
		{
			cout << "Difference is:\n";
			cout << 0 << '\n';

			cout << "Sum is:\n";
			cout << 2 * a_int << '\n';
		}
		if (a_int == b_int && b_int < 0)
		{
			cout << "Difference is:\n";
			cout << 0 << '\n';

			cout << "Sum is:\n";
			cout << 2 * a_int << '\n';
		}
		if (a_int < 0 && b_int > 0)
		{
			cout << "Difference is:\n";
			cout << 2 * a_int << '\n';

			cout << "Sum is:\n";
			cout << 0 << '\n';
		}
		if (a_int > 0 && b_int < 0)
		{
			cout << "Difference is:\n";
			cout << 2 * a_int << '\n';

			cout << "Sum is:\n";
			cout << 0 << '\n';
		}
	}
	else
	{
		c = sum(a, b);
		r = ras(b, a);
		cout << "Difference is:\n";
		cout << '-' << r << '\n';

		cout << "Sum is:\n";
		cout << c << '\n';
	}
}

