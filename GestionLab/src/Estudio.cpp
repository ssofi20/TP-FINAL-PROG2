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

void Estudio::setIDEstudio(const char *idEstudio)
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
    char IDEstudio[11];
    char sala[6];
    int dni, IDTurno;
    
    cout << "ID del estudio: "; 
    cargarCadena(IDEstudio, 10);
    setIDEstudio(IDEstudio);
    
    cout << "DNI: ";
    cin >> dni;
    setDNI(dni);
    
    cout << "Sala: ";
    cargarCadena(sala, 5);
    setSala(sala);
    
    cout << "ID turno: ";
    cin >> _IDTurno;
    setIDTurno(IDTurno);
    
    _estado = true;
    _estadoEstudio = 1;
}

void Estudio::mostrar()
{
    cout << "ID ESTUDIO: " << _IDEstudio << endl;
    cout << "DNI: " << _DNI << endl;
    cout << "SALA: " << _sala << endl;
    cout << "ID TURNO: " << _IDTurno << endl;
    cout << "ESTADO DEL ESTUDIO: ";
    switch(_estadoEstudio){
    case 1:
        cout << "En proceso" << endl;
        break;
    case 2:
        cout << "Esperando resultados" << endl;    
        break;
    case 3:
        cout << "Resultados listos" << endl;
        break;
    case 4:
        cout << "Anulado" << endl;
        break;
    }
}

