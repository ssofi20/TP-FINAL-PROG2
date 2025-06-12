#include "EstudioAnalisisArchivo.h"

EstudioAnalisisArchivo::EstudioAnalisisArchivo(std::string nombreArchivo){

    _nombreArchivo = nombreArchivo;

}

int EstudioAnalisisArchivo::cantidadRegistros(){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(EstudioAnalisis);
    fclose(pFile);
    return cantidad;

}

EstudioAnalisis EstudioAnalisisArchivo::leer(int posicion){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return EstudioAnalisis();
    }
    EstudioAnalisis estudioAnalisis;
    fseek(pFile, sizeof(EstudioAnalisis) * posicion, SEEK_SET);
    fread(&estudioAnalisis, sizeof(EstudioAnalisis), 1, pFile);
    fclose(pFile);
    return estudioAnalisis;
}

bool EstudioAnalisisArchivo::guardar(EstudioAnalisis registro){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&registro, sizeof(EstudioAnalisis), 1, pFile);
    fclose(pFile);
    return escribio;

}

bool EstudioAnalisisArchivo::guardar(EstudioAnalisis registro, int posicion){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(EstudioAnalisis) * posicion, SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(EstudioAnalisis), 1, pFile);
    fclose(pFile);
    return escribio;

}
