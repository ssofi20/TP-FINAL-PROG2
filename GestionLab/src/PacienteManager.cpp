#include "PacienteManager.h"
#include <iostream>

using namespace std;

//FUNCIONES UTILIES
void PacienteManager::mostrar(Paciente registro){

    cout << "DNI: " << registro.getDNI() << endl;

    cout << "Nombre/s: " << registro.getNombre() << endl;

    cout << "Apellido/s: " << registro.getApellido() << endl;

    cout << "Fecha Nacimiento: " << registro.getDateB().toString() << endl;

    cout << "Telefono: " << registro.getTelefono() << endl;

    cout << "Email: "  << registro.getEmail() << endl;

    cout << "Obra social: " << registro.getObraSocial() << endl;

    cout << "Numero de afiliado: " << registro.getNumeroAfiliado() << endl;

}

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
    system("pause");
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
    system("pause");
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
        Paciente registro = _archivo.leer(i);
        cout << "-------------------------" << endl;
        mostrar(registro);
        cout << "-------------------------" << endl << endl;
    }
    system("pause");
}
