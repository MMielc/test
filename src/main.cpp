#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include "Obiekt_Graf.hh"
#include "Zbior_Wierzch.hh"
#include "Robot.hh"
#include "Scena.hh"
#include "Trasa.hh"

using namespace std;

void wyswietlMenu(ostream& Strm)
{
  Strm<<"\n"
  "z - zmiana szybkosci ruchu robota\n"
  "o - obrot robota\n"
  "j - jazda na wprost\n"
  "s - selekcja robota\n"
  "t - zadaj translacje rysunku\n"
  "p - powrot do pierwotnego ustawienia rysunku\n"
  "w - wyswietl ponownie menu\n"
  "k - zakoncz dzialanie programu"<<endl<<endl;
}

int main()
{
 char znak;
 int identyfikator = 0;
  PzG::LaczeDoGNUPlota  Lacze;

  Scena SCN(Lacze);
  Scena bck(Lacze);

  

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("scena.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  //Lacze.DodajNazwePliku("scena.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  // bck.wyswietlScene();
  
  // int costam=10;

  // while(costam!=0){
  // cin>>costam;

  // if (costam == 1)
  // {
  //  int id;
  //  double kat;
  //  cout<<"podaj id i kat: "<<endl;
  //  cin>>id>>kat;
  //  bck.obrotRobota(kat,id-1);
  // } 

  // if (costam == 2)
  // {
  //   int id;
  //   double dlugosc;
  //   cout<<"podaj id i dlugosc ruchu: "<<endl;
  //   cin>>id>>dlugosc;
  //   if(bck.ruchRobota(dlugosc,id-1))
  //   {
  //     cout<<"\n\n !!!KOLIZJA!!!\n\n"<<endl;
  //   }
  // }

  // } return 0;
  SCN.wyswietlScene();
  wyswietlMenu(cout); 
  wyswietlStat(cout);

while(znak != 'k')
{

  cout<<" Aktualnie wyselekcjonowanym robotem jest:\n"
	" Robot "<<identyfikator + 1<<".    Wspolrzedne: "<< SCN.wezPozRob(identyfikator) <<endl<<endl;
  cout<<"Twoj wybor? (w - menu)"<<endl;
  cin>>znak;
  
  switch (znak)
  {
    case 'z': 
    {
      int P;
      cout<<" Podaj predkosc w skali:1 - szybko, 10 - wolno: "<<endl;
      cin>>P;
      SCN.zmienPredkoscRobota(P,identyfikator);
    }
    break;

    case 'o':
    {
      double kat;
      cout<<" Podaj wartosc kata obrotu w stopniach: "<<endl;
      cin>>kat;
      SCN.obrotRobota(kat,identyfikator); 
    }
    break;

    case 'j':
    {
      double DL;
      cout<<" Podaj dlugosc ruchu robota na wprost: "<<endl;
      cin>> DL;
      if(SCN.ruchRobota(DL,identyfikator))
      {
      cout<<"\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
      cout<<" !!!ruch powstrzymany przez kolizje!!!"<<endl;
      cout<<" !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"<<endl;
      }
    }
    break;

    case 's':
    {
      int tmp;
      for(int i=0;i<3;i++)
      cout<<" Robot "<<i+1<<".    Wspolrzedne: "<< SCN.wezPozRob(i) <<endl;
      cout<<endl;
    	cout<<" Podaj numer robota, ktory ma byc obslugiwany: "<<endl;
		  cin>>tmp;
      identyfikator = tmp -1;
    }
    break;

    case 't':
    {
      Wektor2D przes;
      cout<<"Podaj wspolrzedne wektora translacji: "<<endl;
      cin>>przes;
      SCN.przesuniecie(przes); 
    }
    break;

    case 'p':
      SCN = bck;
      SCN.wyswietlScene();
      cout<<"przyrocono domyslna scene"<<endl; 
    break;

    case 'w':
      wyswietlMenu(cout); 
    break;

    case 'k':
      cout<<"Koniec dzialania programu"<<endl;
      wyswietlStatOG(cout);
      return 0;
    break;

    default:
      cout<<"Niepoprawne dane"<<endl;
    break;
  }


}
}
