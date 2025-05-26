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
int PacienteArchivo::buscar(int DNI){
}
bool PacienteArchivo::guardar(Paciente paciente){
}
bool PacienteArchivo::guardar(Paciente paciente, int posicion){
}
Paciente PacienteArchivo::leer(int posicion){
}
void PacienteArchivo::leer(int cantidadRegistros, Paciente *vecPaciente){
}
