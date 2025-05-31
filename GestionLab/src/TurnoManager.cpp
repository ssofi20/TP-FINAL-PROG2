#include "TurnoManager.h"
#include <iostream>

using namespace std;


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
