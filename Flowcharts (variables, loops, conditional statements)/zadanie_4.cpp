/*zadanie 4*/
/* program, kt�ry wczytuje N liczb z klawiatury oraz wypisuje
na ekran �redni� liczb oraz x-razy liczb� 0, gdzie x = �rednia 
wprowadzonych liczb*/

#include <iostream>
using namespace std;

int main() {

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
	srednia = suma/n;
	cout<< "Srednia liczb wynosi: " << srednia <<endl;

	//wypisanie x razy liczbe 0, gdzie x to srednia
	for (int i = 0; i < srednia; i++) {
		cout << 0 << " ";
	};

	cout << endl;
	system("pause");
	return 0;
}