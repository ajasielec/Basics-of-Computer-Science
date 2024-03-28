/*zadanie 1*/
//program, który po pobraniu pe³nego roku okreœli, czy dany rok jest przestêpny

#include <iostream>
using namespace std;

int main() {

	int rok; //wprowadzenie zmiennej rok
	cout << "Podaj rok: ";
	cin >> rok; //wprowadzenie wartoœci zmiennej rok


  //stworzenie instrukcji warunkowej if, ktora sprawdza czy rok jest przestêpny i to wypisuje, jesli jest 
	if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) { 
		cout << "Rok " << rok << " jest przestepny." << endl; 
    }

	//je¿eli if nie zachodzi, zachodzi else, ktore wypisuje, ze rok nie jest przestepny
	else {
		cout << "Rok " << rok << " nie jest przestepny." << endl;

	}

	system("pause");
	return 0;
}
