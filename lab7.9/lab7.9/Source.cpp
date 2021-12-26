#include <iostream>
#include <string>
using namespace std;

char threeDigit(int num) {
	switch (num) {
	case 0: return '3';
	case 1: return '1';
	case 2: return '2';
	}
}

string toThree(int a, string threeNum)
{
	int p = 3;
	int num = (int)a;
	int rest = num % p;
	num /= p;
	if (num == 0)
	{
		threeNum.insert(0, 1, threeDigit(rest));
		return threeNum;
	}
	threeNum = toThree(num, threeNum);
	threeNum.push_back(threeDigit(rest));
	return threeNum;
}


int main() {

	int testNumber;
	cout << "Please enter number:";
	cin >> testNumber;
	string result = ""; 
	result = toThree(testNumber, result);
	cout << result << endl;
	
	return 0;
}