#ifndef ROBOT_HH
#define ROBOT_HH
#include "Macierz2x2.hh"
#include "ObiektGraficzny.hh"
#include "Wektor2D.hh"
#include "ZbiorWierzcholkow.hh"
#include "Sciezka.hh"
using namespace std;


/*!
 * \file Robot.hh
 * Plik zawiera klase robot
*/

/*!
 * \brief Robot
 * Klasa przechowuje kontyner na wierzcholki  robota
 */
class Robot :public ObiektGraficzny
{
public:
    
    ZbiorWierzcholkow Wierz_Lok; //!< Kontyner na wierzcholki robota w ukladzie lokalnym*/
    Wektor2D kierunek;  //!< Kierunek dziobu robota */
    Wektor2D poczatkowe; //!< Poczatkowe polozenie */
    Wektor2D polozenie;
    double predkosc; //!< Predkosc poruszania sie robota */
    Sciezka sciezka;
    int pocz_sciezki;
  Robot(Wektor2D lokalizacja);
    /*!
     * \brief Metoda sluzy do transportowania wierzcholkow lokalnych do globalnego
     * \param ObiektGraficzny
     */
    void LokDoGlb();

    /*!
     * \brief Metoda sluzy do poruszania robotem
     * \param double ile to dlugosc trasy do przejechania
     */
    void jedz(double ile);

    /*!
     * \brief Metoda sluzy do obracania robota wokol srodka jego ciezkosci
     * \param const Macierz2x2 uzupelniona wczesniej macierz o zadany kat
     */
    void obrot(const Macierz2x2 &mac);
/*!
 * Sluzy do wypisywania wspolrzednych tworzacych sciezke
 */
  void slad();
};
/*!
 * Sluzy do wypisywania wspolrzednych lokalnych robota
 */
ostream& operator << (ostream &Strm, const Robot &Rb);


#endif
