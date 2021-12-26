#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	int arr_barrels[240] = { 0 };
	int index = rand() % 240;
	cout << index << endl;
	arr_barrels[index] = 1;
	double arr_time[48];
	arr_time[0] = 0;
	for (int i = 1; i < 48; i++) {
		arr_time[i] = arr_time[i - 1] + 0.5;
	}
	int arr_slaves[5] = { 1,2,3,4,5 };
	double timeToDie;
	int slave_number;
	int barrel_number;
	int i = 0;
	for (int j = 0; j < 48; j++) {
		for (int k = 0; k < 5; k++) {
			cout << "Slave #" << arr_slaves[k] << " tastes wine at " << arr_time[j] << " o'clock on the first day" << endl;
			if (arr_barrels[i] == 1) {
				timeToDie = arr_time[j] + 24;
				slave_number = arr_slaves[k];
				barrel_number = i;
			}
			i++;
		}
	}
	for (int j = 0; j < 48; j++) {
		if (timeToDie == arr_time[j] + 24) {
			cout << "Slave #" << slave_number << " died at " << arr_time[j] << " o'clock on the second day" << endl;
			cout << "The poison is in the barrel with the number " << barrel_number << endl;
			break;
		}
		else {
			cout << "Nobody died at " << arr_time[j] << " o'clock on the second day" << endl;
		}
	}


	return 0;
}