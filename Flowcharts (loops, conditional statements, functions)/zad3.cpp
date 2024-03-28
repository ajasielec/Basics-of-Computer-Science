//Anna Jasielec
#include <iostream>
using namespace std;


int main() {

	int n, s, e, w, x=0, y=0;
	cout << "Podaj przesuniecie robota na polnoc: ";
	cin >> n;
	cout << "Podaj przesuniecie robota na wschod: ";
	cin >> e;
	cout << "Podaj przesuniecie robota na poludnie: ";
	cin >> s;
	cout << "Podaj przesuniecie robota na zachod: ";
	cin >> w;


	x = e - w;
	y = n - s;
	cout << "Robot jest na wspolrzednych (" << x << ", " << y << ")." << endl;

	system("pause");
	return 0;
}

