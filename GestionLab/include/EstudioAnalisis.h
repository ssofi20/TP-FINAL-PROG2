#pragma once
#include <cstring>
#include "TipoAnalisis.h"
#include "TipoAnalisisArchivo.h"
#include "rlutil.h"

class EstudioAnalisis
{
    public:

        EstudioAnalisis();
        EstudioAnalisis(int IDEstudio, int IDAnalisis);

        //SETTERS
        void setIDEstudio(int IDEstudio);
        void setIDAnalisis(int IDAnalisis);
        void setEstado(bool estado);

        //GETTERS
        int getIDEstudio();
        int getIDAnalisis();
        bool getEstado();

        //Metodos de la clase
        void cargar();
        void mostrar(int y);

    private:

        int _IDEstudio;
        int _IDAnalisis;
        bool _estado;
};

