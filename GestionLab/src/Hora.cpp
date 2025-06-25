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
    else {
        _hora = 0;
    }
}

void Hora::setMinuto(int minuto)
{
    if (minuto < 61 && minuto >0)
    {
        _minuto = minuto;
    }
    else {
        _minuto = 0;
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

void Hora::cargar(int x, int y){

    int hora, minuto;

    rlutil::locate(x, y);
    cout << "Hora: ";
    rlutil::locate(x + 6, y);
    cin >> hora;
    
    setHora(hora);

    rlutil::locate(x, y + 1);
    cout << "Minuto: ";
    rlutil::locate(x + 8, y + 1);
    cin >> minuto;
    
    setMinuto(minuto);
    
}

std::string Hora::toString()
{
    return std::to_string(_hora) + ":" + std::to_string(_minuto);
}
