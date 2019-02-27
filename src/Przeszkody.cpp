#include "Przeszkody.hh"


Przeszkody::Przeszkody(Wektor2D srodek){
 
  Wierz_Glb.pojemnik.push_back(Wektor2D(-25+srodek[0],25+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(25+srodek[0],25+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(25+srodek[0],-25+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(-25+srodek[0],-25+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(-25+srodek[0],25+srodek[1]));
 
  /* Wierz_Glb.pojemnik.push_back(Wektor2D(50+srodek[0],150+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(100+srodek[0],150+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(100+srodek[0],100+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(50+srodek[0],100+srodek[1]));
  Wierz_Glb.pojemnik.push_back(Wektor2D(50+srodek[0],150+srodek[1]));
  */

}



ostream& operator << (ostream &Strm, const Przeszkody &przeszkoda)
{
  for(unsigned int i=0; i<5;i++)
    Strm<<przeszkoda.Wierz_Glb.pojemnik[i]<<endl;
  Strm<<endl<<endl;

  
  
  return Strm;
}
