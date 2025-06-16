#pragma once
#include "Estudio.h"
#include <string>
#include <cstring>


class EstudioArchivo
{
    private:
        std::string _nombreArchivo;

    public:

        EstudioArchivo(std::string nombreArchivo = "archivos/Estudios.dat");
        int cantidadRegistros();
        Estudio leer(int posicion);
        void leer(int cantidadRegistros, Estudio *vec);
        int buscar(const char* IDEstudio);
        bool guardar(Estudio registro);
        bool guardar(Estudio registro, int posicion);
        bool copiaSeguridad();

};

