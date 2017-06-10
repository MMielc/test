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

    // static std::shared_ptr<Obiekt_Graf> Zbuduj( TypObiektu  TypOb , Wektor2D wsp, Wektor2D rozm)
    // {
    //   return _Fabryka_Ob.UtworzObiekt(TypOb, wsp, rozm);
    // }

  

  static std::shared_ptr<Robot> ZbudujObiektRobot( Wektor2D wsp, std::shared_ptr<Trasa> wskTrs) 
  {
    return _Fabryka_Ob.UtworzObiektRobot(wsp,wskTrs);
  }

  static std::shared_ptr<Przeszkoda> ZbudujObiektPrzeszkoda(  Wektor2D wsp, Wektor2D rozm ) 
  {
    return _Fabryka_Ob.UtworzObiektPrzeszkoda(wsp,rozm);
  }

  static std::shared_ptr<Trasa> ZbudujObiektTrasa() 
  {
    return _Fabryka_Ob.UtworzObiektTrasa();
  }

  private: /* -------------------------------------------------------------------*/

   std::shared_ptr<Robot> UtworzObiektRobot( Wektor2D wsp, std::shared_ptr<Trasa> wskTrs) const
  {
    std::shared_ptr<Robot> Rob(new Robot(wsp[0],wsp[1],wskTrs));
    return Rob;
  }

   std::shared_ptr<Przeszkoda> UtworzObiektPrzeszkoda(  Wektor2D wsp, Wektor2D rozm ) const
  {
    std::shared_ptr<Przeszkoda> Prz(new Przeszkoda(wsp[0],wsp[1],rozm[0],rozm[1]));
    return Prz;
  }

   std::shared_ptr<Trasa> UtworzObiektTrasa() const
  {
    std::shared_ptr<Trasa> Trs(new Trasa());
    return Trs;
  }


    // std::shared_ptr<Obiekt_Graf> UtworzObiekt( TypObiektu  TypOb , Wektor2D wsp, Wektor2D rozm ) const
    // {
    //   switch (TypOb) {
    //    case TO_Robot:  
    //    {
    //     std::shared_ptr<Robot> Rob(new Robot(wsp[0],wsp[0])); //return std::make_shared<Robot>(wsp[0],wsp[1]);
    //     return Rob;
    //    }
    //    case TO_Sciezka: 
    //    {
    //      std::shared_ptr<Trasa> Trs(new Trasa());
    //      return Trs;
    //    }
    //    case TO_Przeszkoda: 
    //    {
    //      std::shared_ptr<Przeszkoda> Prz(new Przeszkoda(wsp[0],wsp[0],rozm[0],rozm[0]));
    //      return Prz;
    //    }
    //   }
    //   return std::make_shared<Przeszkoda>(); // To tylko po to, aby kompilator
    //             // nie twierdził, że metoda nic nie zwraca. Ta instrukcja 
    //             // i tak nigdy się nie wykona.
    // }
};



#endif
