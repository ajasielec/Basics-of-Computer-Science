//Anna Jasielec
#include <iostream>
using namespace std;

int licz_nogi(int ku, int kr, int sw) {
	int nogi;
	nogi = ku * 2 + kr * 4 + sw * 4;
	return nogi;
}

int main() {
	int kury, krowy, swinie;
	cout << "Podaj liczbe kur: ";
	cin >> kury;
	cout << "Podaj liczbe krow: ";
	cin >> krowy;
	cout << "Podaj liczbe swin: ";
	cin >> swinie;
	//licz_nogi(kury, krowy, swinie);

	cout << "Suma nog wszystkich zwierzat: " << licz_nogi(kury, krowy, swinie) << endl;

	system("pause");
	return 0;
}