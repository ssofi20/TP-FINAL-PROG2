#include "Fecha.h"
#include <ctime>
#include <iostream>

using namespace std;

//CONSTRUCTORES
Fecha::Fecha(){

    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

//METODOS DE LA CLASE
std::string Fecha::toString(){

    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);

}

bool Fecha::esBisiesto(){
    if(_anio%400 == 0 || (_anio % 4 == 0 && _anio % 100 != 0)){
        return true;
    }
    return false;
}

//GETTERS
int Fecha::getDia(){

    return _dia;
}

int Fecha::getMes(){

    return _mes;
}

int Fecha::getAnio(){

    return _anio;
}

//SETTERS
void Fecha::setDia(int dia){

    if(dia <= 31 && dia >=1){
        _dia = dia;
    }
}

void Fecha::setMes(int mes){

    if(mes <= 12 && mes >= 1){
        if(_dia == 31){
            switch(_mes){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    _mes = _mes;
                    break;
                default:
                    _mes = 0;
                    break;
            }
        }
        else if(_dia == 30 && mes == 2){
            _mes = 0;
        }
        else if(_dia == 29 && mes == 2 && !esBisiesto()){
            _mes = 0;
        }
        else {
            _mes = mes;
        }
    }
    else {
        _mes = 0;
    }
}

void Fecha::setAnio(int anio){
    if(anio <= 1900){
        _anio = anio;
    }     
    else {
        _anio = 0;
    }
}

void Fecha::setFechaActual(){
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    _dia = now->tm_mday;
    _mes = now->tm_mon + 1;
    _anio = now->tm_year + 1900;
}

void Fecha::cargar(){
    
    int dia, mes, anio;
    
    cout << "Dia: ";
    cin >> dia;
    setDia(dia);
    cout << "Mes: ";
    cin >> mes;
    setMes(mes);
    cout << "Anio: ";
    cin >> anio;
    setAnio(anio);

}

