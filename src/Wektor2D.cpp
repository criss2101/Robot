#include "Wektor2D.hh"

Wektor2D operator ~(Wektor2D &wek)
{
  wek[0]=0;
  wek[1]=0;
  return wek;
}


istream& operator >>(istream &Strm, Wektor2D &Wek)
{


    cin>> Wek[0];
    cout<<endl;
    cin>> Wek[1];
    cout<<endl;


    return Strm;
}

ostream& operator <<(ostream &Strm,const Wektor2D &Wek)
{

    int i;
    for(i=0; i<2; i++)
        Strm << setw(16) << fixed << setprecision(10) << Wek[i]<<" ";
    return Strm;
}

Wektor2D operator + (Wektor2D Wek, Wektor2D Wek2)
{

    for(int i=0; i<2; i++)
    {
        Wek[i]+=Wek2[i];
    }
    return Wek;
}

Wektor2D operator - (Wektor2D Wek, Wektor2D Wek2)
{
    for(int i=0; i<2; i++)
    {
        Wek[i]-=Wek2[i];
    }
    return Wek;
}


Wektor2D operator * (double mnoznik, Wektor2D Wek)
{
    for(int i=0; i<2; i++)
    {
        Wek[i]*=mnoznik;
    }
    return Wek;
}
Wektor2D operator * (Wektor2D Wek,const Macierz2x2 &Mac)
{
    double wektorPoczatkowy = Wek[0];
    Wek[0]=Wek[0]*Mac(0,0)+Wek[1]*Mac(0,1);
    Wek[1]=wektorPoczatkowy*Mac(1,0)+Wek[1]*Mac(1,1);
    return Wek;

}
