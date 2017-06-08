#include "Wektor2D.hh"
#include <math.h>
#include <iomanip> 

int Wektor2D::liczWekStw;
int Wektor2D::liczWekIst;

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
    Strm>>Wek._wsp[0];
    if (Strm.eof())  
    return Strm;

    else if (Strm.fail())
    {
      Strm.unget();
      Strm.clear();
      Strm.ignore(1000,'\n');
        return Strm;
    }
    else
    {
        Strm>>Wek._wsp[1];
        if (Strm.eof()) 
         return Strm;

    else if (Strm.fail())
    {
      Strm.unget();
      Strm.clear();
      Strm.ignore(1000,'\n');
        return Strm;
    }
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm,  Wektor2D Wek)
{
    Strm<<"("<< std::setprecision(10)<<Wek._wsp[0]<<","<<std::setprecision(10)<<Wek._wsp[1]<<")"<<std::endl; 
    return Strm;
}

float odlgPkt (Wektor2D Wek1,Wektor2D Wek2)
{
    return sqrt((Wek2[0] - Wek1[0])*(Wek2[0] - Wek1[0]) + (Wek2[1] - Wek1[1])*(Wek2[1] - Wek1[1]));
}

   void wyswietlStat(std::ostream &str)
  {
    str<<"liczba stworzonych obiektow typu Wektor2D: ";
    str<<Wektor2D::liczWekStw<<std::endl;
    str<<"liczba istniejacych obiektow typu Wektor2D: ";
    str<<Wektor2D::liczWekIst<<std::endl<<std::endl;
  }