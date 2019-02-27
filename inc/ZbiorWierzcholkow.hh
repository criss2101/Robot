#ifndef ZBIORWIERZCHOLKOW_HH
#define ZBIORWIERZCHOLKOW_HH
#include "Wektor2D.hh"
#include <vector>
using namespace std;

/*!
 * \file ZbiorWierzcholkow.hh
 * Plik zawiera klase kontynera wektorow
 */

/*!
 * Klasa przechowuje pojemnik na wektory
 */
class ZbiorWierzcholkow
{
public:
    vector <Wektor2D> pojemnik; //!< Pojemnik
    /*!
    * \brief Konstruktor domyslny
    *Konstruktor rezerwuje w pamieci miejsce na kontyner
    */
    ZbiorWierzcholkow()
    {
        pojemnik.reserve(50);
    }

    /*!
     * \brief Przeciazenie pomaga w lepszym poslugiwaniu sie macierza
     * pozwala na odwolanie sie do wiersza i kolumny
     */
    Wektor2D operator [ ](int Ind) const
    {
        return pojemnik[Ind];
    }
    Wektor2D& operator [ ](int Ind)
    {
        return pojemnik[Ind];
    }

};







#endif
