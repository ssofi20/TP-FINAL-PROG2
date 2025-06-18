#pragma once
#include "Turno.h"
#include "TurnoArchivo.h"
#include "PacienteArchivo.h"

class TurnoManager
{
    private:
        
        TurnoArchivo _archivo;

    public:

        ///Agregar turno al archivo
        void opcion1();
        ///Cambiar fecha y hora de un turno
        void opcion2();
        ///Modificar estado de un turno
        void opcion3();
        /// Buscar turnos del paciente
        void opcion4();
        /// Listar todos los turnos
        void opcion5();


};

