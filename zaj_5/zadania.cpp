#include<iostream>
using namespace std;

bool Negacja(bool z1) {
	return !z1;
}

bool Koniunkcja(bool z1, bool z2) {
	return z1 && z2;
}

bool Alternatywa(bool z1, bool z2) {
	return z1 || z2;
}

bool Implikacja(bool z1, bool z2) {
	return !(z1 == 1 && z2 == 0);
}

bool Rownowaznosc(bool z1, bool z2) {
	return (z1 == z2);
}

//ZADANIE 1
void Zadanie1() {
	
	bool p, q;
	cout << "Podaj wartosc p i q:\n";
	cin >> p >> q;

	cout << "Negacja p: " << Negacja(p) << endl << "Negacja q: " << Negacja(q) <<endl;
	cout << "Koniunkcja: " << Koniunkcja(p, q) <<endl;
	cout << "Alternatywa: " << Alternatywa(p, q) << endl;
	cout << "Implikacja: " << Implikacja(p, q) << endl;
	cout << "Rownowaznosc: " << Rownowaznosc(p, q) << endl;
}


//ZADANIE 2
void Zadanie2() {
	
	bool p = 1, q = 1, r = 0;
	cout << "p = " << p << ", q = " << q << ", r = " << r << endl;

	cout << "a) " << Koniunkcja(p, q) << endl; //a
	cout << "b) " << Alternatywa(p, q) << endl; //b
	cout << "c) " << Koniunkcja(Negacja(p), Alternatywa(p, q)) << endl; //c
	cout << "d) " << Implikacja(Koniunkcja(p, r), q) << endl; //d
	cout << "e) " << Negacja(Rownowaznosc(p, Alternatywa(q, r))) << endl; //e
	cout << "f) " << Rownowaznosc(Alternatywa(Implikacja(p, r), Negacja(q)), Implikacja(p, Koniunkcja(r, Negacja(q)))) << endl ; //f
	cout << "g) " << Rownowaznosc(Alternatywa(Alternatywa(Negacja(r), q), Negacja(Koniunkcja(q, r))), Negacja(Implikacja(q, p))); //g

}


//ZADANIE 3 (1, 14, 27)


void main() {
	
	while (1) { 
		int nr;
		cout << "Wybierz numer zadania: ";
		cin >> nr;*/

		/*switch (nr) {
		case 1: Zadanie1();
			break;
		case 2: Zadanie2();
			break;
		default: cout << "Podales zly numer!";
		}
	} 
} 