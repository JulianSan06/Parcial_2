#ifndef DISPARO_OFENSIVO_H
#define DISPARO_OFENSIVO_H
#define G 9.81
#define pi 3.1416

#include<math.h>
#include<iostream>
#include<Estructura_Disparo.h>

using namespace::std;

class Disparo_Ofensivo : public Disp_ofensive, public Disp_defensive
{

public:
    void Imprimir(float angle,float V0of,float x,float y, int t);
    void Disparo_of(Disp_ofensive disparoO, Disp_defensive disparoD, int Voo);
    Disparo_Ofensivo();
};

#endif // DISPARO_OFENSIVO_H
