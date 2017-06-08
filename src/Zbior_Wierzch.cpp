#include "Zbior_Wierzch.hh"

void Zbior_Wierzch::dodajWierzch(Wektor2D Wek)
{
    _wierzch.push_back(Wek);
}

void Zbior_Wierzch::przesun(Wektor2D Wek)
{
    for(unsigned int i=0; i<_wierzch.size(); i++)
    {
      _wierzch[i] = _wierzch[i] + Wek;
    }
}

std::vector <Wektor2D> Zbior_Wierzch::obroc(double kat)
{
    Macierz2x2 Mac;
    Mac(0,0) = cos(kat*PI/180);
    Mac(0,1) = -sin(kat*PI/180);
    Mac(1,0) = sin(kat*PI/180);
    Mac(1,1) = cos(kat*PI/180);

    for(unsigned int i = 0; i<_wierzch.size(); i++)
    {
        _wierzch[i] = Mac * _wierzch[i];
    }
return _wierzch;
}

std::ostream & operator << ( std::ostream & Strm, Zbior_Wierzch & zb)
{
    for(unsigned int i =0; i<zb._wierzch.size(); i++)
  {
    for(int j=0; j<2;j++)
    {
        Strm << std::setw(16) << std::fixed << std::setprecision(10) << zb._wierzch[i][j];
    }
    Strm << std::endl;
  }
  return Strm;
}