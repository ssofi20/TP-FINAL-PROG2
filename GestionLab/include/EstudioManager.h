#pragma once
#include "EstudioArchivo.h"
#include "Estudio.h"

class EstudioManager
{
private:
    EstudioArchivo _archivo;

public:

    ///Registrar nuevo estudio
    void opcion1();
    ///Eliminar estudios
    void opcion2();

    /// Sofi
    void opcion3();
    void opcion4();
    void opcion5();

};

