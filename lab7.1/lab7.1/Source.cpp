#include <iostream>
#include <string>
using namespace std;

char hexDigit(int num) {
	switch (num) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	}
}

int elevenDigit(char num) {
	switch (toupper(num)) {
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

int toHexUsingArray(int a, char* hexNum)
{
	int p = 6;
	int num = (int)a;
	int rest = num % p;
	num /= p;
	if (num == 0)
	{
		hexNum[0] = hexDigit(rest); 
		return 1;
	}
	int k = toHexUsingArray(num, hexNum);
	hexNum[k++] = hexDigit(rest);
	return k;
}

string toHexUsingString(int a, string hexNum)
{
	int p = 6;
	int num = (int)a;
	int rest = num % p;
	num /= p;
	if (num == 0)
	{
		hexNum.insert(0, 1, hexDigit(rest));
		return hexNum;
	}
	hexNum = toHexUsingString(num, hexNum);
	hexNum.push_back(hexDigit(rest));
	return hexNum;
}

int fromElevenUsingArray(char* elevenNum, int size) {
	int i, s, k, p; s = 0;
	p = size - 1;
	for (i = 0; i < size; i++) {
		k = elevenDigit(elevenNum[i]);
		s = s + k * pow(11, p);
		p--;
	}
	return s;
}

int fromElevenUsingString(string elevenNum) {
	int i, s, k, p; s = 0; 
	p = elevenNum.length() - 1; 
	for (i = 0; elevenNum[i] != '\0'; i++){
		k = elevenDigit(elevenNum[i]);
		s = s + k * pow(11, p); 
		p--; 
	} 
	return s;
}

int main() {
	string el;
	string hexAsString = "";
	cout << "Please enter number for convertating using strings: ";
	cin >> el;
	int dec1 = fromElevenUsingString(el);
	hexAsString  = toHexUsingString(dec1, hexAsString);
	cout << "The number in hex system (using string): ";
	cout << hexAsString << endl;

	int len;
	char hexAsArray[80] = { 0 };
	cout << "Please enter length of number to convert: ";
	cin >> len;
	char* elNum = new char[len];
	cout << "Please enter number for converting using array: ";
	cin >> elNum;
	int dec2 = fromElevenUsingArray(elNum, len);
	toHexUsingArray(dec2, hexAsArray);
	cout << "The number in hex system (using array): ";
	cout << hexAsArray << endl;

	return 0;
}