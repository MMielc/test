#ifndef SCENA_HH
#define SCENA_HH

#include "Obiekt_Graf.hh"
#include "Wektor2D.hh"
#include "Obiekt_Graf.hh"
#include "Zbior_Wierzch.hh"
#include "Trasa.hh"
#include "Robot.hh"
#include "lacze_do_gnuplota.hh"
#include "Przeszkoda.hh"

#include <memory>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>

/*! \brief klasa: Scena - przechowuje wszystkie elementy graficzne
* w liscie inteligentnych wskaznikow
*/
class Scena{

  PzG::LaczeDoGNUPlota  Lacze;

  std::list<std::shared_ptr<Obiekt_Graf>> LST;
  std::list<std::shared_ptr<Robot>> LST_rbt;

  public:

  /*!
  * funkcja: konstruktor klasy Scena
  * \param[in] lcz - lacze do gnuplota
  */
  Scena (PzG::LaczeDoGNUPlota  lcz);

  /*!
  * funkcja: zwrocenie wskaznika na obiekt typu Robot wedlug identyfikatora
  * \param[in] id - identyfikator robota ( 0 - 2)
  */
  std::shared_ptr<Robot> zwrocWskRobota( int id );

  /*!
  * funkcja: obrot sceny wokol punktu 0,0
  * \param[in] kat - kat obrotu
  */
  void obrot (double kat);

  /*!
  * funkcja: przesuniecie sceny o zadany wektor
  * \param[in] Wek - wektor translacji
  */
  void przesuniecie (Wektor2D Wek);
  
  /*!
  * funkcja: zapis wspolrzednych sceny do strumienia
  * \param[in] StrmWy - strumien wyjsciowy
  * \param[in] Scn - scena docelowa
  */
   void ZapisWspolrzednychDoStrumienia_Scena( std::ostream & StrmWy);

  /*!
  * funkcja: ruch elementu sceny robot o podana odleglosc
  * \param[in] dl_kroku - docelowa odleglosc ruchu
  * \param[in] id - identyfikator robota
  */
  bool ruchRobota(double dl_kroku, int id);

  /*!
  * funkcja: obrot elementu sceny robot o podany kat
  * \param[in] kat - kat obrotu
  * \param[in] id - identyfikator robota
  */
  void obrotRobota(double kat, int id);

  /*!
  * funkcja: zmiana predkosci robota
  * \param[in] PR - zadana predkosc
  * \param[in] id - identyfikator robota
  */
  void zmienPredkoscRobota(int PR, int id);

  /*!
  * funkcja: zapis wspolrzednych sceny do pliku
  * \param[in] sNazwaPliku - nazwa pliku
  */
  bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku);

  /*!
  * funkcja: wyswietlenie scey w programie gnuplot
  */
  void wyswietlScene();

  /*!
  * funkcja: pobranie aktualnej pozycji robota
  * \param[in] id - identyfikator robota
  */
	Wektor2D wezPozRob (int id) {return zwrocWskRobota(id)->wezPozycje();}

  /*!
  * funkcja: rysowanie trasy robota
  * \param[in] id - identyfikator robota
  */
  void rysujTraseRobota (int id);
};
#endif
