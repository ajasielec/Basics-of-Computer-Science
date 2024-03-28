#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
  string slowo_w_pliku;

  // odczyt slowa z pliku
  fstream plik;
  plik.open("plik.txt", ios::in);
  plik >> slowo_w_pliku;
  plik.close();

  // odwracanie slowa
  char *tab_rev = new char[slowo_w_pliku.length()];
  for (int i = 0; i < slowo_w_pliku.length(); i++) {
    tab_rev[i] = slowo_w_pliku[slowo_w_pliku.length() - 1 - i];
  }

  // sprawdzanie czy slowa sa takie same
  if (tab_rev == slowo_w_pliku)
    cout << "Slowo jest palindromem";
  else
    cout << "Slowo nie jest palindromem";

  return 0;
}