#ifndef FUNCIONES_H
#define FUNCIONES_H
#define G 9.81
#define pi 3.1416

#include<math.h>
#include<iostream>
#include<disparo_defensivo.h>
#include<disparo_ofensivo.h>
using namespace::std;

void Imprimir(float angle,float V0of,float x,float y, int t){
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad inicial " << V0of << endl;
    cout << "Impacto con posicion horizontal " << x << endl;
    cout << "Impacto con posicion vertical " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void Disparo_of(Disparo_Ofensivo disparoO, disparo_defensivo disparoD, int Voo){
    float Vxo, Vyo, x, y;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxo=V0of*cos(angle*pi/180);
            Vyo=V0of*sin(angle*pi/180);
            x=0.0;
            y=0.0;
            for(t=0; ;t++){
                x=Vxo*t;
                y=disparoO.Yo+Vyo*t-(0.5*G*t*t);
                if(sqrt(pow((disparoD.dis-x),2)+pow((disparoD.Yo-y),2))<disparoO.DesO){
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
}

void Disparo_def(Disparo_Ofensivo disparoO, disparo_defensivo disparoD, int Voo){
    float Vxo, Vyo, x, y;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxo=V0of*cos((angle+90)*pi/180);
            Vyo=abs(V0of*sin((angle+90)*pi/180));
            x=0.0;
            y=0.0;
            for(t=0; ;t++){
                x=Vxo*t;
                y=disparoD.Yo+Vyo*t-(0.5*G*t*t);
                if(sqrt(pow((disparoO.Xi-x),2)+pow((disparoO.Yo-y),2))<disparoD.DesDef){
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
}

void Disparodef2(Disparo_Ofensivo disparoO, disparo_defensivo disparoD, int Voo, int angleoo, int Vooo){
    float Vxo = 0.0, Vyo = 0.0, x, y, Vxoo, Vyoo, x2, y2;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    Vxoo=Vooo*cos((angleoo)*pi/180);
    Vyoo=Vooo*sin((angleoo)*pi/180);
    for(V0of=Voo; ;V0of+=5){
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
                x=disparoD.dis+Vxo*t;
                y=disparoD.Yo+Vyo*t-(0.5*G*t*t);
                if(sqrt(pow((x2-x),2)+pow((y2-y),2))<disparoD.DesDef){
                    if(y<0) y=0;
                    Imprimir(angleoo,Vooo,x2,y2,t+2);
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
}
void Disparodef3(Disparo_Ofensivo disparoO, disparo_defensivo disparoD, int Voo, int angleoo, int Vooo){
    float Vxo = 0.0, Vyo = 0.0, x, y, Vxoo, Vyoo, x2, y2;
    int V0of=0;
    int t=0;
    int angle=0;
    float aux, auy;
    bool flag2=0;
    int flag=0;
    Vxoo=Vooo*cos((angleoo)*pi/180);
    Vyoo=Vooo*sin((angleoo)*pi/180);
    for(V0of=Voo; ;V0of+=5){
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
                x=disparoD.dis+Vxo*t;
                y=disparoD.Yo+Vyo*t-(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = disparoD.dis+Vxo*t2;
                    auy = disparoD.Yo + Vyo*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((disparoO.Xi - aux),2)+pow((disparoO.Yo - auy),2)) < disparoD.DesDef){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((disparoD.dis - x2),2)+pow((disparoD.Yo - y2),2)) < disparoO.DesO){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.DesDef){
                    if(y<0) y = 0;
                    Imprimir(angleoo,Vooo,x2,y2,t+2);
                    Imprimir(angle, V0of, x, y, t);
                    flag += 1;
                    V0of += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
#endif // FUNCIONES_H
