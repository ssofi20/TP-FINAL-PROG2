#pragma once
#include "Turnos.h"
#include <cstring>



class Estudio
{
    private:

        char _IDEstudio [11];
        int _DNI;
        int _estadoEstudio;
        char _sala[6];
        Turnos _turno;
        bool _estado;

    public:
        /// Constructores

        Estudio();
        Estudio(const char *IDEstudio, int dni, int estEstudio, const char *sala, Turnos turno, bool estado);

        /// Setters

        void setIDEstudio (const char *idEstudio);
        void setDNI (int dni);
        void setEstadoEstudio(int estadoEstudio);
        void setSala (const char *sala);
        void setTurno(Turnos turno);
        void setEstado(bool estado);

        /// Getters

        const char *getIDEstudio();
        int getDNI();
        int getEstadoEstudio();
        const char *getSala();
        Turnos getTurno();
        bool getEstado();

};

