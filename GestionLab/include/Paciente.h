#pragma once
#include "Fecha.h"
#include <cstring>
            
class Paciente
{
    public:
        
        //CONSTRUCTORES
        Paciente();
        Paciente(int DNI, const char *nombre, const char *apellido, const char *telefono, const char *email, const char *obraSocial, const char *numeroAfiliado, Fecha dateB);
        
        //SETTERS
        void setDNI(int dni);
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setTelefono(const char *telefono);
        void setEmail(const char *email);
        void setObraSocial(const char *obraSocial);
        void setNumeroAfiliado(const char *numeroAfiliado);
        void setDateB(Fecha dateB);
        void setEstado(bool estado);
        
        //GETTES
        int getDNI() const;
        const char * getNombre() const;
        const char * getApellido() const;
        const char * getTelefono() const;
        const char * getEmail() const;
        const char * getObraSocial() const;
        const char * getNumeroAfiliado() const;
        Fecha getDateB() const;
        bool getEstado()const;
        
    private:
        int _DNI;
        char _nombre[30];
        char _apellido[40];
        char _telefono[11];
        char _email[60];
        char _obraSocial[50];
        char _numeroAfiliado[11];
        Fecha _dateB;
        bool _estado;
};

