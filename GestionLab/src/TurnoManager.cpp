#include "TurnoManager.h"
#include <iostream>

using namespace std;


/// Buscar turnos del paciente
void TurnoManager::opcion4()
{
    TurnoArchivo registro;
    int dni, idTurno;

    cout << "Ingrese el DNI del paciente por el que quiere consultar: " << endl;
    cin >> dni;
    cout << "Ingrese el ID del turno: " << endl;
    cin >> idTurno;
    int pos = _archivo.buscar( idTurno, dni);
    if (pos < 0)
    {
        cout << "El nro. de DNI no existe en el archivo. " << endl;
        return;
    }
    Turno obj = _archivo.leer(pos);
    cout << obj.toString() << endl;
    system("pause");
}

/// Listar todos los turnos
void TurnoManager::opcion5()
{
    cout << "Listado de turnos" << endl;
    int cantidad = _archivo.cantidadRegistros();

    Turno *vecReg = new Turno[cantidad];
    if(vecReg == nullptr){
        cout << "Error al pedir memoria" << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++){
            vecReg[i] = _archivo.leer(i);
    }
    for (int i=0; i < cantidad; i++)
    {
        Turno registro = _archivo.leer(i);
        if(registro.getEstadoTurno()){
            cout << "-------------------------" << endl;
            registro.toString();
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");

}
