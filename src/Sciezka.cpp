#include "Sciezka.hh"


void Sciezka::Slad(Wektor2D& polo)
{
  
  //Wierz_Glb.pojemnik.insert(Wierz_Glb.pojemnik.begin(), polo);

  
  Wierz_Glb.pojemnik.push_back(polo);
    
    
}
ostream& operator << (ostream& Strm, const Sciezka &sciezka){
  for(unsigned int i=0; i<sciezka.Wierz_Glb.pojemnik.size(); i++)
    Strm<<(sciezka.Wierz_Glb.pojemnik[i]+ObiektGraficzny::Trans_Glb)<<endl;
  return Strm;
}
