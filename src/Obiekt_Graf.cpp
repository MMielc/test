#include "Obiekt_Graf.hh"

Wektor2D Obiekt_Graf::_trans_glob(0,0);
int Obiekt_Graf::liczObStw;
int Obiekt_Graf::liczObIst;

void Obiekt_Graf::Obrot (float kat)
{
  _wierzch_glob.obroc(kat);
}

void Obiekt_Graf::Translacja (Wektor2D Wek)
{
  _wierzch_glob.przesun(Wek);
}

std::ostream & operator << (std::ostream & Strm, Obiekt_Graf obj)
{
  Strm<<obj._wierzch_glob<<std::endl;
  return Strm;
}
  
void Obiekt_Graf::DodajWierzch(Wektor2D Wek)
{
  _wierzch_glob.dodajWierzch(Wek);
}

void wyswietlStatOG(std::ostream &strm)
{
    strm<<"liczba stworzonych obiektow graficznych: ";
    strm<<Obiekt_Graf::liczObStw<<std::endl;
    strm<<"liczba istniejacych obiektow graficznych: ";
    strm<<Obiekt_Graf::liczObIst<<std::endl<<std::endl;
}