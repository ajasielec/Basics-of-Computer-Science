#include <algorithm>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// BUBBLE SORT
void BubbleSort(int *tab, int n) {
  clock_t start, stop;
  long double czas;
  start = clock();
  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= 1; j--) {
      if (tab[j] < tab[j - 1]) {
        swap(&tab[j], &tab[j - 1]);
      }
    }
  }
  stop = clock();
  czas = (double)(stop - start) / CLOCKS_PER_SEC;
  cout << "\nBubble Sort: " << czas <<" s\n";
}

// QUICK SORT
void QuickSort(int *tab, int lewy, int prawy) {
  if (prawy <= lewy)
    return;

  int i = lewy - 1, j = prawy + 1,
      pivot = tab[(lewy + prawy) / 2]; // wybieramy punkt odniesienia

  while (1) {
    // szukam elementu wiekszego lub rownego piwot stojacego
    // po prawej stronie wartosci pivot
    while (pivot > tab[++i])
      ;

    // szukam elementu mniejszego lub rownego pivot stojacego
    // po lewej stronie wartosci pivot
    while (pivot < tab[--j])
      ;

    // jesli liczniki sie nie minely to zamień elementy ze soba
    // stojace po niewlasciwej stronie elementu pivot
    if (i <= j)
      swap(tab[i], tab[j]);
    else
      break;
  }

  if (j > lewy)
    QuickSort(tab, lewy, j);
  if (i < prawy)
    QuickSort(tab, i, prawy);
}

// HEAP SORT
// funkcja uzywana w heap sort
void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void HeapSort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
}

// SELECTION SORT
void SelectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
    int temp = array[min_idx];
  }
}

int main() {
  
  clock_t start, stop;
  long double czas;
  
  // Z.1
  // a) Stwórz tablice dynamiczne liczb całkowitych o rozmiarach: 1 000, 10 000,
  // 30 000, 60 000, 100 000.
  int rozmiar;
  cout << "Podaj rozmiar tablicy: ";
  cin >> rozmiar;

  int *tablica1 = new int[rozmiar];

  // Przypisz elementom losowe wartości z zakresu od 1 do 1000.
  srand(time(NULL));
  for (int i = 0; i < rozmiar; i++) {
    tablica1[i] = rand() % 1000 + 1;
  }
/*
  cout<<"Utworzona tablica losowych wartości:\n";
    for (int i = 0; i < rozmiar; i++) {
    cout << tablica1[i] << " ";
  }
*/
  //mierzenie czasu wykonywania sortowań
cout << "\n\nCzasy sortowania tablicy o rozmiarze "<<rozmiar<<" dla poszczególnych metod sortowania.\n";

  //Bubble sort
  BubbleSort(tablica1, rozmiar);

  //Quick sort
  start = clock();
  QuickSort(tablica1, 0, rozmiar-1);
  stop = clock();
  czas = (long double)(stop - start) / CLOCKS_PER_SEC;
  cout << "Quick Sort: " << czas <<" s\n";

  //Heap sort
  start = clock();
  HeapSort(tablica1, rozmiar);
  stop = clock();
  czas = (double)(stop - start) / CLOCKS_PER_SEC;
  cout << "Heap Sort: " << czas <<" s\n";

  //Selection sort
  start = clock();
  SelectionSort(tablica1, rozmiar);
  stop = clock();
  czas = (double)(stop - start) / CLOCKS_PER_SEC;
  cout << "Selection Sort: " << czas <<" s\n";
  
  // wyswietllanie tablicy
  /*
  cout << "\nPosortowana tablica:\n";
  for (int i = 0; i < rozmiar; i++) {
    cout << tablica1[i] << " ";
  }
  */

}