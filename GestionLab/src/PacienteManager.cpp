#include "PacienteManager.h"
#include <iostream>

using namespace std;
/*
"4. Dar de baja un paciente
"5. Restaurar un paciente
"6. Mostrar lista de pacientes
*/



//Dar de baja un paciente
void PacienteManager::opcion4(){

    Paciente registro;
    int DNI;
    cout << "Ingrese le DNI del paciente a dar de baja: ";
    cin >> DNI;

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++){

        registro = _archivo.leer(i);
        if(registro.getDNI() == DNI){
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado){

        registro.setEstado(false);
        if(_archivo.guardar(registro, pos)){
            cout << "Paciente dado de baja exitosamente!" << endl;
        }
        else {
            cout << "Error al dar de baja el paciente" << endl;
        }
    }
    cout << "No se encontro un paciente con ese DNI en el archivo" << endl;


}

//Restaurar un paciente
void PacienteManager::opcion5(){

    Paciente registro;
    int DNI;
    cout << "Ingrese le DNI del paciente a dar de alta: ";
    cin >> DNI;

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++){

        registro = _archivo.leer(i);
        if(registro.getDNI() == DNI){
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado){

        registro.setEstado(true);
        if(_archivo.guardar(registro, pos)){
            cout << "Paciente se restauro exitosamente!" << endl;
        }
        else {
            cout << "Error al restaurar el paciente" << endl;
        }
    }
    cout << "No se encontro un paciente con ese DNI en el archivo" << endl;

}

//Mostrar lista de pacientes
void PacienteManager::opcion6(){

    cout << "Listado de pacientes" << endl;
    int cant = _archivo.cantidadRegistros();

    Paciente *vecRegistros = new Paciente[cant];
    if(vecRegistros == nullptr){
        cout << "Error al pedir memoria" << endl;
        return;
    }
    _archivo.leer(cant,vecRegistros);
    for (int i = 0; i < cant; i++){

        cout << "-------------------------" << endl;
        //mostrar
        cout << "-------------------------" << endl << endl;
    }

}
