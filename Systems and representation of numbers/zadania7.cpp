//Anna Jasielec, zajecia 7
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int BINnaDEC(string bin);
string DECnaBIN(int dec);
string BINnaHEX(string bin);
string OCTnaBIN(string oct);
int HEXnaDEC(string hex);


int main() {
   // ZADANIE 2
   //Na podstawie przedstawionych wcześniej sposobów konwersji liczb napisz funkcję, która:
   char nr;
   string bin, oct, hex;
   int dec;
   cout << "Zadanie 2.\n";
   cout << "[a] - zamiana DEC na BIN" << endl;
   cout << "[b] - zamiana DEC na HEX" << endl;
   cout << "[c] - zamiana BIN na DEC" << endl;
   cout << "[d] - zamiana BIN na HEX" << endl;
   cout << "[e] - zamiana OCT na BIN" << endl;
   cout << "[f] - zamiana HEX na DEC" << endl;
   cout << "[g] - zamiana OCT na HEX";


   for(;;){
   cout << "\n\nKtory podpunkt chcesz zobaczyc? ";
   cin>>nr;

    switch(nr){
      case 'a':  //a)  przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie binarnym
        cout << "Podaj liczbę w systemie dziesiętnym: ";
        cin >> dec;
        cout << "Liczba " << dec << " w systemie binarnym to: " << DECnaBIN(dec);
        break;
      
      case 'b': //b) przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie szesnastkowym.
        cout << "Podaj liczbę w systemie dziesiętnym: ";
        cin >> dec;
        cout << "Liczba " << dec << " w systemie szesnastkowym to: " << BINnaHEX(DECnaBIN(dec));
        break;
      
      case 'c': //c) przyjmie liczbę z systemu binarnego i zwróci jej odpowiednik w systemie dziesiętnym. 
        cout << "Podaj liczbe w systemie binarnym: ";
        cin >> bin;
        cout << "Liczba " << bin << " w systemie dziesiętnym to: " << BINnaDEC(bin);
        break;
      
      case 'd': //d) przyjmie liczbę z systemu binarnego i zwróci jej odpowiednik w systemie szesnastkowym. 
        cout << "Podaj liczbe w systemie binarnym: ";
        cin >> bin;
        cout << "Liczba " << bin << " w systemie szesnastkowym to: " << BINnaHEX(bin);
        break;
      
      case 'e': //e) przyjmie liczbę z systemu ósemkowego i zwróci jej odpowiednik w systemie binarny. 
        cout << "Podaj liczbe w systemie ósemkowym: ";
        cin >> oct;
        cout << "Liczba " << oct << " w systemie binarnym to: " << OCTnaBIN(oct);
        break;
      
      case 'f': //przyjmie liczbę z systemu szesnastkowego i zwróci jej odpowiednik w systemie dziesiętnym.
        cout << "Podaj liczbe w systemie szesnastkowym: ";
        cin >> hex;
        cout << "Liczba " << hex << " w systemie dziesietnym to: " << HEXnaDEC(hex);
      break;
      
      case 'g': // przyjmie liczbę z systemu ósemkowego i zwróci jej odpowiednik w systemie szesnastkowym.
        cout << "Podaj liczbę w systemie ósemkowym: ";
        cin >> oct;
        cout << "Liczba " << oct << " w systemie szesnastkowym to: " << BINnaHEX(OCTnaBIN(oct));
      break;
      
      default: cout<<"Zle dane!"; break;            
    }  
  }
  }




// funkcja zamieniajaca z systemu dziesietnego na binarny
string DECnaBIN(int dec) {

  int counter = 0;
  int temp = dec;

  // zliczanie ile bedzie cyfr
  do {
    temp = temp / 2;
    counter++;
  } while (temp != 0);

  // tworzenie tablicy cyfr binarnych
  int *bin = new int[counter];

  // uzupelnienie tablicy resztami z dzielenia
  int reszta;
  for (int i = 0; i < counter; i++) {
    reszta = dec % 2;
    bin[i] = reszta;
    dec = dec / 2;
  }

  //odwracanie i zamiana na tablice znakow
  char* bin_char = new char [counter];
  int j = 0, i = counter - 1, temp2;
  while (i>=0){
    temp2 = bin[i];
    bin_char[j] = (char)temp2 + 48;
    j++;
    i--;
  }
  return (bin_char);
}



// funkcja zamieniajaca binarna na dziesietna
int BINnaDEC(string bin) {

  int rozmiar = bin.length();
  int *tab_bin = new int[bin.length()];

  //zmiana tablicy charow na tablice intow
  char temp;
  for (int i = 0; i < rozmiar; i++) {
    temp = bin[i];
    tab_bin[i] = (int)temp - 48;
  }

  //sumowanie poteg dwojki 
  int suma = 0, i = 0;
  while (i < rozmiar) {
    if (tab_bin[i] == 1) {
      suma += pow(2, rozmiar-1-i);
      i++;
    } else
      i++;
  }
  
  return (suma);
}



