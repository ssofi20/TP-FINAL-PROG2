#pragma once
#include <cstring>
#include "Turno.h"
#include "FuncionesGlobales.h"
#include "EstudioAnalisis.h"
#include "EstudioAnalisisArchivo.h"
#include "TipoAnalisisArchivo.h"

class Estudio
{
    private:

        int _IDEstudio;
        int _DNI;
        int _estadoEstudio;
        char _sala[6];
        int _IDTurno;
        float _precio;
        bool _estado;

    public:

        /// Constructores

        Estudio();
        Estudio(int IDEstudio, int dni, int estEstudio, const char *sala, int IDTurno, float precio);

        /// Setters

        void setIDEstudio (int idEstudio);
        void setDNI (int dni);
        void setEstadoEstudio(int estadoEstudio);
        void setSala (const char *sala);
        void setIDTurno(int IDturno);
        void setPrecio(float precio);
        void setEstado(bool estado);

        /// Getters

        int getIDEstudio();
        int getDNI();
        int getEstadoEstudio();
        const char *getSala();
        int getIDTurno();
        float getPrecio();
        bool getEstado();

        ///METODOS CARGAR Y MOSTRAR
        void cargar();
        void cargarAnalisis(int y);
        string toStringEstado();
        void mostrar();
        int mostrarHorizontal(int y);

};

