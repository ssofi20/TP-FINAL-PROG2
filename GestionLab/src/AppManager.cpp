#include "AppManager.h"

#include <iostream>

using namespace std;

void AppManager::menuInicio(){
    
    int opcion;
    
    do {
          
        system("cls");
        cout << "MENU INICIO" << endl;
        cout << "------------------------" << endl;
        cout << "1. Menu Principal" << endl;
        cout << "2. Menu Informes" << endl;
        cout << "3. Menu Configuracion" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            cout << "Gracias por utilizar nuestro programa!!" << endl;
            break;
        default: 
            cout << "Opcion incorrecta!. Intente nuevamente" << endl;
            break;
        }
        
    } while(opcion!=0);
}
