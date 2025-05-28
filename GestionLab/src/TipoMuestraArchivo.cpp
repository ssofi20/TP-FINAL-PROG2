#include "TipoMuestraArchivo.h"

TipoMuestraArchivo::TipoMuestraArchivo (std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int TipoMuestraArchivo::cantidadRegistros()
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return -1;
    }
    fseek (pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof (TipoMuestra);
    fclose(pFile);
    return cantidad;

}

TipoMuestra TipoMuestraArchivo::leer(int posicion)
{

}

void TipoMuestraArchivo::leer(int cantidadRegistros, TipoMuestra *vec)
{

}

int TipoMuestraArchivo::buscar(int IDMuestra)
{

}

bool TipoMuestraArchivo::guardar(TipoMuestra registro)
{

}

bool TipoMuestraArchivo::guardar(TipoMuestra registro, int posicion)
{

}
