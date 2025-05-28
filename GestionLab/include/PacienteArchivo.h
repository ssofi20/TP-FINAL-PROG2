#pragma once
#include "Paciente.h"
#include <string>

class PacienteArchivo
{
    public:

        PacienteArchivo(std::string fileName="archivos/Pacientes.dat");
        int cantidadRegistros();
        int buscar(int DNI);
        bool guardar(Paciente paciente);
        bool guardar(Paciente paciente, int posicion);
        Paciente leer(int posicion);
        void leer(int cantidadRegistros, Paciente *vecPaciente);

    private:

        std::string _fileName;
};

