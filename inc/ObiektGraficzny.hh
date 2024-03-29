#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH
#include "Wektor2D.hh"
#include "ZbiorWierzcholkow.hh"
#include "lacze_do_gnuplota.hh"


/*!
 * \file ObiektGraficzny.hh
 * Plik zawiera klase ObiektGraficzny oraz jej metody
 */

/*!
 * \brief Macierz
 * Klasa sluzy do przechowywania obiektow graficznych
 */
class ObiektGraficzny
{

public:
    static Wektor2D Trans_Glb; //!< Wektor statyczny translacji calej sceny
    ZbiorWierzcholkow Wierz_Glb;//!< Pojemnik na obiekty graficzne
    

    /*!
     * \brief Przeciazenie pomaga w lepszym poslugiwaniu sie pojemnikami
     *
     */
    Wektor2D& operator[ ] (int Ind)
    {
        return Wierz_Glb.pojemnik[Ind];
    }
    Wektor2D  operator[ ] (int Ind) const
    {
        return Wierz_Glb.pojemnik[Ind];
    }


  virtual void poka(){cout<<"dupa";}

};
/*!
 * Sluzy do wypisywnia Obiektu Graficznego
 */
ostream& operator << (ostream &Strm, const ObiektGraficzny &Graf);




#endif
