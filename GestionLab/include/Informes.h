#pragma once
#include "PacienteArchivo.h"
#include "EstudioArchivo.h"
#include "Paciente.h"

class Informes
{
    private:
        PacienteArchivo _arcPaci;
        EstudioArchivo _arcEst;

    public:

        void  informe1();
        ///Mostrar el paciente con más cantidad de estudios realizados.

        void opcion2();
        ///Recaudación por tipo de estudio.

        void opcion3();
        ///Recaudación anual por mes.


        /// Sofi
        void opcion4();
        void opcion5();

};

