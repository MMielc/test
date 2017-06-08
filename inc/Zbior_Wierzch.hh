#ifndef ZBIOR_WIERZCH_HH
#define ZBIOR_WIERZCH_HH

#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include <vector>
#include <math.h>
#include <iomanip>

/*! \brief klasa: Zbior_Wierzch - klasa opisujaca zbior wierzcholkow 
* _wierzch - zbior wierzcholkow
*/
class Zbior_Wierzch{

    std::vector <Wektor2D> _wierzch;

    public:

    Wektor2D zwrocWierzcholek(int numer) {return _wierzch[numer];}


    /*!
    * funkcja: dodanie punktu do tablicy wierzcholkow
    * \param[in] Wek - wektor wierzcholka
    */
    void dodajWierzch(Wektor2D Wek);

    /*!
    * funkcja: translacja punktu
    * \param[in] Wek - wektor translacji
    */
    void przesun(Wektor2D Wek);

    /*!
    * funkcja: obrot figury
    * \param[in] kat - kat obrotu
    */
    std::vector <Wektor2D> obroc(double kat);

    /*!
    * funkcja: przeciazenie operatora wyjscia dla klasy Zbior_Wierzch
    * \param[in] Strm - strumien wyjsciowy
    * \param[in] zb - obiekt klasy Zbior_Wierzch z referencja
    */
    friend std::ostream & operator << ( std::ostream & Strm, Zbior_Wierzch & zb);
};
#endif
