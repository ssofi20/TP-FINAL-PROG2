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
    system("pasuse");
}

///Dar de baja un tipo de muestra
void TipoMuestraManager::opcion2(){

    int IDTipo;
    cout << "Ingrese el ID de tipo de muestra que desea dar de baja: ";
    cin >> IDTipo;

    int cant = _archivo.cantidadRegistros();

    bool encontrado = false;
    int posicion;
    TipoMuestra registro;

    for(int i = 0; i < cant; i++){
        registro = _archivo.leer(i);
        if(registro.getIDMuestra() == IDTipo){
            encontrado = true;
            posicion = i;
            break;
        }
    }

    if(!encontrado){
        cout << "El ID ingresado no existe en el archivo" << endl;
        system("pasuse");
        return;
    }

    registro = _archivo.leer(posicion);
    registro.setEstado(false);
    _archivo.guardar(registro, posicion);

}

///Modificar un tipo de muestra
void TipoMuestraManager::opcion3(){

}

///Listar todos los tipos de muestras
void TipoMuestraManager::opcion4(){

}
