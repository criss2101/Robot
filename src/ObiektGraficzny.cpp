#include "ObiektGraficzny.hh"

Wektor2D ObiektGraficzny::Trans_Glb;



ostream& operator <<(ostream &Strm, const ObiektGraficzny &Graf)
{
  
    for(unsigned int i=0; i<Graf.Wierz_Glb.pojemnik.size(); i++)
      Strm<<(Graf.Wierz_Glb.pojemnik[i]+ObiektGraficzny::Trans_Glb)<<endl;

    return Strm;
}

