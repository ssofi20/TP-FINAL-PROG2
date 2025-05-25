#include "Turnos.h"

/// Constructores

Turnos::Turnos()
{
    _IDTurno = 0;
    _fechaProgramada = 0;
    _horaProgramada = 0;
    _estadoTurno = 0;
}

Turnos::Turnos (int IDTurno, Fecha fechaProgramada, Hora horaProgramada, int estadoTurno)
{
    setIDTurno(IDTurno);
    setFechaProgramada(fechaProgramada);
    setHoraProgramada(horaProgramada);
    setEstadoTurno(estadoTurno);
}

/// Setters

void Turnos::setIDTurno (int idTurno)
{
    _IDTurno = idTurno;
}

void Turnos::setFechaProgramada(Fecha fechaProgramada)
{
    _fechaProgramada = fechaProgramada;
}

void Turnos::setHoraProgramada (Hora horaProgramada)
{
    _horaProgramada = horaProgramada;
}

void Turnos::setEstadoTurno (int estadoTurno)
{
    _estadoTurno = estadoTurno;
}

/// Getters

int Turnos::getIDTurno ()
{
    return _IDTurno;
}

Fecha Turnos::getFechaProgramada()
{
    return _fechaProgramada;
}

Hora Turnos::getHoraProgramada()
{
    return _horaProgramada;
}

int Turnos::getEstadoTurno()
{
    return _estadoTurno;
}
