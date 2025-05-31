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
    
    cout << "ID Turno: "; 
    cin >> _IDTurno;
    
    cout << "DNI Paciente: ";
    cin >> _DNIPaciente;
    
    cout << "Fecha programada: ";
    _fechaProgramada.cargar();
    
    cout << "Hora programada: ";
    _horaProgramada.cargar();
    
    _estadoTurno = 1;
    
}

void Turno::mostrar(){
    
    cout << "ID Turno: " << _IDTurno << endl;
    cout << "DNI Paciente: " << _DNIPaciente << endl;
    cout << "Fecha: " << _fechaProgramada.toString() << endl;
    cout << "Hora: "  << _horaProgramada.toString() << endl;
    cout << "Estado del turno: ";
    
    switch(_estadoTurno){
    case 1:
        cout << "Pendiente" << endl;
        break;
    case 2:
        cout << "Confirmado" << endl;
        break;
    case 3:
        cout << "Finalizado" << endl;
        break;
    case 4:
        cout << "Cancelado" << endl;
        break;
    case 5:
        cout << "Ausente" << endl;
        break;
    }
}
