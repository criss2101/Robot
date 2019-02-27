#include "Macierz2x2.hh"

void Macierz2x2::wypelnij(double stopnie)
{

    macierz[0][0]=cos(stopnie*PI/180);
    macierz[0][1]=-sin(stopnie*PI/180);
    macierz[1][0]=sin(stopnie*PI/180);
    macierz[1][1]=cos(stopnie*PI/180);
}