// funkcja zamieniajaca binarna na szesnastkowa
string BINnaHEX(string bin) {

  int rozmiar = bin.length();
  int *tab_bin = new int[bin.length()];

  // tablica cyfr binarnych
  char temp;
  for (int i = 0; i < rozmiar; i++) {
    temp = bin[i];
    tab_bin[i] = (int)temp - 48;
  }

  // obliczenie rozmiaru tablicy cyfr szesnastkowych i stworzenie jej
  int hex_size = rozmiar / 4;
  if (rozmiar % 4 != 0) {
    hex_size += 1;
  }

  int *wynik = new int[hex_size];

  // analizowanie tablicy cyfr binarnych i dodawanie odpowiednich wartosc do
  // tablicy cyfr osemkowych
  for (int i = rozmiar - 1; i >= 0; i -= 4) {
    if (tab_bin[i] == 1) {
      wynik[i / 4] += 1;
    }
    if (i > 0)
      if (tab_bin[i - 1] == 1)
        wynik[i / 4] += 2;
    if (i > 1)
      if (tab_bin[i - 2] == 1)
        wynik[i / 4] += 4;
    if (i > 2)
      if (tab_bin[i - 3] == 1)
        wynik[i / 4] += 8;
  }

  // zamienie tablicy intow na charow
  char *hex_char = new char[hex_size];
  int temp1;
  for (int i = 0; i < hex_size; i++) {
    temp1 = wynik[i];
    hex_char[i] = (char)temp1 + 48;
  }

  //zamiana cyfr od 10 do 15 na litery, dodaje 48 aby zgadzalo sie z tabela ASCII
  for (int i = 0; i < hex_size; i++) {
    if (hex_char[i] == 10 + 48)
      hex_char[i] = 'A';
    if (hex_char[i] == 11 + 48)
      hex_char[i] = 'B';
    if (hex_char[i] == 12 + 48)
      hex_char[i] = 'C';
    if (hex_char[i] == '=')
      hex_char[i] = 'D';
    if (hex_char[i] == 14 + 48)
      hex_char[i] = 'E';
    if (hex_char[i] == 15 + 48)
      hex_char[i] = 'F';
    }
    return (hex_char);
  }


  // funkcja zamieniajaca osemkowa na binarna
  string OCTnaBIN(string oct){

    int oct_size = oct.length();
    int *tab_oct = new int[oct.length()];

    // tablica cyfr osemkowych
    char temp;
    for (int i = 0; i < oct_size; i++) {
      temp = oct[i];
      tab_oct[i] = (int)temp - 48;
    }

    // tablica cyfr binarnych
    int bin_size = oct_size * 3;
    int *tab_bin = new int[bin_size];

    // wpisanie do tablicy binarnej jednynek w odpowiednich miejscach
    for (int i = oct_size - 1; i >= 0; i--) {
      switch (tab_oct[i]) {
      case 0:
        break;
      case 1:
        tab_bin[(i + 1) * 3 - 1] = 1;
        break;
      case 2:
        tab_bin[(i + 1) * 3 - 2] = 1;
        break;
      case 3:
        tab_bin[(i + 1) * 3 - 1] = 1;
        tab_bin[(i + 1) * 3 - 2] = 1;
        break;
      case 4:
        tab_bin[(i + 1) * 3 - 3] = 1;
        break;
      case 5:
        tab_bin[(i + 1) * 3 - 1] = 1;
        tab_bin[(i + 1) * 3 - 3] = 1;
        break;
      case 6:
        tab_bin[(i + 1) * 3 - 2] = 1;
        tab_bin[(i + 1) * 3 - 3] = 1;
        break;
      case 7:
        tab_bin[(i + 1) * 3 - 1] = 1;
        tab_bin[(i + 1) * 3 - 2] = 1;
        tab_bin[(i + 1) * 3 - 3] = 1;
        break;
      default:
        cout << "Wpisales zla liczbe!" << endl;
      }
    }

    // zamiana int na string
    char* bin_str = new char [bin_size];
    int temp1;
    for(int i=0; i<bin_size; i++){
      temp1 = tab_bin[i];
      bin_str[i] = (char)temp1+48;
    }
   return (bin_str);  
  }


//funkcja zamieniajaca szesnastkowa na dziesietna
int HEXnaDEC(string hex){

  int hex_size = hex.length();
  int x = 1, suma = 0;

  for (int i = hex_size - 1; i>=0; i--){
    if(hex[i] >= '0' && hex[i] <= '9'){
    suma += (hex[i] - 48) * x;
    x *= 16; 
      }
    
    if(hex[i] >= 'A' && hex[i] <= 'F'){
      suma += (hex[i] - 55) * x;
      x *= 16;
    }
    }

  return (suma); 
}


// funkcja zamieniajaca binarna na osemkowa
void BINnaOCT(string bin) {

  int rozmiar = bin.length();
  int *tab_bin = new int[bin.length()];

  // tablica cyfr binarnych
  char temp;
  for (int i = 0; i < rozmiar; i++) {
    temp = bin[i];
    tab_bin[i] = (int)temp - 48;
  }

  // obliczenie rozmiaru tablicy cyfr osemkowych i stworzenie jej
  int oct_size = rozmiar / 3;
  if (rozmiar % 3 != 0) {
    oct_size += 1;
  }

  int *wynik = new int[oct_size];

  // analizowanie tablicy cyfr binarnych i dodawanie odpowiednich wartosc do
  // tablicy cyfr osemkowych
  for (int i = rozmiar - 1; i >= 0; i -= 3) {
    if (tab_bin[i] == 1) {
      wynik[i / 3] += 1;
    }
    if (i > 0)
      if (tab_bin[i - 1] == 1)
        wynik[i / 3] += 2;
    if (i > 1)
      if (tab_bin[i - 2] == 1)
        wynik[i / 3] += 4;
  }

  // wypisanie tablicy
  for (int i = 0; i < oct_size; i++) {
    cout << wynik[i];
  }
}