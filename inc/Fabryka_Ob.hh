#ifndef FABRYKA_OB_HH
#define FABRYKA_OB_HH
#include "Wektor2D.hh"
#include "Zbior_Wierzch.hh"
#include "Obiekt_Graf.hh"
#include "Robot.hh"

enum TypObiektu { TO_Robot, TO_Sciezka, TO_Przeszkoda };

/*! \brief klasa opisujaca fabryke obiektow   
 */
class Fabryka_Ob {

    static Fabryka_Ob   _Fabryka_Ob;

  public:

    static shared_ptr<ObiektGraf> Zbuduj( TypObiektu  TypOb )
    {
      return _Fabryka_Ob.UtworzObiekt(TypOb);
    }

  private:

    shared_ptr<ObiektGraf> UtworzObiekt( TypObiektu  TypOb ) const
    {
      switch (TypOb) {
       case TO_Robot: return make_shared<Robot>();
       case TO_Sciezka: return make_shared<Trasa>();
       case TO_Przeszkoda: return make_shared<Przeszkoda>();
      }
      return make_shared<Przeszkoda>(); // To tylko po to, aby kompilator
                // nie twierdził, że metoda nic nie zwraca. Ta instrukcja 
                // i tak nigdy się nie wykona.
    }
};

Fabryka_Ob Fabryka_Ob::_Fabryka_Ob;

#endif
