#pragma once
#include "Paciente.h"
#include "PacienteArchivo.h"
#include "FuncionesGlobales.h"


class PacienteManager
{
    private:

    PacienteArchivo _archivo;

    public:
        ///Registrar nuevo paciente.
        void opcion1();
        ///Buscar un paciente por DNI
        void opcion2();
        ///Editar información de un paciente segun DNI
        void opcion3();

        void opcion4();
        void opcion5();
        void opcion6();
};


