#ifndef FABRYKA_OB_HH
#define FABRYKA_OB_HH

#include "Wektor2D.hh"
#include "Robot.hh"
#include "Trasa.hh"
#include "Przeszkoda.hh"
#include <memory>
#include <fstream>
#include <unistd.h>

enum TypObiektu { TO_Robot, TO_Sciezka, TO_Przeszkoda };

/*! \brief klasa opisujaca fabryke obiektow   
 */
class Fabryka_Ob {

    static Fabryka_Ob   _Fabryka_Ob;

  public:  

  /*!
    * funkcja: tworzenie wskaznika na obiekt Robot
    * \param[in] wsp - wspolrzedne poczatkowe robota
    * \param[in] wskTrs - wskaznik na trase robota
    */
  static std::shared_ptr<Robot> ZbudujObiektRobot( Wektor2D wsp, std::shared_ptr<Trasa> wskTrs) 
  {
    return _Fabryka_Ob.UtworzObiektRobot(wsp,wskTrs);
  }

  /*!
    * funkcja: tworzenie wskaznika na obiekt Przeszkoda
    * \param[in] wsp - wspolrzedne poczatkowe przeszkody
    * \param[in] rozm - wektor bokow przeszkody
    */
  static std::shared_ptr<Przeszkoda> ZbudujObiektPrzeszkoda(  Wektor2D wsp, Wektor2D rozm ) 
  {
    return _Fabryka_Ob.UtworzObiektPrzeszkoda(wsp,rozm);
  }

  /*!
    * funkcja: tworzenie wskaznika na obiekt Trasa
    */
  static std::shared_ptr<Trasa> ZbudujObiektTrasa() 
  {
    return _Fabryka_Ob.UtworzObiektTrasa();
  }

  private: 

  /*!
    * funkcja: tworzenie obiektu Robot
    * \param[in] wsp - wspolrzedne poczatkowe robota
    * \param[in] wskTrs - wskaznik na trase robota
    */
   std::shared_ptr<Robot> UtworzObiektRobot( Wektor2D wsp, std::shared_ptr<Trasa> wskTrs) const
  {
    std::shared_ptr<Robot> Rob(new Robot(wsp[0],wsp[1],wskTrs));
    return Rob;
  }

  /*!
    * funkcja: tworzenie obiektu Przeszkoda
    * \param[in] wsp - wspolrzedne poczatkowe przeszkody
    * \param[in] rozm - wektor bokow przeszkody
    */
   std::shared_ptr<Przeszkoda> UtworzObiektPrzeszkoda(  Wektor2D wsp, Wektor2D rozm ) const
  {
    std::shared_ptr<Przeszkoda> Prz(new Przeszkoda(wsp[0],wsp[1],rozm[0],rozm[1]));
    return Prz;
  }

  /*!
    * funkcja: tworzenie obiektu Trasa
    */
   std::shared_ptr<Trasa> UtworzObiektTrasa() const
  {
    std::shared_ptr<Trasa> Trs(new Trasa());
    return Trs;
  }
};
#endif
