#include "AppManager.h"

#include <iostream>

using namespace std;

void AppManager::menuInicio(){

    int opcion, y = 0;
    int consola_ancho = 100;
    
    Menu menu;

    do {
        rlutil::hidecursor();
        
        //Titulo principal centrado
        rlutil::locate((consola_ancho - 11) / 2, 10);
        cout << "MENU INICIO";
        
        showItem("MENU GESTIONES", (consola_ancho - 14) / 2, 12, y == 0);
        showItem("MENU REPORTES", (consola_ancho - 13) / 2, 14, y == 2);
        showItem("MENU CONFIGURACION", (consola_ancho - 18) / 2, 16, y == 4);
        showItem("SALIR DEL PROGRAMA", (consola_ancho - 18) / 2, 18, y == 6);
        
        rlutil::locate((consola_ancho - 25) / 2, 12 + y);
        cout << (char)175 << endl;
        
        int key = rlutil::getkey();
        
        switch(key)
        {
            case 14: //UP
                rlutil::locate((consola_ancho - 25) / 2, 12 + y);
                cout << " " << endl;
                y = y - 2;
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                rlutil::locate((consola_ancho - 25) / 2, 12 + y);
                cout << " " << endl;
                y = y + 2;
                if(y > 6){
                    y = 6;
                }
                break;
            case 1: //ENTER
                switch(y) {
                case 0:
                    menu.menuGestiones();
                    break;
                case 2:
                    menu.menuInformes();
                    break;
                case 4:
                    menu.menuConfiguraciones();
                    break;
                case 6:
                    rlutil::cls();
                    rlutil::locate((consola_ancho - 39) / 2, 15);
                    cout << "Gracias por utilizar nuestro programa!!" << endl;
                    return;
                    break;
                default:
                    cout << "Opcion incorrecta! Intente nuevamente" << endl;
                    system("pause");
                    break;
                }
            break;
        }

    } while(true);
}
