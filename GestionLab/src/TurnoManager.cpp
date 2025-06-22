#include "TurnoManager.h"
#include <iostream>

using namespace std;

//Agregar turno al archivo
void TurnoManager::opcion1()
{

    const int consola_ancho = 100;
    Turno registro;
    rlutil::cls();

    //Generar el ID automaticamente
    registro.setIDTurno(_archivo.getID());

    registro.cargar();
    
    string texto;
    
    rlutil::cls();
    
    if(_archivo.guardar(registro)){
        texto = "El Turno se registro correctamente";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33) / 2, 16);
        system("pause");
    } 
    else {
        texto = "El turno no se pudo registrar";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33) / 2, 16);
        system("pause");
    }
}

//Cambiar fecha y hora de un turno
void TurnoManager::opcion2()
{
    int consola_ancho = 100;
    string texto;
    
    int IDTurno;
    texto = "Ingrese el ID del turno que desea reprogramar: ";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto;
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> IDTurno;
    
    rlutil::cls();
    
    int pos = _archivo.buscar(IDTurno);
    
    if(pos < 0){
        texto = "Ese ID no existe en el archivo";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33), 16);
        system("pause");
        return;
    }
    
    Turno registro = _archivo.leer(pos);
    
    int y = 0;
    Fecha newFecha;
    Hora newHora;
    
    bool salir = true;
    
    while(salir)
    {
        rlutil::cls();
        
        texto = "SELECCIONE LA OPCION QUE CORRESPONDA";
        rlutil::locate((consola_ancho - texto.length()) / 2, 8);
        cout << texto;
        
        showItem("NUEVA FECHA", 10, y == 0);
        showItem("NUEVO HORARIO", 12, y == 1);
        showItem("VOLVER A ATRAS", 16, y == 2);
        
        int key = rlutil::getkey();
        
        switch(key)
        {
        case 14: //Up
            y--;
            if(y < 0){
                y = 0;
            }
            break;
        case 15: //Down
            y++;
            if(y > 2){
                y = 2;
            }
            break;
        case 1: //Enter
            rlutil::cls();
            switch(y)
            {
            case 0: //Cambiar fecha
                texto = "Ingrese la nueva fecha";
                rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                cout << texto;
                newFecha.cargar(45, 17);
                registro.setFechaProgramada(newFecha);
                break;
            case 1: //Cambiar hora
                texto = "Ingrese la nueva hora: ";
                rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                cout << texto;
                newHora.cargar(45, 17);
                registro.setHoraProgramada(newHora);
                break;
            case 2: //Salir
                return;
            }
            break;
        }
    }
    
    rlutil::cls();
    
    if(_archivo.guardar(registro, pos)){
        texto = "El Turno se reprogram¢ exitosamente!";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
    }
    else {
        texto = "El Turno no se pudo guardar en el archivo!";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
    }
    rlutil::locate((consola_ancho - 33) / 2, 16); 
    system("pause");
    return;
}

