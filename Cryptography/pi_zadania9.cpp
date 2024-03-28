#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string ZaszyfrujCezar(string wiadomosc);
string OdszyfrujCezar(string szyfr);
string ZaszyfrujPrzestawianie(string wiadomosc);
string OdszyfrujPrzestawianie(string szyfr);

int main() {
  int nr;
  string wiadomosc, szyfr;
  cout << "MENU\n[1] - Szyfrowanie Cezara\n[2] - Szyfrowanie metodą "
          "przestawiania\n";
  cout << "\nPodaj wiadomość którą chcesz zaszyfrować:\n";
  getline(cin, wiadomosc);
  cout << "\nKtórą metodą chcesz zaszyfrować swoją wiadomość?\n";
  cin >> nr;

  switch (nr) {
  case 1:
    szyfr = ZaszyfrujCezar(wiadomosc);
    break;
  case 2:
    szyfr = ZaszyfrujPrzestawianie(wiadomosc);
    break;
  default:
    cout << "Złe dane.";
    break;
  }

  fstream plik;
  // wpisanie zaszyfrowanej wiadomosci do pliku
  plik.open("szyfr.txt", ios::out);
  plik << szyfr;
  plik.close();
  cout << "Twoja wiadomość została zaszyfrowana i zapisana w pliku.\n";

  // odczytanie z pliku zaszyfrowanej wiadomosci
  plik.open("szyfr.txt", ios::in);
  plik >> szyfr;
  plik.close();

  cout << "\nKtórą metodą chcesz odszyfrować wiadomość z pliku? ";
  cin >> nr;

  switch (nr) {
  case 1:
    cout << "\nOdszyfrowana wiadomosc:\n" << OdszyfrujCezar(szyfr);
    break;
  case 2: cout << "\nOdszyfrowana wiadomosc:\n" << OdszyfrujPrzestawianie(szyfr);
    break;
  default:
    cout << "złe dane!";
    break;
  }
}

// Szyfrowanie Cezara
string ZaszyfrujCezar(string wiadomosc) {
  char *szyfr = new char[sizeof(wiadomosc)];

  for (int i = 0; i < sizeof(wiadomosc); i++) {
    szyfr[i] = wiadomosc[i] + 3;
  }
  return (szyfr);
}

// Odszyfrowanie Cezara
string OdszyfrujCezar(string szyfr) {
  char *wiadomosc = new char[sizeof(szyfr)];

  for (int i = 0; i < sizeof(szyfr); i++) {
    wiadomosc[i] = szyfr[i] - 3;
  }

  return (wiadomosc);
}

// Szyfrowanie metoda przestawiania
string ZaszyfrujPrzestawianie(string wiadomosc) {
  int k = 4;
  int w = 3;
  char tab[w][k];
  
 //wpisanie wiadomosci do tablicy
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < k; j++) {
      if (i == 0)
        tab[i][j] = wiadomosc[j];
      if (i == 1)
        tab[i][j] = wiadomosc[4 + j];
      if (i == 2)
        tab[i][j] = wiadomosc[8 + j];
    }
  }

  // wpisanie tablicy do stringa w innej kolejnosci
  char szyfr[12];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < w; j++) {
      szyfr[3 * i + j] = tab[j][i];
    }
  }
  return (szyfr);
}

//Deszyfrowanie metoda przestawiania
string OdszyfrujPrzestawianie(string szyfr){
  int k = 3;
  int w = 4;
  char tab[w][k];

  //wpisanie szyfru do tablicy
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < k; j++) {
      if (i == 0)
        tab[i][j] = szyfr[j];
      if (i == 1)
        tab[i][j] = szyfr[3 + j];
      if (i == 2)
        tab[i][j] = szyfr[6 + j];
      if (i == 3)
        tab[i][j] = szyfr[9 + j];
    }
  }

  // wpisanie tablicy do stringa w innej kolejnosci
  char wiadomosc[12];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < w; j++) {
      wiadomosc[4 * i + j] = tab[j][i];
    }
  }
  return (wiadomosc);
}

