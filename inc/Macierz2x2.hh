#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#define PI 3.14159265


#include <iostream>
#include "Wektor2D.hh"


  // klasa: Macierz2x2 - opisuje strukture danych przedstawiajaca macierz 2 x 2
  // pola:
  // _Tab - dwuwymiarowa tablica przechowujaca elementy macierzy 2 x 2
class Macierz2x2 {

  public:

  float _Tab[2][2];

  // funkcja: przeciazenie operatora funkcyjnego () dla klasy Macierz2x2
  // argumenty:
  // Wiersz - indeks wierszow macierzy
  // Kol - indeks kolumn macierzy
  // funkcja zwraca element tablicy _Tab, wedlug podanych indeksow
  float operator () (int Wiersz, int Kol) const { return _Tab[Wiersz][Kol]; }

  // funkcja: przeciazenie operatora funkcyjnego () dla klasy Macierz2x2
  // argumenty:
  // Wiersz - indeks wierszow macierzy
  // Kol - indeks kolumn macierzy
  // funkcja wczytuje podany element do tablicy _Tab, wedlug podanych indeksow
  float & operator () (int Wiersz, int Kol)  { return _Tab[Wiersz][Kol]; }

    // funkcja: przeciazenie operatora mnozenia * dla klasy Wektor2D i Macierz2x2
  // argumenty:
  // Mac - macierz typu Macierz2x2
  // Wek - wektor typu Wektor2D
  // funkcja zwraca wektor bedacy wynikiem mnozenia macierzy przez wektor
  Wektor2D operator * ( Wektor2D Wek)
  {
    Wektor2D wynik;

    wynik[0] = (Wek[0] * _Tab[0][0]) + (Wek[1] * _Tab[0][1]);
    wynik[1] = (Wek[0] * _Tab[1][0]) + (Wek[1] * _Tab[1][1]);
    return wynik;
  }
  
  };

    // funkcja: przeciazenie operatora << dla typu macierz2x2
  // argumenty:
  // Strm - strumien wyjsciowy z referencja
  // Mac - macierz2x2 do wyswietlenia
  // funkcja zwraca strumien wyjsciowy z referencja
  std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);


#endif
