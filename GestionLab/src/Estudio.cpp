#include "Estudio.h"
#include <iostream>

using namespace std;

/// Constructores

Estudio::Estudio()
{
    strcpy(_IDEstudio, "SIN ID");
    _DNI = 0;
    _estadoEstudio = 0;
    strcpy(_sala, "SIN SALA");
    _IDTurno = 0;
    _estado = true;
}

Estudio::Estudio(const char *IDEstudio, int dni, int estEstudio, const char *sala, int IDTurno)
{
    setIDEstudio(IDEstudio);
    setDNI(dni);
    setEstadoEstudio(estEstudio);
    setSala(sala);
    setIDTurno(IDTurno);
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

void Estudio::setIDTurno(int IDTurno)
{
    _IDTurno = IDTurno;
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

int Estudio::getIDTurno()
{
    return _IDTurno;
}

bool Estudio::getEstado()
{
    return _estado;
}

//METODOS CARGAR Y MOSTRAR
void Estudio::cargar()
{
    cout << "ID del estudio: ";
    cargarCadena(_IDEstudio, 11);
    cout << "DNI: ";
    cin >> _DNI;
     cout << "Estado del estudio: ";
    cin >> _estadoEstudio;
    cout << "Sala: ";
    cargarCadena(_sala, 5);
    cout << "ID turno: ";
   cin >> _IDTurno;
    _estado = true;
}

void Estudio::mostrar()
{
    cout << "ID ESTUDIO: " << _IDEstudio << endl;
    cout << "DNI: " << _DNI << endl;
    cout << "ESTADO DEL ESTUDIO: " << _estadoEstudio << endl;
    cout << "SALA: " << _sala << endl;
    cout << "ID TURNO: " << _IDTurno << endl;
}

