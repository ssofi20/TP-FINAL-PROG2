#include "EstudioArchivo.h"

EstudioArchivo::EstudioArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int EstudioArchivo::cantidadRegistros()
{
   FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Estudio);
    fclose(pFile);
    return cantidad;

}

Estudio EstudioArchivo::leer(int posicion)
{
    FILE *pFile = fopen (_nombreArchivo.c_str(),"rb");
    if (pFile == nullptr)
    {
        return Estudio();
    }
    Estudio estudio;
    fseek(pFile, sizeof (Estudio) * posicion, SEEK_SET);
    fread(&estudio, sizeof(Estudio), 1, pFile);
    fclose(pFile);
    return estudio;
}

void EstudioArchivo::leer(int cantidadRegistros, Estudio *vec)
{
    FILE *pFile = fopen (_nombreArchivo.c_str(),"rb");
    if (pFile == nullptr)
    {
        return ;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        vec[i] = leer(i);
    }
    fclose(pFile);
}

int EstudioArchivo::buscar(const char* IDEstudio)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return -1;
    }
    Estudio estudio;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        estudio = leer(i);
        if (strcmp(estudio.getIDEstudio(), IDEstudio) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool EstudioArchivo::guardar(Estudio registro)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr)
    {
        return -1;
    }
    bool escribio = fwrite(&registro, sizeof(Estudio), 1, pFile);
    fclose(pFile);
    return escribio;
}

bool EstudioArchivo::guardar(Estudio registro, int posicion)
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Estudio) * posicion, SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(Estudio), 1, pFile);
    fclose(pFile);
    return escribio;
}

