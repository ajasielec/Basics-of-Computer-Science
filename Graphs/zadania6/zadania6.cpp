#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


//ZADANIE 1
void Zadanie1() {

    int i, j;
    int tab_mn[9][9];

    //utworzynie tabliczki mnozenia
    //przypisanie wartosci do tablicy dwuwymiarowej
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            tab_mn[i][j] = { (j + 1) * (i + 1) };

        }
    }

    //zapis tabliczki do pliku
    fstream tabmn;
    tabmn.open("tabliczka_mnozenia.txt", ios::out);

    tabmn << "Tabliczka mnozenia:\n";
    //wyswietlenie tablicy
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tabmn.width(5);
            tabmn << tab_mn[i][j];
        }
        tabmn << endl;
    }

    tabmn.close();
}





//ZADANIE 2
void Zadanie2() {

    string haslo, haslo2;
    cout << "Podaj jakie chcesz miec haslo: ";
    cin >> haslo;

    //wpisywanie hasla do pliku
    fstream plik_haslo;
    plik_haslo.open("haslo.txt", ios::out);

    plik_haslo << haslo;
    plik_haslo.close();

    //wpisywanie hasla i sprawdzanie czy jest takie samo jak to w pliku
    plik_haslo.open("haslo.txt", ios::in);

    if (plik_haslo.good() == false) {
        cout << "Plik nie istnieje." << endl;
        exit(0);
    }

    cout << "Podaj haslo zapisane w pliku: ";
    cin >> haslo2;

    if (haslo2 == haslo) { cout << "Haslo sie zgadza.\n"; }
    else { cout << "Haslo sie nie zgadza.\n"; }

    plik_haslo.close();
}




//ZADANIE3
/*Napisz program który wczytuje podan¹ przez u¿ytkownika liczbê wierzcho³ków i krawêdzi oraz pary wierzcho³ków,
    a nastêpnie wyœwietla macierz s¹siedztwa */
void Zadanie3() {

    int n, m, x, y, i, j;
    cout << "Podaj liczbe wierzcholkow: "; cin >> n;
    cout << "Podaj liczbe krawedzi: "; cin >> m;

    //tworzenie tablicy dynamicznej dwuwymiarowej, ktora bedzie miacierza sasiedztwa
    int** tab;
    tab = new int* [n];

    for (i = 0; i < n; i++) {
        tab[i] = new int[n]; //tworzenie wierszy
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            tab[i][j] = 0; //wypelnienie zerami
        }
    }

    for (i = 0; i < m; i++) {
        cout << "Podaj " << i + 1 << " pare krawedzi:\n";
        cin >> x >> y;
        tab[x][y] = 1; //wpisywanie 1 tam gdzie jest krawedz
    }

    //wypisanie macierzy
    cout << "Macierz sasiedztwa dla tego grafa:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout.width(4);
            cout << tab[i][j];
        }

        cout << endl;
    }

    //USUWANIE MI NIE DZIALA
    for (int i = 0; i < n; i++) { //usuwamy macierz z pamieci
        delete[]tab[i];
    }
    delete[] tab;
}



//ZADANIE 4
//Zmieñ program z zad.3 w taki sposób aby wczytywa³ dane z pliku.
void Zadanie4() {

    fstream graf;
    
    //wczytanie z pliku krawedzi i wierzcholkow
    graf.open("graf.txt", ios::in);

    if (graf.good() == false) {
        cout << "Plik nie istnieje." << endl;
        exit(0);
    }
    
    int m, n, x, y, i, j;
    graf >> n >> m; // n - krawedzie, m - wierzcholki
    // cout << m << endl << n; //$kontrolne

    int** tab;
    tab = new int* [n];

    for (i = 0; i < n; i++) {
        tab[i] = new int[n]; //tworzenie wierszy
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            tab[i][j] = 0; //wypelnienie zerami
        }
    }


    for ( i = 0; i < n; i++)
    {
        graf >> x;
        graf >> y;
        tab[x][y] = 1;
    }

    graf.close();

    //wypisanie macierzy
    cout << "Macierz sasiedztwa dla tego grafa:\n";
    for (int i = 0; i < n; i++) {
        // cout << "v" <<i<<endl;

        for (int j = 0; j < n; j++) {
            // cout << "v" << i;
            cout.width(4);
            cout << tab[i][j];
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++) { //usuwamy macierz z pamieci
        delete[]tab[i];
    }
    delete[] tab;
}


int main() {

    int nr;

    for (;;) {
        cout << "\nPodaj numer zadania: ";
        cin >> nr;

        switch (nr) {
        case 1: Zadanie1();
            break;
        case 2: Zadanie2();
            break;
        case 3: Zadanie3();
            break;
        case 4: Zadanie4();
            break;
        default: return(-1);
        }
    }
    return 0;
}


