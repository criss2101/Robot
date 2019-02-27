#ifndef PRZESZKODY_HH
#define PRZESZKODY_HH
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "ZbiorWierzcholkow.hh"

using namespace std;


/*!
 * \file Przeszkody.hh
 * Plik zawiera klase robot
 */

/*!
 * \brief Przeszkody
 * Klasa przechowuje kontyner na przeszkody
 */
class Przeszkody :public ObiektGraficzny
{
public:
  Wektor2D polozenie;
  /*!
 * Konstruktor tworzacy przeszkode 
 */
  Przeszkody(Wektor2D srodek);



};
  ostream& operator << (ostream &Strm, const Przeszkody &przeszkoda);


#endif
