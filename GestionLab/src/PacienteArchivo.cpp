#include "PacienteArchivo.h"

PacienteArchivo::PacienteArchivo(std::string fileName)
{
    _fileName = fileName;
}

//DEVUELVE LA CANTIDAD DE REGISTROS EN EL ARCHIVO
int PacienteArchivo::cantidadRegistros(){
    
    FILE *pFile = fopen(_fileName.c_str(), "rb");
    if(pFile == nullptr){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Paciente);
    fclose(pFile);
    return cantidad;
}

//LEE UN REGISTRO EN LA POSICION DADA Y DEVUELVE UN OBJETO CARGADO
Paciente PacienteArchivo::leer(int posicion){
    
    FILE *pFile = fopen(_fileName.c_str(), "rb");
    if(pFile == nullptr){
        return Paciente();
    }
    Paciente paciente;
    fseek(pFile, sizeof(Paciente) * posicion, SEEK_SET);
    fread(&paciente, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return paciente;
}

//LEE TODO EL ARCHIVO Y VA GUARDANDO LOS REGISTROS EN EL VECTOR DADO
void PacienteArchivo::leer(int cantidadRegistros, Paciente *vecPaciente){
    
    FILE *pFile = fopen(_fileName.c_str(), "rb");
    if(pFile == nullptr){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        vecPaciente[i] = leer(i);
    }
}

//BUSCA QUE REGISTRO COINCIDE CON ESE CAMPO Y DEVUELVE SU POSICION
int PacienteArchivo::buscar(int DNI){
    
    FILE *pFile = fopen(_fileName.c_str(), "rb");
    if(pFile == nullptr){
        return -2;
    }
    Paciente paciente;
    int cant = cantidadRegistros();
    for(int i = 0; i < cant; i++){
        paciente = leer(i);
        if(paciente.getDNI() == DNI){
            return i;
        }
    }
    return -1;
    
}

//GUARDA AL FINAL DE ARCHIVO UN REGISTRO
bool PacienteArchivo::guardar(Paciente paciente){
    
    FILE *pFile = fopen(_fileName.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }
    bool escribio = fwrite(&paciente, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return escribio;
    
}

//GUARDA UN REGISTRO EN LA POSCION DADA
bool PacienteArchivo::guardar(Paciente paciente, int posicion){
    
    FILE *pFile = fopen(_fileName.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, sizeof(Paciente) * posicion, SEEK_SET);
    bool escribio = fwrite(&paciente, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return escribio;
}
