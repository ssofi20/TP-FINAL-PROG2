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
    
    rlutil::cls();
    
    obj.mostrar();
    
    rlutil::locate((consola_ancho - 33) / 2, 26);
    system("pause");
}

//Editar informacion de un paciente por DNI
void PacienteManager::opcion3()
{
    int consola_ancho = 100;
    int dni;
    string texto = "Ingrese el DNI del paciente que desea modificar datos: ";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto << endl;
    
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> dni;
    
    int pos = _archivo.buscar(dni);
    
    rlutil::cls();
    
    string textoError;
    if(pos < 0)
    {
        textoError = "No existe un paciente con ese DNI en el archivo.";
        rlutil::locate((consola_ancho - textoError.length()) / 2, 15);
        cout << textoError;
        rlutil::locate((consola_ancho - 33 / 2), 17);
        system("pause");
        return;
    }

    Paciente obj;

    obj = _archivo.leer(pos);
    
    int x = 0;

    bool salir = true;
    
    while(salir)
    {
        obj.mostrar();
        
        texto = "¨Desea modificar los datos de este paciente?";
        rlutil::locate((consola_ancho - texto.length()) / 2, 25);
        cout << texto;
        
        showItemHorizontal("SI", 41, 27, x == 0);
        showItemHorizontal("NO", 49, 27, x == 1);
        
        int key = rlutil::getkey();
        
        switch(key)
        {
            case 16: //LEFT
                x--;
                if(x < 0){
                    x = 0;
                }
                break;
            case 17: //RIGTH
                x++;
                if(x > 1){
                    x = 1;
                }
                break;
            case 1: //ENTER
                switch(x)
                {
                case 0:
                    salir = false;
                    break;
                case 1:
                    return;
                }
            break;
        }
    }
    
    int y = 0;
        
    rlutil::cls();
    
    while(true)
    {
        
        texto = "SELECCIONE LA OPCION QUE DESEA MODIFICAR";
        rlutil::locate((consola_ancho - texto.length()) / 2, 6);
        cout << texto;
        
        showItem("NOMBRE", 8, y == 0);
        showItem("APELLIDO", 10, y == 1);
        showItem("TELEFONO", 12, y == 2);
        showItem("EMAIL", 14, y == 3);
        showItem("OBRA SOCIAL", 16, y == 4);
        showItem("NUMERO DE AFILIADO", 18, y == 5);
        showItem("FECHA DE NACIMIENTO", 20, y == 6);
        showItem("SALIR", 22, y == 7);
        
        int key = rlutil::getkey();
        
        switch(key)
        {
            case 14: //UP
                y--;
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                y++;
                if(y > 7){
                    y = 7;
                }
                break;
            case 1: //ENTER
                rlutil::cls();
                switch(y)
                {
                    case 0:
                        {
                            char nombre [30];
                            texto = "Ingrese el nuevo nombre del paciente: ";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(nombre, 29);
                            obj.setNombre(nombre);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                rlutil::locate((consola_ancho - texto.length()) / 2, 14);
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 1:
                        {
                            char apellido [40];
                            texto = "Ingrese el nuevo apellido del paciente:";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(apellido, 39);
                            obj.setApellido(apellido);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 2:
                        {
                            char nroTel [11];
                            texto = "Ingrese el nuevo numero de telefono:";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(nroTel, 10);
                            obj.setNombre(nroTel);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 3:
                        {
                            char mail [60];
                            texto = "Ingrese el nuevo correo electronico del paciente:";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(mail, 59);
                            obj.setEmail(mail);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 4:
                        {
                            char obraSocial [50];
                            texto = "Ingrese la nueva obra social del paciente: ";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(obraSocial, 49);
                            obj.setObraSocial(obraSocial);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 5:
                        {
                            char nroAfiliado [11];
                            texto = "Ingrese el nuevo nro. de afiliado del paciente:";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            rlutil::locate(50, 17);
                            cargarCadena(nroAfiliado, 10);
                            
                            int cant = _archivo.cantidadRegistros();
                            for(int i = 0; i < cant; i++)
                            {
                                Paciente paciente = _archivo.leer(i);
                                if(strcmp(paciente.getNumeroAfiliado(), nroAfiliado) == 0)
                                {
                                    rlutil::cls();
                                    texto = "No se puede modificar. Un paciente registrado ya posee ese numero de afiliado";
                                    cout << texto;
                                    rlutil::locate((consola_ancho - 33) / 2, 16);
                                    system("pause");
                                    return;
                                }
                            }

                            obj.setNumeroAfiliado(nroAfiliado);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }

                    case 6:
                        {
                            Fecha fechaNac;
                            texto = "Ingrese la nueva fecha de nacimiento:";
                            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                            cout << texto;
                            fechaNac.cargar(45,17);
                            obj.setDateB(fechaNac);
                            if(_archivo.guardar(obj, pos)){
                                rlutil::cls();
                                texto = "Se actualizaron correctamente los datos del paciente";
                                rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                                cout << texto;
                                rlutil::locate((consola_ancho - 33) / 2, 16);
                                system("pause");
                            }
                            break;
                        }
                    case 7:
                        return;
                }
                rlutil::cls();
            break;
        }
    }
}

//Dar de baja un paciente
void PacienteManager::opcion4()
{

    int consola_ancho = 100;
    int dni;
    string texto = "Ingrese DNI del paciente a dar de baja:";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto << endl;
    
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> dni;
    
    int pos = _archivo.buscar(dni);

    bool encontrado = false;
    
    Paciente registro;
    
    if(pos >= 0)
    {
        encontrado = true;
        registro = _archivo.leer(pos);
    }

    rlutil::cls();
    
    if(encontrado){

        registro.setEstado(false);
        if(_archivo.guardar(registro, pos)){
            texto = "Paciente se ha dado de baja exitosamente!";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto << endl;
        }
        else{
            texto = "Error al dar de baja al paciente";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto << endl;
        }
    } 
    else {
        texto = "No se encontro un paciente con ese DNI en el archivo";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto << endl;
    }
    
    rlutil::locate((consola_ancho - 33) / 2, 17);
    system("pause");
}

//Restaurar un paciente
void PacienteManager::opcion5()
{
    int consola_ancho = 100;

    Paciente registro;
    
    int DNI;
    string texto = "Ingrese el DNI del paciente a dar de alta:";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto;
    
    rlutil::locate((consola_ancho - 8) / 2, 8);
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

    rlutil::cls();
    
    if(encontrado){

        registro.setEstado(true);
        if(_archivo.guardar(registro, pos)){
            texto = "Paciente se restauro exitosamente!";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto << endl;
        }
        else{
            texto = "Error al restaurar el paciente";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto << endl;
        }
    } 
    else {
        texto = "No se encontro un paciente con ese DNI en el archivo";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto << endl;
    }
    
    rlutil::locate((consola_ancho - 33) / 2, 17);
    system("pause");
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
    
    
    rlutil::locate(2, 4);   cout << "DNI";
    rlutil::locate(12, 4);  cout << "Apellido";
    rlutil::locate(28, 4);  cout << "Nombre";
    rlutil::locate(42, 4);  cout << "Telefono";
    rlutil::locate(56, 4);  cout << "Afiliado";
    rlutil::locate(70, 4);  cout << "Obra Social";
    rlutil::locate(88, 4);  cout << "Nacimiento";

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
