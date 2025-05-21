#include "Fecha.h"

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
        _mes = mes;
    }
}

void Fecha::setAnio(int anio){
    
    if(anio > 1900){
        _anio = anio;
    }
}

//METODOS DE LA CLASE
std::string Fecha::toString(){
    
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);

}
