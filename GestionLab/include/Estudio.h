#pragma once
#include "Turno.h"
#include <cstring>



class Estudio
{
    private:

        char _IDEstudio [11];
        int _DNI;
        int _estadoEstudio;
        char _sala[6];
        Turno _turno;
        bool _estado;

    public:
        /// Constructores

        Estudio();
        Estudio(const char *IDEstudio, int dni, int estEstudio, const char *sala, Turno turno);

        /// Setters

        void setIDEstudio (const char *idEstudio);
        void setDNI (int dni);
        void setEstadoEstudio(int estadoEstudio);
        void setSala (const char *sala);
        void setTurno(Turno turno);
        void setEstado(bool estado);

        /// Getters

        const char *getIDEstudio();
        int getDNI();
        int getEstadoEstudio();
        const char *getSala();
        Turno getTurno();
        bool getEstado();

};

