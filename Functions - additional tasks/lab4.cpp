//Anna Jasielec
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

void lotto() {

	srand(time(NULL));

	for (int i = 0; i < 6; i++) {
		int liczba = rand() % 49 + 1;
		cout << liczba << endl;
		Sleep(1000);
	}
}


int cisnienie() {
	double Pa;
	cout << "Podaj cisnienie w Pa: ";
	cin >> Pa;
	cout << "Na jaka jednostke chcesz przeliczyc wartosc? Wybierz cyfre od 1 do 3\n1 - bar\n2 - tor\n3 - psi" << endl;
	int wybor;
	double wynik;
	cin >> wybor;

	switch (wybor) {
	case 1: wynik = Pa * pow(10, -5);
		cout << Pa << " Pa to " << wynik << " bar" << endl;
		break;
	case 2: wynik = Pa * 0.0075;
		cout << Pa << " Pa to " << wynik << " tor" << endl;
		break;
	case 3: wynik = Pa * 145.038 * pow(10, -6);
		cout << Pa << " Pa to " << wynik << " psi" << endl;
		break;
	default: cout << "Zla cyfra" << endl;
	}

	return (wynik);
}


int LiczbyPitagorejskie(int a, int b, int c) {

	bool wynik;
	wynik = a * a + b * b == c * c;
	if (wynik == 1) { return (1); }
	else { return (0); }
}


void CiagArytmetyczny() {
	int tab_arytm[100];
	int a, r;
	cout << "Podaj pierwszy wyraz ciagu: ";
	cin >> a;
	cout << "Podaj roznice ciagu: ";
	cin >> r;

	for (int i = 0; i < 100; i++) {
		tab_arytm[i] = a;
		a += r;
		cout << tab_arytm[i] << " ";
	}
	cout << endl;
}


void CiagGeometryczny() {
	long double a, q;
	long double tab_geom[100];
	cout << "Podaj pierwszy wyraz ciagu: ";
	cin >> a;
	cout << "Podaj iloraz ciagu: ";
	cin >> q;

	for (int i = 0; i < 100; i++) {
		tab_geom[i] = a;
		a *= q;
		cout << tab_geom[i] << " ";
	}
	cout << endl;
}




int main() {

	cout << "[1]-lotto\n[2]-cisnienie\n[3]-pitagoras\n[4]-ciag arytmetyczny\n[5]-ciag geometryczny\n[6]-zakoncz"<<endl;
	int nr_zadania;
	
	while (true) {
		cout << "\nKtore zadanie chcesz zobaczyc? ";
		cin >> nr_zadania;
		
		switch (nr_zadania) {
		
		case 1: lotto();
			break;
		
		case 2: cisnienie();
			break;
		
		case 3: //pitagoras
			int a, b, c;
			cout << "Podaj 3 liczby calkowite: ";
			cin >> a >> b >> c;
			cout << LiczbyPitagorejskie(a, b, c) << endl;
			break;
		
		case 4: CiagArytmetyczny();
			break;
		
		case 5: CiagGeometryczny();
			break;
		
		case 6: return (-1);

		default: cout << "Podales zly numer" << endl;
		}
	}


	system("pause");
	return 0;
}