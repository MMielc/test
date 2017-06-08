#ifndef OBIEKT_GRAF_HH
#define OBIEKT_GRAF_HH

#include "Zbior_Wierzch.hh"
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include <math.h>
#include <iomanip>

/*! \brief klasa: Obiekt_Graf - podstawowa klasa opisujaca obiekt graficzny,
* zawiera zbior wierzcholkow obiektu oraz wektor translacji globalnej
*/
class Obiekt_Graf{

    protected:

     Zbior_Wierzch _wierzch_glob;
     static Wektor2D _trans_glob;

    public:

    static int liczObIst;
    static int liczObStw;

    Obiekt_Graf () {liczObStw++; liczObIst++;}
    ~Obiekt_Graf () {liczObIst--;}
    

    /*!
    * funkcja: zwrocenie wektora globalnego obiektu graficznego
    */
    static Wektor2D wezWekGlob () {return _trans_glob;}

    /*!
    * funkcja: zaktualizowanie wektora globalnego obiektu graficznego
    * \param[in] Wek - wektor translacji
    */
    static void zapiszWekGlob (Wektor2D Wek) {_trans_glob = _trans_glob + Wek;}


    /*!
    * funkcja: wirtualna metoda testu kolizji podanego punktu z obiektem graficznym
    * \param[in] polozenie - wektor polozenia punktu sprawdzenia kolizji 
    * \param[in] promien - promien obszaru zajmowanego przez obiekt
    */
    virtual bool czyKolizja(Wektor2D polozenie, double promien) {return false;}

    /*!
    * funkcja: obrot obiektu graficznego wokol punktu 0,0
    * \param[in] kat - kat obrotu w stopniach  
    */
    void Obrot (float kat);

    /*!
    * funkcja: translacja obiektu graficznego o podany wektor
    * \param[in] Wek - wektor translacji 
    */
    void Translacja (Wektor2D Wek); 

    /*!
    * funkcja: dodanie kolejnego wektora do zbioru wierzcholkow
    * \param[in] Wek - wektor translacji 
    */
    void DodajWierzch(Wektor2D Wek);

    /*!
    * funkcja: przeciazenie operatora wyjscia dla klasy Obiekt_Graf
    * \param[in] Strm - strumien wyjsciowy z referencja
    * \param[in] obj - docelowy obiekt graficzny
    */
    friend std::ostream & operator << (std::ostream & Strm, Obiekt_Graf obj ); 
};
    void wyswietlStatOG(std::ostream &strm);
#endif
