#pragma once
#include "Fecha.h"
            
class Paciente
{
    public:
        
        Paciente();
         
    private:
        int _DNI;
        char _nombre[30];
        char _apellido[40];
        char _telefono[10];
        char _email[60];
        char _obraSocial[50];
        char _numeroAfiliado[11];
        Fecha _dateb;
        bool _estado;
};

