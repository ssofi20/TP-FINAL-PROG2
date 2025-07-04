#pragma once
#include "TipoMuestra.h"
#include <string>
#include <cstring>

class TipoMuestraArchivo
{
public:

    TipoMuestraArchivo (std::string nombreArchivo = "archivos/TiposMuestras.dat");
    int cantidadRegistros();
    TipoMuestra leer(int posicion);
    void leer(int cantidadRegistros, TipoMuestra *vec);
    int buscar(int IDMuestra);
    bool guardar(TipoMuestra registro);
    bool guardar(TipoMuestra registro, int posicion);
    bool copiaSeguridad();
    bool restaurarCopia();

private:
    std::string _nombreArchivo;
};

