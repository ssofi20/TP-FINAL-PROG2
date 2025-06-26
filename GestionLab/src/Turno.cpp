#include "Turno.h"
#include <iostream>

using namespace std;

/// Constructores

Turno::Turno()
: _fechaProgramada(0,0,0),  _horaProgramada(0,0)
{
    _IDTurno = 0;
    _DNIPaciente = 0;
    _estadoTurno = 0;
}

Turno::Turno (int IDTurno, int DNIPaciente, Fecha fechaProgramada, Hora horaProgramada, int estadoTurno)
{
    setIDTurno(IDTurno);
    setDNIPaciente(DNIPaciente);
    setFechaProgramada(fechaProgramada);
    setHoraProgramada(horaProgramada);
    setEstadoTurno(estadoTurno);
}

/// Setters

void Turno::setIDTurno (int idTurno)
{
    _IDTurno = idTurno;
}

void Turno::setDNIPaciente(int DNIPaciente)
{
    _DNIPaciente = DNIPaciente;
}

void Turno::setFechaProgramada(Fecha fechaProgramada)
{
    _fechaProgramada = fechaProgramada;
}

void Turno::setHoraProgramada (Hora horaProgramada)
{
    _horaProgramada = horaProgramada;
}

void Turno::setEstadoTurno (int estadoTurno)
{
    _estadoTurno = estadoTurno;
}

/// Getters

int Turno::getIDTurno()
{
    return _IDTurno;
}

int Turno::getDNIPaciente()
{
    return _DNIPaciente;
}

Fecha Turno::getFechaProgramada()
{
    return _fechaProgramada;
}

Hora Turno::getHoraProgramada()
{
    return _horaProgramada;
}

int Turno::getEstadoTurno()
{
    return _estadoTurno;
}

///Metodos de la clase
void Turno::cargar(){
    
    const int xCampo = 30;
    const int xIngreso = 55;
    int y = 6;
    
    rlutil::cls();
    
    string titulo = "FORMULARIO REGISTRO DE TURNO";
    rlutil::locate((100 - titulo.length()) / 2, y - 2);
    cout << titulo;
    
    //Mostrar el ID generado.
    rlutil::locate(xCampo, y);
    cout << "ID Turno generado:";
    rlutil::locate(xIngreso, y);
    cout << _IDTurno;
    
    y += 2;

    //DNI paciente
    bool invalido = true;
    PacienteArchivo archivo;
    int dniPaciente;

    while (invalido) {
        rlutil::locate(xCampo, y);
        cout << "DNI Paciente: ";
        rlutil::locate(xIngreso, y);
        cin >> dniPaciente;

        int pos = archivo.buscar(dniPaciente);
        if (pos < 0) {
            rlutil::locate(xCampo, y + 2);
            cout << "No existe un paciente con ese DNI. Intente de nuevo.";
            rlutil::anykey();
            //Limpiar campos
            rlutil::locate(xIngreso, y);
            cout << "           ";
            rlutil::locate(xCampo, y + 2);
            cout << "                                                    ";
        } else {
            invalido = false;
        }
    }

    _DNIPaciente = dniPaciente;
    y += 2;

    //Fecha programada
    invalido = true;
    while (invalido) {
        rlutil::locate(xCampo, y);
        cout << "Fecha programada: ";
        _fechaProgramada.cargar(xIngreso, y);
        
        Fecha fechaActual;
        fechaActual.setFechaActual();

        if (_fechaProgramada.getDia() == 0 || _fechaProgramada.getMes() == 0 || _fechaProgramada.getAnio() == 0 ){
            rlutil::locate(xCampo, y + 3);
            cout << "Fecha invalida! Pruebe de nuevo.";
            rlutil::anykey();
            rlutil::locate(xIngreso, y);
            cout << "           ";
            rlutil::locate(xIngreso, y + 1);
            cout << "           ";
            rlutil::locate(xIngreso, y + 2);
            cout << "           ";
            rlutil::locate(xCampo, y + 3);
            cout << "                                ";
        }
        else {
            invalido = false;
        }
    }

    y += 4;

    //Hora programada
    invalido = true;
    while (invalido) {
        rlutil::locate(xCampo, y);
        cout << "Hora programada: ";
        _horaProgramada.cargar(xIngreso, y);

        if (_horaProgramada.getHora() == 0 || _horaProgramada.getMinuto() == -1) {
            rlutil::locate(xCampo, y + 2);
            cout << "Hora invalida! Pruebe de nuevo.";
            rlutil::anykey();
            rlutil::locate(xIngreso, y);
            cout << "           ";
            rlutil::locate(xIngreso, y + 1);
            cout << "           ";
            rlutil::locate(xCampo, y + 2);
            cout << "                               ";
        } else {
            invalido = false;
        }
    }

    _estadoTurno = true;
    
}

string Turno::estadoToString()
{
    switch(_estadoTurno) {
        case 1: return "Pendiente";
        case 2: return "Confirmado";
        case 3: return "Finalizado";
        case 4: return "Cancelado";
        case 5: return "Ausente";
    }
}

void Turno::mostrar(int y){
    
    rlutil::locate(3, y);   cout << _IDTurno;
    rlutil::locate(12, y);  cout << _DNIPaciente;
    rlutil::locate(28, y);  cout << _fechaProgramada.toString();
    rlutil::locate(45, y);  cout << _horaProgramada.toString();
    rlutil::locate(60, y);  cout << estadoToString();
}
