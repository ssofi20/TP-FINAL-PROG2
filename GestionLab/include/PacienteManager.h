#pragma once
#include "Paciente.h"
#include "PacienteArchivo.h"


class PacienteManager
{
    private:

        PacienteArchivo _archivo;

    public:
        //Funciones del menu
        void opcion4();
        void opcion5();
        void opcion6();

        //Funciones utiles
        void mostrar(Paciente registro);

};


