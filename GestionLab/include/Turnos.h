#pragma once
#include "Hora.h"
#include "Fecha.h"

class Turnos
{
    private:
    int _IDTurno;
    Fecha _fechaProgramada;
    Hora _horaProgramada;
    int _estadoTurno;


    public:
        /// Constructores

        Turnos();
        Turnos (int IDTurno, Fecha fechaProgramada, Hora horaProgramada, int estadoTurno);

        /// Setters

        void setIDTurno (int idTurno);
        void setFechaProgramada(Fecha fechaProgramada);
        void setHoraProgramada (Hora horaProgramada);
        void setEstadoTurno (int estadoTurno);

        /// Getters

        int getIDTurno ();
        Fecha getFechaProgramada();
        Hora getHoraProgramada();
        int getEstadoTurno();



};

