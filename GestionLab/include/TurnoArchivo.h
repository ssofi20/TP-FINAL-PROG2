#pragma once
#include "Turno.h"

class TurnoArchivo
{
    public:
        
        TurnoArchivo(std::string nombreArchivo = "Turnos.dat");
        
        int cantidadRegistros();
        Turno leer(int posicion);
        int buscar(int IDTurno);
        bool guardar(Turno registro);
        bool guardar(Turno registro, int posicion);

    private:
        
        std::string _nombreArchivo;
};

