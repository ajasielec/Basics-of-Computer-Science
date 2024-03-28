/*zadanie 3*/
/*Napisz program, który wczytuje 5 liczb z klawiatury oraz 
wypisuje na ekran najwiêksz¹ i najmniejsz¹ liczbê oraz ich ró¿nicê*/

#include<iostream>
using namespace std;

int main() {

	//stworzenie tablicy i dwoch zmiennych
	int tab[5];
	int min, max;

	//przypisanie wartosci do tablicy
	cout << "Podaj 5 liczb: "<<endl;

	for (int i = 0; i < 5; i++) {
		cin >> tab[i];
	}

	//szukanie wartosci minimalnej i maksymalnej
	min = tab[0];
	max = tab[0];

	for (int i = 1; i < 5; i++) {
		if (tab[i] < min) {
			min = tab[i];
		}
		if (tab[i] > max) {
			max = tab[i];
		}
	}

	//wypisanie liczby najwiekszej i najmiejszej i ich roznicy
	cout << "Najmniejsza liczba to: " << min << endl;
	cout << "Najwieksza liczba to: " << max << endl;
	cout << "Roznica tych liczb to: " << max-min << endl;

	system("pause");
	return 0;
}