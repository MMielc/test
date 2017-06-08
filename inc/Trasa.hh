#ifndef TRASA_HH
#define TRASA_HH
#include "Wektor2D.hh"
#include "Zbior_Wierzch.hh"
#include "Obiekt_Graf.hh"
#include "Robot.hh"

/*! \brief klasa: Trasa - klasa pochodna od klasy Obiekt_Graf
*/
class Trasa: public Obiekt_Graf{

    public:
    
    /*!
    * funkcja: sprawdzenie kolizji z obiektem graficznym - Trasa
    * \param[in] polozenie - wektor punktu sprawdzenia kolizji
    * \param[in] R - promien obszaru zajmowanego przez obiekt
    */
    virtual bool czyKolizja(Wektor2D polozenie, double R) {return false;}
};

#endif
