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

int EstudioArchivo::buscar(int IDEstudio)
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
        if (estudio.getIDEstudio() == IDEstudio)
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

bool EstudioArchivo::copiaSeguridad()
{
    Estudio estudio;
    
    FILE *pFileBkp = fopen("archivosBKP/Estudios.bkp", "wb");

    if(pFileBkp == nullptr){return false;}
    
    int cant = cantidadRegistros();
    
    for(int i = 0; i < cant; i++)
    {
        estudio = leer(i);
        fwrite(&estudio, sizeof (Estudio), 1, pFileBkp);
    }
    
    fclose(pFileBkp);
    
    return true;
}

bool EstudioArchivo::restaurarCopia()
{
    Estudio estudio;
    
    EstudioArchivo archivoBKP("archivosBKP/Estudios.bkp");
    
    int cant = archivoBKP.cantidadRegistros();
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
    if(pFile == nullptr){return false;}
    
    for(int i = 0; i < cant; i++)
    {
        estudio = archivoBKP.leer(i);
        fwrite(&estudio, sizeof(Estudio), 1, pFile);
    }
    
    fclose(pFile);
    
    return true;
}

int EstudioArchivo::getID()
{
    return cantidadRegistros() + 1;
}
