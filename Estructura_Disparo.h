#ifndef ESTRUCTURA_DISPARO_H
#define ESTRUCTURA_DISPARO_H


#include<iostream>
using namespace::std;

struct Disp_ofensive{
    float distance=800;
    float Ho=200;
    float Xo=0;
    float Yo=Ho;
    float DO=0.05*distance;
};

struct Disp_defensive{
    float distance=800;
    float Hd=50;
    float Xd=distance;
    float Yd=Hd;
    float DO=0.025*distance;
};

#endif // ESTRUCTURA_DISPARO_H
