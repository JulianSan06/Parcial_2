#ifndef DISPARO_OFENSIVO_H
#define DISPARO_OFENSIVO_H
#define G 9.81
#define pi 3.1416

#include<math.h>
#include<iostream>

using namespace::std;

class Disparo_Ofensivo
{


public:
    float distance=800;
    float Ho=200;
    float Xo=0;
    float Yo=Ho;
    float DO=0.05*distance;
    Disparo_Ofensivo();
};

#endif // DISPARO_OFENSIVO_H
