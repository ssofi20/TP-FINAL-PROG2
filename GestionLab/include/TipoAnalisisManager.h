#pragma once
#include "TipoAnalisis.h"
#include "TipoAnalisisArchivo.h"
#include "FuncionesGlobales.h"


class TipoAnalisisManager
{
private:
    TipoAnalisisArchivo _archivo;

public:

    ///Dar de alta un tipo de análisis
    void opcion1();

    ///Dar de baja un tipo de análisis
    void opcion2();

    ///Modificar un tipo de análisis
    void opcion3();

    /// Listar todos los tipos de análisis
    void opcion4();

};
