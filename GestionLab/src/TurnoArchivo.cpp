#include "TurnoArchivo.h"

TurnoArchivo::TurnoArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}
 
int TurnoArchivo::cantidadRegistros(){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Turno);
    fclose(pFile);
    return cantidad;
    
}

Turno TurnoArchivo::leer(int posicion){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return Turno();
    }
    
    Turno registro;
    fseek(pFile, sizeof(Turno) * posicion, SEEK_SET);
    fread(&registro, sizeof(Turno), 1, pFile);
    fclose(pFile);
    return registro;
    
}

int TurnoArchivo::buscar(int IDTurno){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    
    Turno registro;
    int cant = cantidadRegistros();
    
    for(int i = 0; i < cant; i++){
        
        registro = leer(i);
        if(registro.getIDTurno() == IDTurno){
            return i;
        }
    }
    return -2;
}

bool TurnoArchivo::guardar(Turno registro){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }
    
    bool escribio = fwrite(&registro, sizeof(Turno), 1, pFile);
    fclose(pFile);
    return escribio;
    
}

bool TurnoArchivo::guardar(Turno registro, int posicion){
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    
    fseek(pFile, sizeof(Turno) * posicion, SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(Turno), 1, pFile);
    fclose(pFile);
    return escribio;
}

bool TurnoArchivo::copiaSeguridad()
{
    Turno turno;
    
    FILE *pFileBkp = fopen("archivosBKP/Turnos.bkp", "wb");

    if(pFileBkp == nullptr){return false;}
    
    int cant = cantidadRegistros();
    
    for(int i = 0; i < cant; i++)
    {
        turno = leer(i);
        fwrite(&turno, sizeof (Turno), 1, pFileBkp);
    }
    
    fclose(pFileBkp);
    
    return true;
}

bool TurnoArchivo::restaurarCopia()
{
    Turno turno;
    
    TurnoArchivo archivoBKP("archivosBKP/Turnos.bkp");
    
    int cant = archivoBKP.cantidadRegistros();
    
    FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
    if(pFile == nullptr){return false;}
    
    for(int i = 0; i < cant; i++)
    {
        turno = archivoBKP.leer(i);
        fwrite(&turno, sizeof(Turno), 1, pFile);
    }
    
    fclose(pFile);
    
    return true;
}
