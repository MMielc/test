#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "Wektor2D.hh"
#include "Zbior_Wierzch.hh"
#include "Obiekt_Graf.hh"
#include "Macierz2x2.hh"

/*! \brief klasa opisujaca obiekt przeszkody. Klasa pochodna od klasy Obiekt_Graf   
 */
class Przeszkoda: public Obiekt_Graf{

  Zbior_Wierzch wierz_lok;
  Wektor2D pozycja;

  public:

  /*!
  * funkcja: konstruktor klasy Przeszkoda
  */
  Przeszkoda(double x, double y, double a, double b);

  /*!
    * funkcja: sprawdzenie kolizji z obiektem graficznym - Przeszkoda
    * \param[in] polozenie - wektor punktu sprawdzenia kolizji
    * \param[in] R - promien obszaru zajmowanego przez obiekt
    */
  virtual bool czyKolizja(Wektor2D polozenie, double R);
};
#endif
