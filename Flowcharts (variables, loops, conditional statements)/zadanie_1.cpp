/*zadanie 1*/
//program, kt�ry po pobraniu pe�nego roku okre�li, czy dany rok jest przest�pny

#include <iostream>
using namespace std;

int main() {

	int rok; //wprowadzenie zmiennej rok
	cout << "Podaj rok: ";
	cin >> rok; //wprowadzenie warto�ci zmiennej rok


  //stworzenie instrukcji warunkowej if, ktora sprawdza czy rok jest przest�pny i to wypisuje, jesli jest 
	if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) { 
		cout << "Rok " << rok << " jest przestepny." << endl; 
    }

	//je�eli if nie zachodzi, zachodzi else, ktore wypisuje, ze rok nie jest przestepny
	else {
		cout << "Rok " << rok << " nie jest przestepny." << endl;

	}

	system("pause");
	return 0;
}
