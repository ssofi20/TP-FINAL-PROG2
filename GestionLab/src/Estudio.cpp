#include "Estudio.h"

 /// Constructores

Estudio::Estudio()
: _turno(0, Fecha(0,0,0), Hora(0,0),1 )
{
    strcpy(_IDEstudio, "SIN ID");
    _DNI = 0;
    _estadoEstudio = 0;
    strcpy(_sala, "SIN SALA");
    _estado = true;
}

Estudio::Estudio(const char *IDEstudio, int dni, int estEstudio, const char *sala, Turno turno)
{
    setIDEstudio(IDEstudio);
    setDNI(dni);
    setEstadoEstudio(estEstudio);
    setSala(sala);
    setTurno(turno);
    setEstado(true);
}

/// Setters

void Estudio::setIDEstudio (const char *idEstudio)
{
    strcpy(_IDEstudio, idEstudio);
}

void Estudio::setDNI (int dni)
{
    _DNI = dni;
}

void Estudio::setEstadoEstudio(int estadoEstudio)
{
    _estadoEstudio = estadoEstudio;
}

void Estudio::setSala (const char *sala)
{
    strcpy(_sala, sala);
}

void Estudio::setTurno(Turno turno)
{
    _turno = turno;
}

void Estudio::setEstado(bool estado)
{
    _estado = estado;
}

/// Getters

const char * Estudio::getIDEstudio()
{
    return _IDEstudio;
}

int Estudio::getDNI()
{
    return _DNI;
}

int Estudio::getEstadoEstudio()
{
    return _estadoEstudio;
}

const char * Estudio::getSala()
{
    return _sala;
}

Turno Estudio::getTurno()
{
    return _turno;
}

bool Estudio::getEstado()
{
    return _estado;
}
