#ifndef SCENA_HH
#define SCENA_HH
#include <fstream>
#include "Robot.hh"
#include "Sciezka.hh"
#include "Fabryka.hh"
#include "ObiektGraficzny.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#include "Przeszkody.hh"
#include <memory>
using namespace std;


/*!
 * \file Scena.hh
 * Plik zawiera klase Scena oraz jej metody i konstruktory
 */

/*!
 * \brief Scena
 * Klasa przedstawia Scene graficzna
 */
class Scena
{
public:
  list<shared_ptr<ObiektGraficzny>> obiekty; //lista wskanzikow na obiekty
  list<shared_ptr<Robot>> roboty; //!< lista robotow
  shared_ptr<Robot> aktRob; // wskaznik na aktywnego robota
  int typ;  
  
  
  
    PzG::LaczeDoGNUPlota Lacze; //!<pole tworzy obiekt ktorym la
  
  Scena(); 

    /*!
     * \brief Metoda sluzy do poruszania robotem po scenie
     * \param double ile to dlugosc trasy do przejechania
     */
    void jedz(double &ile);

    /*!
     * \brief Metoda sluzy do obracania robota wokol srodka jego ciezkosci
     * \param const Macierz2x2 uzupelniona wczesniej macierz o zadany kat
     */
    void obrot(double &ile, Macierz2x2 &mac);

    /*!
     * \brief Metoda sluzy do rysowania sceny w programie GNUPLOT
     * \param const Macierz2x2 uzupelniona wczesniej macierz o zadany kat
     */
    int rysuj();

    /*!
     * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
     * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
     * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
     * to 16 miejsc, sposób wyrównywania - do prawej strony.
     * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
     *                     kolejne wspolrzedne.
     * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
     *                          mozliwosc zmiany wspolrzednych i prostokata
     *                          i zmiane jego polorzenia na okienku graficznym
     *                         rysownym przez gnuplota.
     * \retval true - gdy operacja zapisu powiodła się,
     * \retval false - w przypadku przeciwnym.
     */
    void PrzykladZapisuWspolrzednychDoStrumienia(ostream& StrmWy);

    /*!
     * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
     * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
     * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
     *                          wspolrzędne punktów.
     * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
     *                          mozliwosc zmiany wspolrzednych i prostokata
     *                          i zmiane jego polorzenia na okienku graficznym
     *                         rysownym przez gnuplota.
     * \retval true - gdy operacja zapisu powiodła się,
     * \retval false - w przypadku przeciwnym.
     */
    bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku);

    /*!
     * \brief Metoda sluzy do translacji calej sceny
     * \param double tran to wektor sluzacy do przesuniecia wszystkich obiektow na scenie
     */
  void translacja(Wektor2D &tran);

    /*!
     * \brief Metoda sluzy do wykrywania zderzenia
     * 
     */
  bool czykraksa();

    /*!
     * \brief Metoda sluzy do zmiany aktywnego robota
     * 
     */
  void zmianaRobota(int wybor);

  /*!
   * \brief Metoda sluzy do wyswietlenia wspolrzednych aktywnego robota
   */     
  void wyswietlAktywnego();

  /*!
     * \brief Metoda sluzy do wyswietlenia wspolrzednych wszystkich robotow
     * 
     */
  void wyswietlInne();

    /*!
     * \brief Metoda sluzy do zmiany predkosci aktywnego robota
     * 
     */
  void zmienPr(double pr);

  /*!
     * \brief Metoda sluzy do tworzenia robotow lub przeszkod
     * 
     */
  void Dodaj();

    /*!
     * \brief Metoda sprawdza czy mozna utworzyc przeszkode lub robota w danym miejscu
     * 
     */
  bool czynachodzi(Wektor2D polNowego,int typ);
};

ostream& operator <<(ostream& Strm, Scena& scena);

#endif
