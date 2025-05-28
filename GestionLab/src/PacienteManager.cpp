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

void PacienteManager::mostrar(Paciente registro)
{

    cout << "DNI: " << registro.getDNI() << endl;

    cout << "Nombre/s: " << registro.getNombre() << endl;

    cout << "Apellido/s: " << registro.getApellido() << endl;

    cout << "Fecha Nacimiento: " << registro.getDateB().toString() << endl;

    cout << "Telefono: " << registro.getTelefono() << endl;

    cout << "Email: "  << registro.getEmail() << endl;

    cout << "Obra social: " << registro.getObraSocial() << endl;

    cout << "Numero de afiliado: " << registro.getNumeroAfiliado() << endl;

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
