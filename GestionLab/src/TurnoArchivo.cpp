#include "TurnoArchivo.h"

TurnoArchivo::TurnoArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}
 
int TurnoArchivo::cantidadRegistros(){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Turno);
    fclose(pFile);
    return cantidad;
    
}

Turno TurnoArchivo::leer(int posicion){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return Turno();
    }
    Turno registro;
    fseek(pFile, sizeof(Turno) * posicion, SEEK_SET);
    fread(&registro, sizeof(Turno), 1, pFile);
    fclose(pFile);
    return registro;
    
}
int TurnoArchivo::buscar(int IDTurno, int DNIPaciente){
}
bool TurnoArchivo::guardar(Turno registro){
}
bool TurnoArchivo::guardar(Turno registro, int posicion){
}
