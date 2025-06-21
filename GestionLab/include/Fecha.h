#pragma once
#include <string>

class Fecha
{
    public:

        //CONSTRUCTORES
        Fecha();
        Fecha(int dia, int mes, int anio);

        //GETTERS
        int getDia();
        int getMes();
        int getAnio();

        //SETTERS
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void setFechaActual();

        //METODOS DE LA CLASE
        std::string toString();
        void cargar(int x, int y);


    private:

        int _dia;
        int _mes;
        int _anio;

        bool esBisiesto();
};

