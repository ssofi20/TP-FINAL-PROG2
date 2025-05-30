#pragma once
#include <string>
#include "Hora.h"
#include "Fecha.h"

class Turno
{
    private:
    int _IDTurno;
    int _DNIPaciente;
    Fecha _fechaProgramada;
    Hora _horaProgramada;
    int _estadoTurno;


    public:
        /// Constructores

        Turno();

        Turno (int IDTurno, int DNIPaciente, Fecha fechaProgramada, Hora horaProgramada, int estadoTurno);

        /// Setters

        void setIDTurno (int idTurno);
        void setDNIPaciente(int DNIPaciente);
        void setFechaProgramada(Fecha fechaProgramada);
        void setHoraProgramada (Hora horaProgramada);
        void setEstadoTurno (int estadoTurno);

        /// Getters

        int getIDTurno();
        int getDNIPaciente();
        Fecha getFechaProgramada();
        Hora getHoraProgramada();
        int getEstadoTurno();
        
        ///Metodos de la clase
        void cargar();
        std::string toString();
};

