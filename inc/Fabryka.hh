#ifndef FABRYKA_HH
#define FABRYKA_HH
#include "ObiektGraficzny.hh"
#include "Przeszkody.hh"
#include "Robot.hh"
#include <memory>
#include "Wektor2D.hh"

using namespace std;

enum TypObiektu { TO_Robot=1, TO_Przeszkoda };




/*!
 * \file Fabryka.hh
 * Plik zawiera klase fabryki robotow
 */

/*!
 * \brief Fabryka
 * Klasa sluzy do tworzenia robotow i przeszkod 
 */
class Fabryka {
  static Fabryka   _Fabryka; //!< Singleton
public:

  ~Fabryka(){cout<<"";}


  static shared_ptr<ObiektGraficzny> Zbuduj( TypObiektu  TypOb,Wektor2D pol )
  {
    return _Fabryka.UtworzObiekt(TypOb,pol);
  }

  private:
  Fabryka(){cout<<"";}             


  /*!
   * \brief Metoda sluzy do tworzenia przeszkod lub robota
   * 
   */
  shared_ptr<ObiektGraficzny> UtworzObiekt( TypObiektu  TypOb, Wektor2D pol ) const 
  {
   
    switch (TypOb) {
    case TO_Robot: return make_shared<Robot>(pol);
    
    case TO_Przeszkoda: return make_shared<Przeszkody>(pol);
    }
    return make_shared<Przeszkody>(pol); // To tylko po to, aby kompilator
    // nie twierdził, że metoda nic nie zwraca. Ta instrukcja
    // i tak nigdy się nie wykona.
  }
};





#endif
