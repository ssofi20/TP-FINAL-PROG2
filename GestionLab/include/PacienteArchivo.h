#pragma once
#include "Paciente.h"
#include <string>

class PacienteArchivo
{
    public:
        
        PacienteArchivo(std::string fileName);
        int CantidadRegistros();
        int Buscar(int DNI);
        bool Guardar(Paciente paciente);
        bool Guardar(Paciente paciente, int posicion);
        Paciente Leer(int posicion);
        void Leer(int cantidadRegistros, Paciente *vecPaciente);
        
    private:
        
        std::string _fileName;
};

