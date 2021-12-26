#include <iostream>
#include <iostream>
using namespace std;

char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    }
}
//getting the integer part of a number
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
//getting the fractional part of a number
int dectox_double(double a, int p, char* s)
{
    int iter = 0;
    int k = 0;
    double a1 = a;
    do {
        a1 = a1 * p;
        int num = (int)(a1);
        s[k++] = digit(num);
        a1 -= (int)a1;
        iter++;
    } while (a1 > 0.00000001 && iter < 10);
    s[k] = '\0';
    return k;
}
int main()
{
    bool isNegative = false;
    double a;
    char s[80] = { 0 };
    char result[81] = { 0 };
    int p = 2;
    cout << "Please enter number: ";
    cin >> a;
    if (a < 0) {
        a = fabs(a);
        isNegative = true;
    }
    int k = dectox_int((int)a, p, s);
    s[k++] = ',';
    k += dectox_double(a - (int)a, p, &s[k]);
    if (isNegative) {
        result[0] = '1';
        for (int i = 0; i <= k; i++) {
            if (s[i] == '1'){
                result[i + 1] = '0';
            }
            else if (s[i] == '0') {
                result[i + 1] = '1';
            }
            else {
                result[i + 1] = s[i];
            }
        }
    }
    else {
        for (int i = 0; i <=k; i++) {
            result[i] = s[i];
        }
    }
    cout << result;
    return 0;
}