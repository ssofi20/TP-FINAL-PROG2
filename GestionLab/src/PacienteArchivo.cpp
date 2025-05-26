#include "PacienteArchivo.h"

PacienteArchivo::PacienteArchivo(std::string fileName)
{
    _fileName = fileName;
}

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

void PacienteArchivo::leer(int cantidadRegistros, Paciente *vecPaciente){
}

int PacienteArchivo::buscar(int DNI){
}
bool PacienteArchivo::guardar(Paciente paciente){
}
bool PacienteArchivo::guardar(Paciente paciente, int posicion){
}
