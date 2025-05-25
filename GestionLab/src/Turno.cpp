#include "Turnos.h"

/// Constructores

Turno::Turno()
: _fechaProgramada(0,0,0),  _horaProgramada(0,0)
{
    _IDTurno = 0;
    _estadoTurno = 0;
}

Turno::Turno (int IDTurno, Fecha fechaProgramada, Hora horaProgramada, int estadoTurno)
{
    setIDTurno(IDTurno);
    setFechaProgramada(fechaProgramada);
    setHoraProgramada(horaProgramada);
    setEstadoTurno(estadoTurno);
}

/// Setters

void Turno::setIDTurno (int idTurno)
{
    _IDTurno = idTurno;
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

int Turno::getIDTurno ()
{
    return _IDTurno;
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
