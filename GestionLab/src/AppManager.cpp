#include "AppManager.h"

#include <iostream>

using namespace std;

void AppManager::menuInicio(){

    int opcion;
    Menu menu;

    do {

        system("cls");
        cout << "MENU INICIO" << endl;
        cout << "------------------------" << endl;
        cout << "1. Menu Gestiones" << endl;
        cout << "2. Menu Informes" << endl;
        cout << "3. Menu Configuracion" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            menu.menuGestiones();
            break;
        case 2:
            menu.menuInformes();
            break;
        case 3:
            menu.menuConfiguraciones();
            break;
        case 0:
            cout << "Gracias por utilizar nuestro programa!!" << endl;
            break;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }

    } while(opcion!=0);
}
