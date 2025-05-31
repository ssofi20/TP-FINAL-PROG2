#include "TurnoManager.h"
#include <iostream>

using namespace std;

///Agregar turno al archivo
void TurnoManager::opcion1(){

    Turno registro;
    registro.cargar();
    if(_archivo.guardar(registro)){
        cout << "El Turno se registro correctamente" << endl;
    } 
    else {
        cout << "El turno no se pudo registrar" << endl;
    }
    system("pause");

}

///Cambiar fecha y hora de un turno
void TurnoManager::opcion2(){
    
    int IDTurno;
    cout << "Ingrese el ID del turno a modificar: ";
    cin >> IDTurno;
    
    int pos = _archivo.buscar(IDTurno);
    if(pos < 0){
        cout << "Ese ID no existe en el archivo";
        system("pause");
        return;
    }
    
    Turno registro = _archivo.leer(pos);
    
    if(registro.getIDTurno() < 0){
        cout << "Error al buscar el turno" << endl;
        system("pause");
        return;
    }
    
    Fecha newFecha;
    cout << "Ingrese la nueva fecha" << endl;
    newFecha.cargar();
    registro.setFechaProgramada(newFecha);
    
    Hora newHora;
    cout << "Ingrese la nueva hora" << endl;
    newHora.cargar();
    registro.setHoraProgramada(newHora);
    
    if(_archivo.guardar(registro, pos)){
        cout << "El Turno se reprogram¢ exitosamente!" << endl;
        system("pause");
        return;
    }
    else {
        cout << "El Turno no se pudo guardar en el archivo!" << endl;
        system("pause");
        return;
    }
}

///Modificar estado de un turno
void TurnoManager::opcion3(){
    
     int IDTurno;
    cout << "Ingrese el ID del turno a modificar: ";
    cin >> IDTurno;
    
    int pos = _archivo.buscar(IDTurno);
    if(pos < 0){
        cout << "Ese ID no existe en el archivo";
        system("pause");
        return;
    }
    
    Turno registro = _archivo.leer(pos);
    
    if(registro.getIDTurno() < 0){
        cout << "Error al buscar el turno" << endl;
        system("pause");
        return;
    }
    
    int estadoTurno;
    cout << "Seleccione la opcion que corresponda: " << endl;
    cout << "2- Confirmado" << endl;
    cout << "3- Finalizado" << endl;
    cout << "4- Cancelado" << endl;
    cout << "5- Ausente" << endl;
    cout << "Seleccion: ";
    cin >> estadoTurno;
    
    if(estadoTurno < 2 || estadoTurno > 5){
        cout << "Opcion invalida!" << endl;
        system("pause");
        return;
    }
    
    registro.setEstadoTurno(estadoTurno);
    
    if(_archivo.guardar(registro, pos)){
        cout << "El Turno fue modificado exitosamente!" << endl;
        system("pause");
        return;
    }
    else {
        cout << "El Turno no pudo ser modificado!" << endl;
        system("pause");
        return;
    }

}


/// Buscar turnos del paciente
void TurnoManager::opcion4()
{
    Turno registro;
    int dni;
    int cantidad = _archivo.cantidadRegistros();

    cout << "Ingrese el DNI del paciente por el que quiere consultar: " << endl;
    cin >> dni;

    for (int i = 0; i < cantidad; i++)
    {
        registro = _archivo.leer(i);
        if (registro.getDNIPaciente()==dni)
        {
            cout << "-------------------------" << endl;
            registro.toString();
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");
}

/// Listar todos los turnos
void TurnoManager::opcion5()
{
    cout << "Listado de turnos" << endl;
    int cantidad = _archivo.cantidadRegistros();

    for (int i=0; i < cantidad; i++)
    {
        Turno registro = _archivo.leer(i);
        if(registro.getEstadoTurno())
        {
            cout << "-------------------------" << endl;
            registro.toString();
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");

}
