#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


//funkcja kamien papier nozyczki
void kpn(int n, int m){
    
   if (n==m){
       cout<<"Remis.\n";
   }
   if((n==0 && m==2) || (n==1 && m==0) || (n==2 && m==1)) {
       cout<<"Wygrales!\n";
   }
   if((n==0 && m==1) || (n==1 && m==2) || (n==2 && m==0)) {
       cout<<"Przegrales :(\n";
   }
    
}


int main()
{
       

    cout<<"Gra kamien, papier, nozyczki.\n";

    
    //3 rundy
    for(int x=0; x<3; x++){
        
    srand(time(NULL));
       
    int n;
    string wybor;
    
    cout<<"Podaj swoj wybor: ";
    cin>>wybor; //gracz podaje swoj wybor
    
    
    //zmienianie podanych slow na cyfry
    if (wybor=="kamien") {n=0;}
    if (wybor=="papier") {n=1;}
    if (wybor=="nozyczki") {n=2;}
    
     //losowanie liczby od 0 do 2
    int m = rand()%3;
    

    cout<<"Komputer wylosowal ";
   switch(m){
       case 0: cout<<"kamień.\n";
       break;
       case 1: cout<<"papier.\n";
       break;
       case 2: cout<<"nozyczki.\n";
       break;
   }
    
   kpn(n, m);
   
    }

    return 0;
}
