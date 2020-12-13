#include<iostream>
#include<disparo_defensivo.h>
#include<disparo_ofensivo.h>
#include<Funciones.h>
#include<neutralizacion.h>

using namespace std;

int main()
{
    int choice = 0;

    do{
        cout << "BIENVENIDO A LA APLICACION DE SIMULACION"<< endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Para generar disparos ofensivos" << endl;
        cout << "2. Para generar disparos defensivos" << endl;
        cout << "3. Para generar disparos defensivos que impida que el canion defensivo sea destruido" << endl;
        cout << "4. Para generar disparo defensivos que impidan que los caniones defensivo y ofensivo puedan ser destruidos." << endl;
        cout << "5. Para emular el caso especifico" << endl;
        cout << "6. Para emular salir" << endl;
        cin >> choice;
        if(choice == 1){
            disparo_defensivo disparo1;  //un objeto tipo disparo defensivo
            Disparo_Ofensivo disparo2;   //un objeto tipo disparo ofensivo


            cout << "----------------------------------------\n\n" << endl;
            cout << "GENERAR DISPAROS OFENSIVOS" << endl;
            cout << "Ingrese la velocidad de prueba: " << endl;
            float Velocidad_ofensiva;
            cin >> Velocidad_ofensiva;
            Disparo_of(disparo2, disparo1, Velocidad_ofensiva);
            disparo2.~Disparo_Ofensivo();
            disparo1.~disparo_defensivo();

        }

        else if(choice == 2){
            disparo_defensivo disparo1;  //un objeto tipo disparo defensivo
            Disparo_Ofensivo disparo2;   //un objeto tipo disparo ofensivo


            cout << "----------------------------------------\n\n" << endl;
            cout << "GENERAR DISPAROS DEFENSIVOS" << endl;
            cout << "Ingrese la velocidad de prueba: " << endl;
            float Velocidad_ofensiva;
            cin >> Velocidad_ofensiva;
            Disparo_def(disparo2, disparo1, Velocidad_ofensiva);
            disparo2.~Disparo_Ofensivo();
            disparo1.~disparo_defensivo();

        }

        else if(choice == 3){
            disparo_defensivo disparo1;  //un objeto tipo disparo defensivo
            Disparo_Ofensivo disparo2;   //un objeto tipo disparo ofensivo
            int VoO, angleO, VoD;

            cout << "----------------------------------------\n\n" << endl;
            cout << "GENERAR DISPAROS DE DEFENSA" << endl;
            cout << "Ingrese la velocidad de ataque: " << endl;
            cin >> VoO;

            cout << "Ingrese el angulo de ataque: " << endl;
            cin >> angleO;

            cout << "Ingrese la velocidad de defensa: " << endl;
            cin >> VoD;


            Disparodef2(disparo2, disparo1,VoO,angleO,VoD);
            disparo2.~Disparo_Ofensivo();
            disparo1.~disparo_defensivo();

        }

        else if (choice == 4){
            disparo_defensivo disparo1;  //un objeto tipo disparo defensivo
            Disparo_Ofensivo disparo2;   //un objeto tipo disparo ofensivo
            int VoO, angleO, VoD;

            cout << "----------------------------------------\n\n" << endl;
            cout << "GENERAR DISPAROS DE DEFENSA" << endl;
            cout << "Ingrese la velocidad de ataque: " << endl;
            cin >> VoO;

            cout << "Ingrese el angulo de ataque: " << endl;
            cin >> angleO;

            cout << "Ingrese la velocidad de defensa: " << endl;
            cin >> VoD;


            Disparodef3(disparo2, disparo1,VoO, angleO,VoD);
            disparo2.~Disparo_Ofensivo();
            disparo1.~disparo_defensivo();

        }

        else if(choice == 5){

            Disparo_Ofensivo disparo1; //primer disparo ofensivo
            disparo_defensivo disparo2; //segundo disparo ofensivo;
            int VoO, angleO;

            cout << "----------------------------------------\n\n" << endl;
            cout << "GENERAR DISPAROS DE DEFENSA" << endl;
            cout << "Ingrese la velocidad de ataque: " << endl;
            cin >> VoO;

            cout << "Ingrese el angulo de ataque: " << endl;
            cin >> angleO;


            neutralizacion(disparo1, disparo2, VoO, angleO);

        }


    }while(choice != 6);



    return 0;
}
