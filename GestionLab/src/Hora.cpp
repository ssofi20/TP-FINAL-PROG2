#include "Hora.h"
#include <iostream>

using namespace std;

/// Constructores

Hora::Hora()
{
    _hora = 0;
    _minuto =0;
}

Hora::Hora( int hora, int minuto )
{
    _hora = hora;
    _minuto = minuto;
}

/// Setters

void Hora::setHora (int hora)
{
    if (hora < 25)
    {
        _hora = hora;
    }
}

void Hora::setMinuto(int minuto)
{
    if (minuto < 61)
    {
        _minuto = minuto;
    }
}

/// Getters

int Hora::getHora()
{
    return _hora;
}

int Hora::getMinuto()
{
    return _minuto;
}


///Metodos de la clase

void Hora::cargar(){

    cout << "Hora: ";
    cin >> _hora;
    cout << "Minuto: ";
    cin >> _minuto;
    
}

std::string Hora::toString()
{
    return std::to_string(_hora) + ":" + std::to_string(_minuto);
}
