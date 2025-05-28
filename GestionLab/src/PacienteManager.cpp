#include "PacienteManager.h"
#include <iostream>

using namespace std;

/// Funciones Utiles
void PacienteManager::cargarCadena(char *palabra, int tamano)
{
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++)
    {
        palabra[i]=cin.get();
        if (palabra[i]=='\n')
        {
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

Paciente PacienteManager::cargarPaciente()
{
    int dni;
    char nombres [30];
    char apellidos [40];
    char telefono [10];
    char email [60];
    char nombreOS [60];
    char nroAfiliado [20];
    Fecha fechaNacimiento;
    int dia;
    int mes;
    int anio;


    cout << "Ingrese el DNI del paciente: " << endl;
    cin >> dni;
    cout << "Ingrese el nombre del paciente: " << endl;
    cargarCadena(nombres, 29);
    cout << "Ingrese el apellido del paciente: " << endl;
    cargarCadena(apellidos, 39);
    cout << "Ingrese el correo electronico del paciente: " << endl;
    cargarCadena(email, 59);
    cout << "Ingrese la obra social del paciente: " << endl;
    cargarCadena(nombreOS, 59);
    cout << "Ingrese el nro. de afiliado del paciente: " << endl;
    cargarCadena(nroAfiliado, 19);
    cout << "Ingrese la fecha de nacimiento del paciente: " << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Anio: " << endl;
    cin >> anio;

   return Paciente(dni, nombres, apellidos, telefono, email, nombreOS, nroAfiliado, Fecha (dia, mes, anio));
}


///Registrar nuevo paciente.
void PacienteManager::opcion1()
{
    Paciente obj;
    obj = cargarPaciente();
    if (_archivo.guardar(obj))
    {
        cout << "Se pudo guardar el paciente exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el paciente. ";
    }
}

///Buscar un paciente.
void PacienteManager::opcion2()
{
cout << "Ingrese el nro. de DNI del paciente que desea buscar: " << endl;
    int dni;
    cin >> dni;
    int pos = _archivo.buscar(dni);
    if (pos < 0)
    {
        cout << "El nro. de DNI no existe en el archivo. " << endl;
        return;
    }
    Paciente obj = _archivo.leer(pos);
    //obj.mostrar();
}

void PacienteManager::opcion3()
{

}
