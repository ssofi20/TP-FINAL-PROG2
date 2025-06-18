#include "AppManager.h"

#include <iostream>

using namespace std;

void AppManager::menuInicio(){

    int y = 0;
    int consola_ancho = 100;
    
    Menu menu;

    do {

        rlutil::hidecursor();
        rlutil::cls();
        
        //Titulo principal centrado
        string titulo = "MENU INICIO";
        string linea = "---------------------";
        
        rlutil::locate((consola_ancho - titulo.length()) / 2, 9);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;
        
        //Opciones del menu
        
        const char* opciones[] = {
            "MENU GESTIONES", 
            "MENU REPORTES", 
            "MENU CONFIGURACION", 
            "SALIR DEL PROGRAMA"
        };
        
        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        
        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;
        
        int key = rlutil::getkey();
        
        switch(key)
        {
            case 14: //UP
                largoTexto = strlen(opciones[y / 2]);
                rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
                cout << " " << endl;
                y = y - 2;
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                largoTexto = strlen(opciones[y / 2]);
                rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
                cout << " " << endl;
                y = y + 2;
                if(y > 6){
                    y = 6;
                }
                break;
            case 1: //ENTER
                switch(y) 
                {
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
