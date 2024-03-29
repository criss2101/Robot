#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#include <iostream>
#include "Macierz2x2.hh"
#include <iomanip>

using namespace std;

/*!
 * \file Wektor3D.hh
 * Plik zawiera klase wektora
 */

/*!
 * Klasa przechowuje wektor i jego trzy wspolrzedne
 */
class Wektor2D
{


  double wektor[2];//!< Wsporzedne wektora
public:
  /*!
   *\brief Operator indeksujacy sluzacy do odwolywania sie do wektorw
   */
    double operator[ ] (int Ind) const
    {
        return wektor[Ind];
    }

    double& operator[ ] (int Ind)
    {
        return wektor[Ind];
    }

   /*!
   *\brief konstruktor inicjujacy wspolrzedne wektora
   */
    Wektor2D(double x,double y)
    {
        wektor[0]=x;
        wektor[1]=y;
    }
   /*!
   *\brief konstruktor bezparametryczny inicjujacy wspolrzedne wektora 0
   */
   Wektor2D()
    {
        wektor[0]=0;
        wektor[1]=0;
    }

};


/*!
 * \brief Pozwala na wpisywanie wektorow
 */
istream& operator >> (istream &Strm, Wektor2D &Wek);

/*!
 * \brief Pozwala na wypisywanie wektorow
 */
ostream& operator << (ostream &Strm, const Wektor2D &Wek);

/*!
 * \brief Pozwala dodawanie wektorow
 */
Wektor2D operator + (Wektor2D Wek, Wektor2D Wek2);

/*!
 * \brief Pozwala odejmowanie wektorow
 */
Wektor2D operator - (Wektor2D Wek, Wektor2D Wek2);

/*!
 * \brief Pozwla na mnozenie wektorow
 */
Wektor2D operator * (double mnoznik, Wektor2D Wek);

/*!
 * \brief Pozwla na mnozenie macierzy przez wektor
 */
Wektor2D operator * (Wektor2D Wek,const Macierz2x2 &Mac);

Wektor2D operator ~ (Wektor2D &wek);

#endif
