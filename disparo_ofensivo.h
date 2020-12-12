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
    float dis = 800;
    float Yo= 200;
    float Xi= 0;
    float DesO = 0.05*dis;
    Disparo_Ofensivo();
};

#endif // DISPARO_OFENSIVO_H
