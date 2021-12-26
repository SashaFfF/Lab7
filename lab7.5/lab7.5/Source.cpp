#include <iostream>
#include <string>
using namespace std;

string convert(int digit, string low, string mid, string high){
    if (digit == 1)
    {
        return low;
    }
    if (digit == 2)
    {
        return low + low;
    }
    if (digit == 3)
    {
        return low + low + low;
    }
    if (digit == 4)
    {
        return low + mid;
    }
    if (digit == 5)
    {
        return mid;
    }
    if (digit == 6)
    {
        return mid + low;
    }
    if (digit == 7)
    {
        return mid + low + low;
    }
    if (digit == 8)
    {
        return mid + low + low + low;
    }
    if (digit == 9)
    {
        return low + high;
    }
    if (digit == 0)
    {
        return "";
    }
}

int main(){
    const int MAX_INPUT = 3999, MIN_INPUT = 0, array_size = 4;               
    string answers[array_size] = { "", "", "", "" }; //An  array of string to hold the output from the convert function.
    int accumulator = 0; // Variable to hold number of arabic numbers converted.
    int userNum = 0;
    cout << "Please enter an arabic number between 1 and 3999: ";    
    while (!(cin >> userNum) || (userNum < 1 || userNum > 3999)) {
        if (userNum < 0)
        {
            cout << "Exiting program:";
            return 0;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nNumber must be between 1 and 3999. Try again ";
        }
    }

    int thous = userNum / 1000;
    int hund = userNum % 1000 / 100;
    int tens = userNum % 100 / 10;
    int ones = userNum % 10 / 1;

    answers[0] = convert(thous, "M", "M", "M");
    answers[1] = convert(hund, "C", "D", "M");
    answers[2] = convert(tens, "X", "L", "C");
    answers[3] = convert(ones, "I", "V", "X");

    cout << answers[0] << answers[1] << answers[2] << answers[3];
    return 0;
}
