#include "Przeszkoda.hh"

Przeszkoda::Przeszkoda(double x, double y, double a, double b)
{
    pozycja[0] = x;
    pozycja[1] = y;

    Wektor2D Wierz_Prz[5];

    Wierz_Prz[0][0] = 0;
    Wierz_Prz[0][1] = 0;

    Wierz_Prz[1][0] = a;
    Wierz_Prz[1][1] = 0;

    Wierz_Prz[2][0] = a;
    Wierz_Prz[2][1] = b;

    Wierz_Prz[3][0] = 0;
    Wierz_Prz[3][1] = b;

    Wierz_Prz[4][0] = 0;
    Wierz_Prz[4][1] = 0;

    for (int i = 0; i<5; i++)
    wierz_lok.dodajWierzch(Wierz_Prz[i]);

    _wierzch_glob = wierz_lok;
    Translacja(pozycja);
}

bool Przeszkoda::czyKolizja(Wektor2D polozenie, double R)
{
  if(polozenie[0] > _wierzch_glob.zwrocWierzcholek(0)[0] - R && 
     polozenie[0] < _wierzch_glob.zwrocWierzcholek(1)[0] + R &&

     polozenie[1] > _wierzch_glob.zwrocWierzcholek(0)[1] - R &&
     polozenie[1] < _wierzch_glob.zwrocWierzcholek(2)[1] + R)

  // if(polozenie[0] > _wierzch_glob._wierzch[0][0] - R && 
  //    polozenie[0] < _wierzch_glob._wierzch[1][0] + R &&

  //    polozenie[1] > _wierzch_glob._wierzch[0][1] - R &&
  //    polozenie[1] < _wierzch_glob._wierzch[2][1] + R)
  return true;

  else 
	return false;
}