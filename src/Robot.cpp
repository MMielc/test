#include "Robot.hh"
#include <math.h>


Robot::Robot (double x, double y, std::shared_ptr<Trasa> wskTrs)
:
 predkosc(7)

{
kat_rotacji = 0;

wskNaTraseRobota = wskTrs;

 Wektor2D ini;
 ini[0] = 0;
 ini[1] = 0;

pozycja[0] = x;
pozycja[1] = y;

  wierz_lok.dodajWierzch( Wektor2D (0,0));
  wierz_lok.dodajWierzch( Wektor2D (35,0));
  wierz_lok.dodajWierzch( Wektor2D (5,-35));
  wierz_lok.dodajWierzch( Wektor2D (-25,-35));
  wierz_lok.dodajWierzch( Wektor2D (-25,35));
  wierz_lok.dodajWierzch( Wektor2D (5,35));
  wierz_lok.dodajWierzch( Wektor2D (35,0));

 _wierzch_glob = wierz_lok;

 Obrot(kat_rotacji);
 }

 void Robot::Obrot (double kat)
 {
    Zbior_Wierzch tmp;
    tmp = wierz_lok;

    tmp.obroc(kat + kat_rotacji);
    _wierzch_glob = tmp;
    kat_rotacji = kat_rotacji + kat;

   Translacja(pozycja);
 }

 void Robot::Przesuniecie (Wektor2D Wek)
 {
    pozycja = pozycja + Wek;
    Translacja(Wek);
 }

 void Robot::RuchWPrzod (double dlugosc_kroku)
 {
   Wektor2D ruch;
   ruch[0] = dlugosc_kroku * cos(kat_rotacji*PI/180);
   ruch[1] = dlugosc_kroku * sin(kat_rotacji*PI/180);

   pozycja = pozycja + ruch;
   Translacja(ruch);
 }

void Robot::RysujTrase (Obiekt_Graf &trs)
    {
        trs.DodajWierzch(wezPozycje());
    }

bool Robot::czyKolizja(Wektor2D polozenie, double R)
{
  if( odlgPkt(_wierzch_glob.zwrocWierzcholek(0), polozenie) < 2 * R)
	return true;
	else
	return false;
}



















