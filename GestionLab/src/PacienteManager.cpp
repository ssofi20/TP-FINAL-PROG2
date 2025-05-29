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
    char telefono [11];
    char email [60];
    char nombreOS [60];
    char nroAfiliado [20];
    Fecha fechaNacimiento;
    int dia;
    int mes;
    int anio;

    //falta telefono
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
    mostrar(obj);
}

///Editar información de un paciente segun DNI
void PacienteManager::opcion3()
{
    int dni;
    cout<<"Ingrese el DNI del paciente a modificar: ";
    cin>>dni;
    int pos = _archivo.buscar(dni);
    if(pos<0)
    {
        cout<<"No existe un paciente con ese DNI en el archivo."<<endl;
        return;
    }
    Paciente obj;
    obj = _archivo.leer(pos);
    int opc;
    cout<<"Ingrese la opcion del dato que quiere modificar: " << endl << endl;
    cout<<"1- Modificar DNI." << endl;
    cout<<"2- Modificar nombre." << endl;
    cout<<"4- Modificar apellido." << endl;
    cout<<"5- Modificar nro. de telefono." << endl;
    cout<<"6- Modificar email." << endl;
    cout<<"7- Modificar Obra Social." << endl;
    cout<<"8- Modificar nro. de Afiliado." << endl;
    cout<<"9- Modificar fecha de nacimiento." << endl;
    cout <<"0- Volver al menu anterior." << endl;
    cin >> opc;
    switch(opc)
    {
    case 1:
        {
        int dniNuevo;
        cout<<"Ingrese el nuevo DNI del paciente: "<< endl;
        cin >> dniNuevo;
        obj.setDNI(dniNuevo);
        _archivo.guardar(obj, pos);
        break;
        }

    case 2:
        {
        char nombre [30];
        cout<<"Ingrese el nuevo nombre del paciente: "<< endl;
        cargarCadena(nombre, 29);
        obj.setNombre(nombre);
        _archivo.guardar(obj, pos);
        break;
        }

    case 3:
        {
        char apellido [40];
        cout<<"Ingrese el nuevo apellido del paciente: "<< endl;
        cargarCadena(apellido, 39);
        obj.setApellido(apellido);
        _archivo.guardar(obj, pos);
        break;
        }

    case 4:
        {
        char nroTel [11];
        cout<<"Ingrese el nuevo nro. de telefono del paciente: "<< endl;
        cargarCadena(nroTel, 10);
        obj.setNombre(nroTel);
        _archivo.guardar(obj, pos);
        break;
        }

    case 5:
        {
        char mail [60];
        cout<<"Ingrese el nuevo correo electronico del paciente: "<< endl;
        cargarCadena(mail, 59);
        obj.setEmail(mail);
        _archivo.guardar(obj, pos);
        break;
        }

    case 6:
        {
        char obraSocial [50];
        cout<<"Ingrese la nueva obra social del paciente: "<< endl;
        cargarCadena(obraSocial, 49);
        obj.setObraSocial(obraSocial);
        _archivo.guardar(obj, pos);
        break;
        }

    case 7:
        {
        char nroAfiliado [11];
        cout<<"Ingrese el nuevo nro. de afiliado del paciente: "<< endl;
        cargarCadena(nroAfiliado, 10);
        obj.setNumeroAfiliado(nroAfiliado);
        _archivo.guardar(obj, pos);
        break;
        }

    case 8:
        {
        Fecha fechaNac;
        int dia, mes, anio;
        cout<<"Ingrese la nueva fecha de nacimiento del paciente: " << endl;
        cout<<"Dia: " << endl;
        cin>> dia;
        fechaNac.setDia(dia);
        cout<<"Mes: " << endl;
        cin>> mes;
        fechaNac.setMes(mes);
        cout<<"Anio: " << endl;
        cin>> anio;
        fechaNac.setAnio(anio);
        obj.setDateB(fechaNac);
        _archivo.guardar(obj, pos);
        break;
        }

    case 0:
        {
        return;
        }
    default:
        {
        cout << "Opcion incorrecta! Intente nuevamente" << endl;
        system("pause");
        break;
        }
    }
}


//Dar de baja un paciente
void PacienteManager::opcion4()
{

    Paciente registro;
    int DNI;
    cout << "Ingrese le DNI del paciente a dar de baja: ";
    cin >> DNI;

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++)
    {

        registro = _archivo.leer(i);
        if(registro.getDNI() == DNI)
        {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado)
    {

        registro.setEstado(false);
        if(_archivo.guardar(registro, pos))
        {
            cout << "Paciente dado de baja exitosamente!" << endl;
        }
        else
        {
            cout << "Error al dar de baja el paciente" << endl;
        }
    }
    cout << "No se encontro un paciente con ese DNI en el archivo" << endl;
    system("pause");
}

//Restaurar un paciente
void PacienteManager::opcion5()
{

    Paciente registro;
    int DNI;
    cout << "Ingrese le DNI del paciente a dar de alta: ";
    cin >> DNI;

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++)
    {

        registro = _archivo.leer(i);
        if(registro.getDNI() == DNI)
        {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado)
    {

        registro.setEstado(true);
        if(_archivo.guardar(registro, pos))
        {
            cout << "Paciente se restauro exitosamente!" << endl;
        }
        else
        {
            cout << "Error al restaurar el paciente" << endl;
        }
    }
    cout << "No se encontro un paciente con ese DNI en el archivo" << endl;
    system("pause");
}

//Mostrar lista de pacientes
void PacienteManager::opcion6()
{

    cout << "Listado de pacientes" << endl;
    int cant = _archivo.cantidadRegistros();

    Paciente *vecRegistros = new Paciente[cant];
    if(vecRegistros == nullptr)
    {
        cout << "Error al pedir memoria" << endl;
        return;
    }
    _archivo.leer(cant,vecRegistros);
    for (int i = 0; i < cant; i++)
    {
        Paciente registro = _archivo.leer(i);
        cout << "-------------------------" << endl;
        mostrar(registro);
        cout << "-------------------------" << endl << endl;
    }
    system("pause");
}
