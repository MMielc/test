#ifndef ROBOT_HH
#define ROBOT_HH
#include "Wektor2D.hh"
#include "Zbior_Wierzch.hh"
#include "Obiekt_Graf.hh"
#include "Macierz2x2.hh"
#include "Przeszkoda.hh"
#include "Trasa.hh"
#include "memory"

#define promien 35

/*! \brief klasa pochodna od klasy Obiekt_Graf, opisuje 
* konstrukcje obiektu Robot
*/
class Robot: public Obiekt_Graf{

  Zbior_Wierzch wierz_lok;
  Wektor2D pozycja;
  double kat_rotacji;
  int predkosc;
  std::shared_ptr<Trasa> wskNaTraseRobota;

  public: 

  std::shared_ptr<Trasa> WezWskNaTrase() {return wskNaTraseRobota;}

    /*!
    * funkcja: konstruktor klasy Robot
    */
    Robot (double x, double y, std::shared_ptr<Trasa> wskTrs); 

    /*!
    * funkcja: obrot robota wokol wlasnej osi
    * \param[in] kat - kat obrotu w stopniach  
    */
    void Obrot (double kat);

    /*!
    * funkcja: translacja robota o podany wektor
    * \param[in] Wek - wektor translacji 
    */
    void Przesuniecie (Wektor2D Wek);

    /*!
    * funkcja: ruch robota do przodu o podana odleglosc
    * \param[in] dlugosc_kroku - dlugosc kroku jaki ma zrobic robot
    */
    void RuchWPrzod (double dlugosc_kroku);

    /*!
    * funkcja: podbranie aktualnej pozycji robota
    */
    Wektor2D wezPozycje() {return _wierzch_glob.zwrocWierzcholek(0);}

    /*!
    * funkcja: zmiana predkosci robota
    * \param[in] pred - zadana predkosc robota
    */
    void zmienPredkosc(int pred) {predkosc = pred;}

    /*!
    * funkcja: pobranie wartosci predkosci robota
    */
    int wezPredkosc() {return predkosc;}

    /*!
    * funkcja: sprawdzenie kolizji z obiektem typu przeszkoda
    * \param[in] prz - obiekt typu Przeszkoda
    */
	  //bool czyKolizjaZPrzeszkoda(Przeszkoda prz);

    /*!
    * funkcja: sprawdzenie kolizji z obiektem typu robot
    * \param[in] prz - obiekt typu Robot
    */
	  //bool czyKolizjaZRobotem(Robot rbt);

    /*!
    * funkcja: rysowanie trasy za robotem
    * \param[in] &trs - obiekt typu trasa
    */
    void RysujTrase(Obiekt_Graf &trs);

    /*!
    * funkcja: sprawdzenie kolizji z obiektem graficznym - Robot
    * \param[in] polozenie - wektor punktu sprawdzenia kolizji
    * \param[in] R - promien obszaru zajmowanego przez robota
    */
    virtual bool czyKolizja(Wektor2D polozenie, double R);

    void zapiszWekPoz (Wektor2D wek) {pozycja = pozycja + wek;}
};
#endif
