#pragma once
#include <string>

class Hora
{
    private:

        int _hora;
        int _minuto;

    public:
        /// CONSTRUCTORES
        Hora();
        Hora(int hora, int minuto);

        ///SETTERS

        void setHora(int hora);
        void setMinuto(int minuto);

        /// GETTERS

        int getHora();
        int getMinuto();

     /// Metodo de clase
        std::string toString();
        void cargar();

};

