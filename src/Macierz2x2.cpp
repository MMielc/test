#include "Macierz2x2.hh"



std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
    Strm<<"| "<<Mac(0,0)<<" "<<Mac(0,1)<<" |"<<std::endl;
    Strm<<"| "<<Mac(1,0)<<" "<<Mac(1,1)<<" |"<<std::endl;

    return Strm;
}



