#include <iostream>
#include <string>
using namespace std;

char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    }
}

int dectox_int(int a, int p, char* s)
{
    int num = (int)a;
    int rest = num % p;
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = dectox_int(num, p, s);
    s[k++] = digit(rest);
    return k;
}

string convertToReverse(int a) {
    bool isNegative = false;
    char s[80] = { 0 };
    char result[16];
    for (int i = 0; i < 16; i++) {
        result[i] = '0';
    }
    int p = 2;
    if (a < 0) {
        a = fabs(a);
        isNegative = true;
    }
    int k = dectox_int((int)a, p, s);
    if (isNegative) {
        for (int i = 0; i < 16 - k; i++) {
            result[i] = '1';
        }
        int j = 0;
        for (int i = 16 - k; i < 16; i++) {
            if (s[j] == '1') {
                result[i] = '0';
            }
            else if (s[j] == '0') {
                result[i] = '1';
            }
            j++;
        }
    }
    else {
        int j = 0;
        for (int i = 16 - k; i < 16; i++) {
            result[i] = s[j];
            j++;
        }
    }
    for (int i = 0; i < 16; i++) {
        cout << result[i];
    }
    return result;
}

string sum(string A, string B) {
    char carry = '0';

    char C[17] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
    char sum[17] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };

    for (int i = 15; i >= 0; i--) {
        C[i] = ((((A[i] - '0') ^ (B[i] - '0')) ^ (carry - '0'))) + '0';
        carry = ((((A[i] - '0') & (B[i] - '0')) | ((A[i] - '0') & (carry - '0'))) | ((B[i] - '0') & (carry - '0'))) + '0';
    }
    strcpy_s(sum, C);

    for (int l = 15; carry != '0'; l--) {
        sum[l] = ((C[l] - '0') ^ (carry - '0')) + '0';
        carry = ((C[l] - '0') & (carry - '0')) + '0'; 
    }
    return sum;
}

string convertFromReverse(string reverse_number) {
    string  number = "";
    if (reverse_number[0] == '0') {
        number = reverse_number;
    }
    else if (reverse_number[0] == '1') {
        if (reverse_number.find("0") != -1) {
            number = "-";
        }
        for (int i = 0; i < reverse_number.length(); i++) {
            if (reverse_number[i] == '0') {
                number.push_back('1');
            } else if (reverse_number[i] == '1') {
                number.push_back('0');
            }
        }
    }
    return number;
}

int main(){
    int a, b;
    cout << "Please enter a: ";
    cin >> a;
    cout << "Please enter b: ";
    cin >> b;
    string result1 = convertToReverse(a);
    cout << endl;
    string result2 = convertToReverse(b);
    cout <<"\nsum"<< endl;
    string s = sum(result1, result2);
    cout << s << endl;
    string number = convertFromReverse(s);
    cout <<"sum in natural form\n"<< number << endl;
	return 0;
}