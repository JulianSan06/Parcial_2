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
    float angle_Def =20, Velx_Of, Vely_Of, Velx_Def, Vely_Def, Vel_Def = 10, Distancia;
    float X_Def, Y_Def, X_Of, Y_Of;
    bool Flag = 0;
    Velx_Of = vel_Of * cos(Angle_Of * pi/180);
    Vely_Of = vel_Of * sin(Angle_Of * pi/180);
    for(t_Of; ;){
        for(Vel_Def; Vel_Def+=10;)
            for(angle_Def; ;angle_Def=+5){
                Velx_Def = abs(Vel_Def * cos(angle_Def * (pi/180)));
                Vely_Def = abs(Vel_Def * sin(angle_Def *(pi /180)));
                for(t_Def=0; ;t_Def++){

                    //coordenadas del disparo defensivo
                    X_Def = disparo_Def.Xd - Velx_Def * t_Def;
                    Y_Def =disparo_Def.Yd - Vely_Def * t_Def - (0.5*G*pow(t_Def,2));

                    //coordenadas del ataque ofensivo
                    X_Of = disparo_Of.Xo + Velx_Of * t_Of;
                    Y_Of = disparo_Of.Yo + Vely_Of * t_Of - (0.5*G*pow(t_Of,2));
                    //Actualizacion de los parametros de los ciclos for
                    Vel_Def+=10;

                    //comparacion de la distacia con la explosion del misil defensivo
                    Distancia = sqrt(pow(X_Of-X_Def, 2) + pow(Y_Of -X_Def, 2));
                    if(Distancia < disparo_Def.DO){
                        cout<< "inminente explosion de ambos misiles" << endl;
                        //generar los tres
                        Disparo_Ofensivo disparo1;
                        int Vel_Res = vel_Of, angle_Res;
                        float Vxo, Vyo, x, y;
                        int V0of=0;
                        int t=0;
                        int angle=0;
                        int flag=0;
                        for(V0of=0; ;V0of+=5){
                            for(angle=0;angle<90;angle++){
                                Vxo=V0of*cos(angle*pi/180);
                                Vyo=V0of*sin(angle*pi/180);
                                x=0.0;
                                y=0.0;
                                for(t=0; ;t++){
                                    x=Vxo*t;
                                    y=disparo1.Yo+Vyo*t-(0.5*G*t*t);
                                    if(sqrt(pow((x-X_Def),2)+pow((y-Y_Def),2))<disparo1.DO){
                                        if(y<0) y=0;
                                        Imprimir(angle, V0of, x, y, t);
                                        flag+=1;
                                        V0of+=50;
                                        break;
                                    }
                                    if(y<0){
                                        break;
                                    }
                                }
                                if(flag == 3) break;
                            }
                            if(flag==3) break;
                        }
                        if(flag!=3){
                            cout << "No impacto en los disparos esperados" << endl;
                        }

                        exit(0);
                    }
                    if(Y_Def < 0){
                        t_Of++;
                        Y_Def = 0;
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
