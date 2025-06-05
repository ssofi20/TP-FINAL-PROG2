#include "TipoMuestraManager.h"
#include <iostream>

using namespace std;

///Dar de alta un tipo de muestra
void TipoMuestraManager::opcion1(){

    TipoMuestra registro;

    int IDTipo;
    bool invalido = true;
    while(invalido){
        cout << "Ingrese el ID: ";
        cin >> IDTipo;
        if(IDTipo < 6 && IDTipo > 0){
            invalido = false;
        }
        else {
            cout << "No existe ese tipo de ID. Ingrese una opcion del 1 al 5" << endl;
        }
    }

    registro.setIDMuestra(IDTipo);

    char nombre[35];
    cout << "Ingrese el nombre del tipo de muestra: " << endl;
    cargarCadena(nombre, 34);

    registro.setNombre(nombre);

    registro.setEstado(true);

    if(_archivo.guardar(registro)){
        cout << "Se ha guardado con exito!" << endl;
    }
    else {
        cout << "No se ha podido guardar :(" << endl;
    }
}

///Dar de baja un tipo de muestra
void TipoMuestraManager::opcion2(){

}

///Modificar un tipo de muestra
void TipoMuestraManager::opcion3(){

}

///Listar todos los tipos de muestras
void TipoMuestraManager::opcion4(){

}
