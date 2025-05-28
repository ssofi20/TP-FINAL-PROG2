#pragma once
#include <cstring>

class TipoMuestraArchivo
{
public:

    TipoMuestraArchivo (std::string nombreArchivo);
    int cantidadRegistros();
    TipoMuestra leer(int posicion);
    void leer(int cantidadRegistros, TipoMuestra *vec);
    int buscar(int IDMuestra);
    bool guardar(TipoMuestra registro);
    bool guardar(TipoMuestra registro, int posicion);

private:
    std::string _nombreArchivo;
};

