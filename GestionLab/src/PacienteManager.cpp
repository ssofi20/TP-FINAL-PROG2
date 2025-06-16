#include "PacienteManager.h"
#include <iostream>

using namespace std;

//Registrar nuevo paciente.
void PacienteManager::opcion1()
{
    Paciente obj;
    obj.cargar();
    if (_archivo.guardar(obj))
    {
        cout << "Se pudo guardar el paciente exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el paciente. ";
    }
    system("pause");
}

//Buscar un paciente.
void PacienteManager::opcion2()
{
    cout << "Ingrese el nro. de DNI del paciente que desea buscar: " << endl;
    int dni;
    cin >> dni;
    int pos = _archivo.buscar(dni);
    if (pos < 0)
    {
        cout << "El nro. de DNI no existe en el archivo. " << endl;
        system("pause");
        return;
    }
    Paciente obj = _archivo.leer(pos);
    obj.mostrar();
    system("pause");
}

//Editar informacion de un paciente por DNI
void PacienteManager::opcion3()
{
    int dni;
    cout << "Ingrese el DNI del paciente a modificar: ";
    cin >> dni;

    int pos = _archivo.buscar(dni);
    if(pos < 0)
    {
        cout<<"No existe un paciente con ese DNI en el archivo."<<endl;
        system("pause");
        return;
    }

    Paciente obj;

    obj = _archivo.leer(pos);

    system("cls");
    cout << "Datos del paciente buscado" << endl;
    obj.mostrar();

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
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 2:
        {
        char nombre [30];
        cout<<"Ingrese el nuevo nombre del paciente: "<< endl;
        cargarCadena(nombre, 29);
        obj.setNombre(nombre);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 3:
        {
        char apellido [40];
        cout<<"Ingrese el nuevo apellido del paciente: "<< endl;
        cargarCadena(apellido, 39);
        obj.setApellido(apellido);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 4:
        {
        char nroTel [11];
        cout<<"Ingrese el nuevo nro. de telefono del paciente: "<< endl;
        cargarCadena(nroTel, 10);
        obj.setNombre(nroTel);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 5:
        {
        char mail [60];
        cout<<"Ingrese el nuevo correo electronico del paciente: "<< endl;
        cargarCadena(mail, 59);
        obj.setEmail(mail);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 6:
        {
        char obraSocial [50];
        cout<<"Ingrese la nueva obra social del paciente: "<< endl;
        cargarCadena(obraSocial, 49);
        obj.setObraSocial(obraSocial);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 7:
        {
        char nroAfiliado [11];
        cout<<"Ingrese el nuevo nro. de afiliado del paciente: "<< endl;
        cargarCadena(nroAfiliado, 10);
        obj.setNumeroAfiliado(nroAfiliado);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
        break;
        }

    case 8:
        {
        Fecha fechaNac;
        cout<<"Ingrese la nueva fecha de nacimiento del paciente: " << endl;
        fechaNac.cargar();
        obj.setDateB(fechaNac);
        if(_archivo.guardar(obj, pos)){
            cout << "Se actualizaron correctamente los datos del paciente" << endl;
            system("pause");
        }
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
        else{
            cout << "Error al dar de baja el paciente" << endl;
        }
        system("pause");
    }
    else {
        cout << "No se encontro un paciente con ese DNI en el archivo" << endl;
        system("pause");
    }
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
            system("pause");
        }
        else{
            cout << "Error al restaurar el paciente" << endl;
            system("pause");
        }
    } else {
        cout << "No se encontro un paciente con ese DNI en el archivo" << endl;
        system("pause");
    }
}

//Mostrar lista de pacientes
void PacienteManager::opcion6(){

    cout << "Listado de pacientes" << endl;
    int cant = _archivo.cantidadRegistros();

    if(cant <= 0){
        return ;
    }

    Paciente *vecRegistros = new Paciente[cant];
    if(vecRegistros == nullptr){
        cout << "Error al pedir memoria" << endl;
        system("pause");
        return;
    }
    _archivo.leer(cant,vecRegistros);
    for (int i = 0; i < cant; i++){
        Paciente registro = _archivo.leer(i);
        if(registro.getEstado()){
            cout << "-------------------------" << endl;
            registro.mostrar();
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");
}
