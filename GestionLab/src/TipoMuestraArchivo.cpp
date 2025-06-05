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
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return TipoMuestra();
    }
    TipoMuestra registro;
    fseek(pFile, sizeof (TipoMuestra) * posicion, SEEK_SET);
    fread(&registro, sizeof(TipoMuestra), 1, pFile);
    fclose(pFile);
    return registro;
}

void TipoMuestraArchivo::leer(int cantidadRegistros, TipoMuestra *vec)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        vec[i] = leer(i);
    }
    fclose(pFile);
}

int TipoMuestraArchivo::buscar(int IDMuestra)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return -1;
    }

    TipoMuestra registro;

    int cantidad = cantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        registro = leer(i);
        if (registro.getIDMuestra(), IDMuestra)
        {
            return i;
        }
    }
    return -1;
}

bool TipoMuestraArchivo::guardar(TipoMuestra registro)
{
    FILE *pFile = fopen(_nombreArchivo.c_str() , "ab");
    if (pFile == nullptr)
    {
        return -1;
    }
    bool escribio = fwrite(&registro, sizeof(TipoMuestra), 1, pFile);
    fclose(pFile);
    return escribio;
}

bool TipoMuestraArchivo::guardar(TipoMuestra registro, int posicion)
{
    FILE *pFile = fopen(_nombreArchivo.c_str() , "rb+");
    if (pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile, sizeof (TipoMuestra) * posicion, SEEK_SET);
    bool escribio = fwrite(&registro, sizeof (TipoMuestra), 1, pFile);
    fclose(pFile);
    return escribio;

}
