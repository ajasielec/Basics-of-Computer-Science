#include <iostream>
using namespace std;

//zadanie 1
void zadanie_1() {

	int rok;
	cout << "Podaj rok: ";
	cin >> rok; //wprowadzenie wartoœci zmiennej rok


  //stworzenie instrukcji warunkowej if, ktora sprawdza czy rok jest przestêpny i to wypisuje, jesli jest 
	if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
		cout << "Rok " << rok << " jest przestepny." << endl << endl;
	}

	//je¿eli if nie zachodzi, zachodzi else, ktore wypisuje, ze rok nie jest przestepny
	else {
		cout << "Rok " << rok << " nie jest przestepny." << endl << endl;

	}
}

//zadanie 2
void zadanie2() {

	//przypisanie wartoœci do zmiennych
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
	cout << endl << "Suma liczb parzystych z tego przedzialu: " << suma << endl << endl;
}


//zadanie 3
void zadanie3() {

	//stworzenie tablicy i dwoch zmiennych
	int tab[5];
	int min, max;

	//przypisanie wartosci do tablicy
	cout << "Podaj 5 liczb: " << endl;

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
	cout << "Roznica tych liczb to: " << max - min << endl << endl;
}


//zadanie 4
void zadanie4() {

	//stworzenie zmiennej n, zmiennej srednia i zmiennej suma
	int n;
	int srednia;
	int suma = 0;

	//przypisanie wartosci do zmiennej n
	cout << "Podaj n: ";
	cin >> n;

	//wczytanie n liczb z klawiatury i obliczenie ich sumy
	cout << "Podaj n liczb:" << endl;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		suma += x;
	}

	//obliczenie sredniej i wypisanie jej
	srednia = suma / n;
	cout << "Srednia liczb wynosi: " << srednia << endl;

	//wypisanie x razy liczbe 0, gdzie x to srednia
	for (int i = 0; i < srednia; i++) {
		cout << 0 << " ";
	};
	cout << endl << endl;
}




int main() {
	int nr_zadania=0;
	
	while (nr_zadania!=5) {

		cout << "Podaj numer od 1 do 5: ";
		cin >> nr_zadania;

		switch (nr_zadania)
		{
		case 1:
			zadanie_1();
			break;

		case 2:
			zadanie2();
			break;

		case 3:
			zadanie3();
			break;

		case 4:
			zadanie4();
			break;

		case 5:
			break;


		default:
			cout << "Podales zly numer." << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

