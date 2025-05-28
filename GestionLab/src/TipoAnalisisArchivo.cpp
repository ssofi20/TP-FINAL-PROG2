#include "TipoAnalisisArchivo.h"

TipoAnalisisArchivo::TipoAnalisisArchivo (std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int TipoAnalisisArchivo::cantidadRegistros()
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if  (pFile == nullptr)
    {
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof (TipoAnalisis);
    fclose(pFile);
    return cantidad;
}

TipoAnalisis TipoAnalisisArchivo::leer(int posicion)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if  (pFile == nullptr)
    {
        return TipoAnalisis();
    }
    TipoAnalisis registro;
    fseek(pFile, sizeof (TipoAnalisis) *posicion, SEEK_SET);
    fread(&registro, sizeof(TipoAnalisis), 1, pFile);
    fclose(pFile);
    return registro;

}

void TipoAnalisisArchivo::leer(int cantidadRegistros, TipoAnalisis *vec)
{
     FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if  (pFile == nullptr)
    {
        return;
    }
    for (int i = 0; i<cantidadRegistros; i++)
    {
        vec[i] = leer(i);
    }
    fclose(pFile);
}

int TipoAnalisisArchivo::buscar(int IDAnalisis)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return -1;
    }
     TipoAnalisis registro;
     int cantidad = cantidadRegistros();
     for (int i = 0; i<cantidad; i++)
     {
     FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return -1;
    }
    TipoAnalisis registro;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if (registro.getIDAnalisis() == IDAnalisis)
        {
            return i;
        }
    }
}
    return -1;
}

bool TipoAnalisisArchivo::guardar(TipoAnalisis registro)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr)
    {
        return -1;
    }
    bool escribio =  fwrite(&registro, sizeof(TipoAnalisis), 1, pFile);
    fclose(pFile);
    return escribio;
}

bool TipoAnalisisArchivo::guardar(TipoAnalisis registro, int posicion)
{
 FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(TipoAnalisis) * posicion, SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(TipoAnalisis), 1, pFile);
    fclose(pFile);
    return escribio;
}

