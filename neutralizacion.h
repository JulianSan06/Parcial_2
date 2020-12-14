#ifndef NEUTRALIZACION_H
#define NEUTRALIZACION_H
#define G 9.8
#define pi 3.1416

#include<math.h>
#include<iostream>
#include<disparo_defensivo.h>
#include<disparo_ofensivo.h>
#include<Funciones.h>
using namespace::std;

void neutralizacion(Disparo_Ofensivo disparo_Of, disparo_defensivo disparo_Def, int Angle_Of, int vel_Of){
    int  t_Of = 0, t_Def = 2;
        float angle_Def =0, Velx_Of, Vely_Of, Velx_Def, Vely_Def, Vel_Def = 0, Distancia;
        float X_Def, Y_Def, X_Of, Y_Of;
        bool Flag = 0;
        Velx_Of = vel_Of * cos(Angle_Of * pi/180);
        Vely_Of = vel_Of * sin(Angle_Of * pi/180);
        for(t_Of=0; ;){
            for(Vel_Def=10; Vel_Def+=10;)
                for(angle_Def=20; ;angle_Def=+5){
                    Velx_Def = abs(Vel_Def * cos(angle_Def * (pi/180)));
                    Vely_Def = abs(Vel_Def * sin(angle_Def * (pi /180)));
                    for(t_Def=0; ;t_Def++){

                        //coordenadas del disparo defensivo
                        X_Def = disparo_Def.Xd - Velx_Def * t_Def;
                        Y_Def =disparo_Def.Yd - Vely_Def * t_Def - (0.5*G*t_Def*t_Def);

                        //coordenadas del ataque ofensivo
                        X_Of = disparo_Of.Xo + Velx_Of * t_Of;
                        Y_Of = disparo_Of.Yo + Vely_Of * t_Of - (0.5*G*t_Of*t_Of);
                        //Actualizacion de los parametros de los ciclos for
                        Vel_Def+=10;
                        angle_Def+=5;

                        //comparacion de la distacia con la explosion del misil defensivo
                        Distancia = sqrt(pow(X_Of-X_Def, 2) + pow(Y_Of -Y_Def, 2));
                        if(Distancia < disparo_Def.DO){
                            cout<< "inminente explosion de ambos misiles" << endl;
                            break;
                            break;
                            break;
                            break;


                            //generar los tres

                        }
                        if(Y_Def < 0){
                            t_Of++;
                            Y_Def = 0.0;
                            break;
                        }

                    }
                    if(Flag)
                        break;
                    else{
                        angle_Def = 20;
                        break;
                    }
                }
            if(Flag)
                break;
            else
                break;
        }
        //generar los tres
        Disparo_Ofensivo disparo_Respuesta;
        int t_Res= 0, angle_Res = 0;
        float X_Res, Y_Res, VelX_Res, VelY_Res, Vel_Res = Vely_Of, Distancia2;

        for(Vel_Res; ;VelX_Res+=10){
            for(angle_Def=20; ;angle_Def+=5){
                VelX_Res = Vel_Res * cos(angle_Res * pi /180);
                VelY_Res = Vel_Res * sin(angle_Res * pi /180);

                for(t_Res; ;t_Res++){

                    //Coordenadas de los ataques de respuesta
                    X_Res = disparo_Respuesta.Xo + Velx_Def * t_Res;
                    Y_Res = disparo_Respuesta.Yo + VelY_Res * t_Res - (0.5 * G * pow(t_Res,2));

                    //comparacion de la distancia
                    Distancia2 = sqrt(pow(X_Res-X_Def, 2) + pow(Y_Res -Y_Def, 2));

                    if(Distancia2 < disparo_Respuesta.DO){
                        Imprimir(angle_Res, Vel_Res, X_Res, Y_Res, t_Res);
                    }
                    if(Y_Res < 0){
                        Vel_Res++;
                        Y_Res = 0;
                        break;
                    }

                }
                if(Flag)
                    break;
                else{
                    angle_Def = 20;
                    break;
                }
            }
        if(Flag)
            break;
        else
            break;
    }
    }
#endif // NEUTRALIZACION_H
