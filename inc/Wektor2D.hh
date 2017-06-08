#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#include <iostream>

class Wektor2D {

  public:

  float _wsp[2];
  static int liczWekIst;
  static int liczWekStw;

  Wektor2D (int x, int y) {_wsp[0] = x; _wsp[1] = y; liczWekStw++; liczWekIst++;}

  Wektor2D () {_wsp[0]=0;_wsp[1]=0; liczWekStw++; liczWekIst++;}

  ~Wektor2D () {liczWekIst--;}

  
  // funkcja: przeciazenie operatora indeksujacego [] dla klasy Wektor2D
  // argumenty:
  // ind - indeks wspolrzednych wektora
  // funkcja zwraca wspolrzedna wektora odpowiadajaca indeksowi
  float operator[] (int ind) const { return _wsp[ind];}

  // funkcja: przeciazenie operatora indeksujacego [] dla klasy Wektor2D
  // argumenty:
  // ind - indeks wspolrzednych wektora
  // funkcja wczytuje element do wspolrzednych wektora odpowiadajacym indeksowi
  float& operator[] (int ind)  { return _wsp[ind];}

  // funkcja: przeciazenie operatora dodawania + dla klasy Wektor2D
  // argumenty:
  // Wek - wektor dodawany do wektora bazowego
  // funkcja zwraca wektor bedacy suma podanych dwoch wektorow
  Wektor2D operator + (Wektor2D Wek)
  {
    Wek[0] += _wsp[0];
    Wek[1] += _wsp[1];
    return Wek;
  }    

  // funkcja: przeciazenie operatora odejmowania - dla klasy Wektor2D
  // argumenty:
  // Wek - wektor odejmowany od wektora bazowego
  // funkcja zwraca wektor bedacy roznica podanych dwoch wektorow
  Wektor2D operator - (Wektor2D Wek)
  {
    Wektor2D wynik;
     wynik[0] = _wsp[0]- Wek[0];
     wynik[1] = _wsp[1]- Wek[1];
    return wynik;
  }  

  Wektor2D operator * (double mnoznik)
  {
    Wektor2D wynik;

    wynik[0] = wynik[0] * mnoznik;
    wynik[1] = wynik[1] * mnoznik;

    return wynik;
  }
};
   void wyswietlStat(std::ostream &str);

  // funkcja: przeciazenie operatora wejscia >> dla typu Wektor2D 
  // argumenty:
  // Strm - strumien wejscia z referencja
  // Wek - wektor do wczytania z referencja
  // funkcja zwraca strumien wejscia z referencja
  std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

  // funkcja: przeciazenie operatora wyjscia << dla klasy Wektor2D
  // argumenty:
  // Wek - wektor do wyswietlenia na wyjsciu
  // Strm - strumien wyjscia z referencja
  // funkcja zwraca strumien wyjscia z referencja
  std::ostream& operator << (std::ostream &Strm,  Wektor2D Wek);

  // funkcja: obliczenie odleglosciu pomiedzy dwoma punktami
  // argumenty:
  // Wek1 - pierwszy punkt 
  // Wek1 - drugi punkt
  // funkcja zwraca wartosc odleglosci pomiedzy podanymi punktami
  float odlgPkt (Wektor2D Wek1,Wektor2D Wek2);

#endif