//Modificar estado de un turno
void TurnoManager::opcion3()
{
    
    int consola_ancho = 100;
    string texto;
    
    int IDTurno;
    texto = "Ingrese el ID del turno a modificar: ";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto;
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> IDTurno;
    
    rlutil::cls();
    
    int pos = _archivo.buscar(IDTurno);
    
    if(pos < 0){
        texto = "Ese ID no existe en el archivo";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33), 16);
        system("pause");
        return;
    }
    
    int y = 0;
    int estadoTurno;
    bool salir = true;
    
    while(salir)
    {
        texto = "SELECCIONE LA OPCION QUE CORRESPONDA";
        rlutil::locate((consola_ancho - texto.length()) / 2, 8);
        cout << texto;
        
        showItem("CONFIRMADO", 10, y == 0);
        showItem("FINALIZADO", 12, y == 1);
        showItem("CANCELADO", 14, y == 2);
        showItem("AUSENTE", 16, y == 3);
        showItem("SALIR", 20, y == 4);
        
        int key = rlutil::getkey();
        
        switch(key)
        {
        case 14: //Up
            y--;
            if(y < 0){
                y = 0;
            }
            break;
        case 15: //Down
            y++;
            if(y > 4){
                y = 4;
            }
            break;
        case 1: //Enter
            rlutil::cls();
            switch(y)
            {
            case 0: //Confirmado
                estadoTurno = 2;
                break;
            case 1: //Finalizado
                estadoTurno = 3;
                break;
            case 2: //Cancelado
                estadoTurno = 4;
                break;
            case 3: //Ausente
                estadoTurno = 5;
                break;
            case 4: //Salir
                return;
            }
            salir = false;
            break;
        }
    }
    
    rlutil::cls();
    Turno registro = _archivo.leer(pos);
    registro.setEstadoTurno(estadoTurno);
    
    if(_archivo.guardar(registro, pos)){
        texto = "El Turno fue modificado exitosamente!";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
    }
    else {
        texto = "El Turno no pudo ser modificado!";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
    }
    rlutil::locate((consola_ancho - 33) / 2, 16); 
    system("pause");
    return;
}

//Buscar turnos del paciente
void TurnoManager::opcion4()
{
    int consola_ancho = 100;
    int dni;
    int cantidad = _archivo.cantidadRegistros();

    string texto;
    
    texto = "Ingrese el DNI del paciente por el que quiere consultar: ";
    rlutil::locate((consola_ancho - texto.length()) / 2, 6);
    cout << texto;
    rlutil::locate((consola_ancho - 8) / 2, 8);
    cin >> dni;
    
    PacienteArchivo archivoPaciente;
    
    int pos = archivoPaciente.buscar(dni);
    
    rlutil::cls();
    
    if(pos < 0)
    {
        texto = "No existe un paciente con ese DNI en el archivo.";
        rlutil::locate((consola_ancho - texto.length()) / 2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33 / 2), 17);
        system("pause");
        return;
    }
        
    texto = "LISTADO DE TURNOS DEL PACIENTE";
    rlutil::locate((consola_ancho - texto.length()) / 2, 4);
    cout << texto;
    
    // Mostrar encabezados
    rlutil::locate(3, 6);  cout << "ID";
    rlutil::locate(12, 6); cout << "DNI";
    rlutil::locate(28, 6); cout << "Fecha";
    rlutil::locate(45, 6); cout << "Hora";
    rlutil::locate(60, 6); cout << "Estado";
    
    rlutil::locate(3, 7);
    cout << string(75, '-');

    int y = 8;
    Turno registro;
    for (int i = 0; i < cantidad; i++)
    {
        registro = _archivo.leer(i);
        if (registro.getDNIPaciente() == dni)
        {
            registro.mostrar(y);
            y++;
        }
    }
    
    rlutil::locate((consola_ancho - 33)/2, y + 2);
    system("pause");
}

//Listar todos los turnos
void TurnoManager::opcion5()
{
    int consola_ancho = 100;
    string texto = "LISTADO DE TURNOS";
    rlutil::locate((consola_ancho - texto.length()) / 2, 4);
    cout << texto;
    
    // Mostrar encabezados
    rlutil::locate(3, 6);  cout << "ID";
    rlutil::locate(12, 6); cout << "DNI";
    rlutil::locate(28, 6); cout << "Fecha";
    rlutil::locate(45, 6); cout << "Hora";
    rlutil::locate(60, 6); cout << "Estado";
    
    rlutil::locate(3, 7);
    cout << string(75, '-');
    
    int cantidad = _archivo.cantidadRegistros();

    int y = 8;
    
    for (int i = 0; i < cantidad; i++)
    {
        Turno registro = _archivo.leer(i);
        if(registro.getEstadoTurno())
        {
            registro.mostrar(y);
            y++;
        }
    }
    rlutil::locate((consola_ancho - 33)/2, y + 2);
    system("pause");
}
