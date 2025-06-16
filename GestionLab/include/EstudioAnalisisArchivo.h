#pragma once
#include "EstudioAnalisis.h"
#include <string>

class EstudioAnalisisArchivo
{
    public:

        EstudioAnalisisArchivo(std::string nombreArchivo = "archivos/EstudioAnalisis.dat");
        int cantidadRegistros();
        EstudioAnalisis leer(int posicion);
        bool guardar(EstudioAnalisis registro);
        bool guardar(EstudioAnalisis registro, int posicion);
        bool copiaSeguridad();
        bool restaurarCopia();

    private:

        std::string _nombreArchivo;

};
