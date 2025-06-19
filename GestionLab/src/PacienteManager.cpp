#include "PacienteManager.h"
#include <iostream>

using namespace std;

//Registrar nuevo paciente.
void PacienteManager::opcion1()
{
    Paciente obj;
    int consola_ancho = 100;
    bool yaExiste = true;
    
    while (yaExiste)
    {
        obj.cargar();
        
        int band = 0;
        
        int pos = _archivo.buscar(obj.getDNI());
        
        string textoError;
        
        if(pos >= 0)
        {
            rlutil::cls();
            textoError = "Ya existe un paciente con ese DNI. Intente nuevamente.";
            rlutil::locate((consola_ancho - textoError.length()) / 2, 15);
            cout << textoError << endl;
            band ++;
            rlutil::locate((consola_ancho - 33) / 2, 16);
            system("pause");
        }
        
        Paciente paciente = _archivo.leer(pos);
        if(strcmp(paciente.getNumeroAfiliado(), obj.getNumeroAfiliado()) == 0)
        {
            rlutil::cls();
            textoError = "Ya existe un paciente con ese numero de afiliado. Intente nuevamente.";
            rlutil::locate((consola_ancho - textoError.length()) / 2, 15);
            cout << textoError << endl;
            band ++;
            rlutil::locate((consola_ancho - 33) / 2, 16);
            system("pause");
        }
        
        if(band == 0)
        {
            yaExiste = false;
        }
        
        system("cls");
    }
    
    string textoMensaje;
    
    if (_archivo.guardar(obj))
    {
        rlutil::cls();
        textoMensaje = "Se pudo guardar el paciente exitosamente!";
        rlutil::locate((consola_ancho - textoMensaje.length()) / 2, 15);
        cout << textoMensaje << endl;
    }
    else
    {
        rlutil::cls();
        textoMensaje = "Se no pudo guardar el paciente exitosamente!";
        rlutil::locate((consola_ancho - textoMensaje.length()) / 2, 15);
        cout << textoMensaje << endl;
    }
    rlutil::locate((consola_ancho - 33) / 2, 16);
    system("pause");
}

//Buscar un paciente.
void PacienteManager::opcion2()
{
    int consola_ancho = 100;
    int dni;
    string texto = "Ingrese el numero de DNI del paciente que desea buscar: ";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto << endl;
    
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> dni;
    int pos = _archivo.buscar(dni);
    
    if (pos < 0)
    {
        rlutil::cls();
        texto = "El numero de DNI no existe en el sistema.";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto << endl;
        rlutil::locate((consola_ancho - 33) / 2, 16);
        system("pause");
        return;
    }
    
    Paciente obj = _archivo.leer(pos);
    
    obj.mostrar();
    
    rlutil::locate((consola_ancho - 33) / 2, 26);
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
        
        int pos = _archivo.buscar(dniNuevo);
        
        if(pos >= 0)
        {
            cout << "No se puede modificar. Un paciente registrado ya posee ese DNI." << endl;
            return;
        }
        
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
        
        int cant = _archivo.cantidadRegistros();
        for(int i = 0; i < cant; i++)
        {
            Paciente paciente = _archivo.leer(i);
            if(strcmp(paciente.getNumeroAfiliado(), nroAfiliado) == 0)
            {
                cout << "No se puede modificar. Un paciente registrado ya posee ese numero de afiliado" << endl;
                return;
            }
        }

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
void PacienteManager::opcion4()
{

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
void PacienteManager::opcion5()
{

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
void PacienteManager::opcion6()
{
    int consola_ancho = 100;

    rlutil::cls();
    string titulo = "LISTADO DE PACIENTES";
    rlutil::locate((consola_ancho - titulo.length()) / 2, 2);
    cout << titulo;

    int cant = _archivo.cantidadRegistros();

    if (cant <= 0) {
        rlutil::locate(30, 5);
        cout << "No hay pacientes registrados.";
        rlutil::locate((consola_ancho - 33) / 2, 6);
        system("pause");
        return;
    }
    
    
    rlutil::locate(3, 4);   cout << "DNI";
    rlutil::locate(12, 4);  cout << "Apellido";
    rlutil::locate(30, 4);  cout << "Nombre";
    rlutil::locate(46, 4);  cout << "Telefono";
    rlutil::locate(58, 4);  cout << "Afiliado";
    rlutil::locate(72, 4);  cout << "Obra Social";
    rlutil::locate(92, 4);  cout << "Nacimiento";

    rlutil::locate(3, 5);
    cout << string(96, '-');

     int y = 6;
    for (int i = 0; i < cant; i++) {
        Paciente reg = _archivo.leer(i);
        if (reg.getEstado()) {
            reg.mostrarHorizontal(y);
            y++; 
        }
    }

    rlutil::locate((consola_ancho - 35) / 2, y + 2);
    system("pause");
}
