#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#include <math.h>
#define PI 3.14159265359
#include <iostream>

/*!
 * \file Macierz3x3.hh
 * Plik zawiera klase Macierz3x3 oraz jej metody i konstruktory
 */

/*!
 * \brief Macierz
 * Klasa jest tablica macierz3x3 sluzy do rotacji
 */
class Macierz2x2
{


    double macierz[2][2];//!< Macierz rotacji
public:

    

    /*!
     * \brief Przeciazenie pomaga w lepszym poslugiwaniu sie macierza
     * pozwala na odwolanie sie do wiersza i kolumny
     */
    double &operator ( ) (int Wiersz, int Kolumna)
    {
        return macierz[Wiersz][Kolumna];
    }
    double operator ( ) (int Wiersz, int Kolumna) const
    {
        return macierz[Wiersz][Kolumna];
    }
    /*!
       * \brief wypelnia macierz w zaleznosci od stopni
       * \param double stopnie stopnie o jakie ma nastapic obrot
       * pozwala na odwolanie sie do wiersza i kolumny
       */
    void wypelnij(double stopnie);
};



#endif
