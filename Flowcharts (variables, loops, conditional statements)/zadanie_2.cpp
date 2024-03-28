/*zadanie 2*/
/*program, kt�ry wczytuje z klawiatury dwie liczby ca�kowite, a nast�pnie wypisuje
wszystkie liczby z ich przedzia�u i dodaje wszystkie parzyste liczby z przedzia�u 
i wypisuje wynik na ekranie*/

#include <iostream>
using namespace std;

int main() {

	//przypisanie warto�ci do zmiennych
	int liczba1;
	int liczba2;

	cout << "Podaj pierwsza liczbe calkowita: ";
	cin >> liczba1;

	cout << "Podaj druga liczbe calkowita: ";
	cin >> liczba2;


	//znalezienie mniejszej liczby
	int min, max;
	if (liczba1 <= liczba2) {
		min = liczba1;
		max = liczba2;
	}
	else {
		min = liczba2;
		max = liczba1;
	}


	//stworzenie petli, ktora wypisze przedzial tych liczb
	cout << "Liczby z przedzialu tych dwoch liczb calkowitych:" << endl;

	for (int x = min; x <= max; x++) {
		cout << x << " ";
	}


	//dodanie wszystkich liczb parzystych i wypisanie sumy
	int suma = 0;
	for (int x = min; x <= max; x++) {
		if (x % 2 == 0) {
			suma += x;
		}
	}
	cout << endl <<"Suma liczb parzystych z tego przedzialu: "<< suma << endl;

	system("pause");
	return 0;
}