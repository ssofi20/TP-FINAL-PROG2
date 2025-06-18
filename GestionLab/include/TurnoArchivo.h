#pragma once
#include "Turno.h"

class TurnoArchivo
{
    public:
        
        TurnoArchivo(std::string nombreArchivo = "archivos/Turnos.dat");
        
        int cantidadRegistros();
        Turno leer(int posicion);
        int buscar(int IDTurno);
        bool guardar(Turno registro);
        bool guardar(Turno registro, int posicion);
        bool copiaSeguridad();
        bool restaurarCopia();
        int getID();

    private:
        
        std::string _nombreArchivo;
};

