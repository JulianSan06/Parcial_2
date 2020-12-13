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


void neutralizacion(Disparo_Ofensivo disparoO, disparo_defensivo disparoD, int VoO, int angleO){
    float Vxo = 0.0, Vyo = 0.0, x, y, Vxoo, Vyoo, x2, y2;
    int V0of=0;
    int t=0;
    int angle=0;
    float aux, auy;
    bool flag2=0;
    int flag=0;
    Vxoo=VoO*cos((angleO)*pi/180);
    Vyoo=VoO*sin((angleO)*pi/180);
    for(V0of=VoO; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxo=V0of*cos((angle+90)*pi/180);
            Vyo=V0of*sin((angle+90)*pi/180);
            x=0.0;
            y=0.0;
            x2=0.0;
            y2=0.0;
            for(t=0; ;t++){
                x2=Vxoo*(t+2);
                y2=disparoO.Yo+Vyoo*(t+2)-(0.5*G*(t+2)*(t+2));
                x=disparoD.Xd+Vxo*t;
                y=disparoD.Yd+Vyo*t-(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = disparoD.Xd+Vxo*t2;
                    auy = disparoD.Yd + Vyo*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((disparoO.Xo - aux),2)+pow((disparoO.Yo - auy),2)) < disparoD.DO){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    cout << "No impacto en los disparos esperados"<< endl;
                    break;
                }
                if(sqrt(pow((disparoD.Xd - x2),2)+pow((disparoD.Yd - y2),2)) < disparoO.DO){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.DO){
                    if(y<0) y = 0;
                    if(y2<0) y2=0;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag2 == 1) break;

        }
        if(flag2 == 1) break;
    }
//generar los tres disparos
    Disparo_Ofensivo disparoO_Res;
    float Vxo_Res, Vyo_Res, x_Res, y_Res;
    int V0of_Res=0;
    int t_Res=0;
    int angle_Res=0;
    int flag4=0;
    for(V0of_Res=VoO; ;V0of+=15){
        for(angle=0;angle_Res<90;angle_Res++){
            Vxo_Res=V0of*cos((angle_Res+90)*pi/180);
            Vyo_Res=abs(V0of*sin((angle_Res+90)*pi/180));
            x=0.0;
            y=0.0;
            for(t_Res=0; ;t_Res++){
                x_Res=Vxo_Res*t_Res;
                y_Res=disparoD.Yd+Vyo_Res*t-(0.5*G*t_Res*t_Res);
                if(sqrt(pow((disparoO.Xo - aux),2)+pow((disparoO.Yo - auy),2)) < disparoD.DO){
                    if(y<0) y_Res=0;
                    Imprimir(angle_Res, V0of_Res, x_Res, y_Res, t_Res);
                    flag+=1;
                    V0of_Res+=50;
                    break;
                }
                if(y<0){
                    break;
                }
            }
            if(flag4 == 3) break;
        }
        if(flag4 ==3) break;
    }
    if(flag4!=3){
        cout << "No impacto en los disparos esperados" << endl;
    }
}
#endif // NEUTRALIZACION_H
