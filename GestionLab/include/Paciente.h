#pragma once
#include "Fecha.h"
#include <cstring>
            
class Paciente
{
    public:
        
        Paciente();
        Paciente(int DNI, const char *nombre, const char *apellido, const char *telefono, const char *email, const char *obraSocial, const char *numeroAfiliado, Fecha dateB);
         
    private:
        int _DNI;
        char _nombre[30];
        char _apellido[40];
        char _telefono[10];
        char _email[60];
        char _obraSocial[50];
        char _numeroAfiliado[11];
        Fecha _dateB;
        bool _estado;
};

