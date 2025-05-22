#include "Paciente.h"

Paciente::Paciente(){
    
    _DNI = 0;
    strcpy(_nombre, "SIN NOMBRE");
    strcpy(_apellido, "SIN APELLIDO");
    strcpy(_telefono, "0");
    strcpy(_email, "SIN EMAIL");
    strcpy(_obraSocial, "SIN OS");
    strcpy(_numeroAfiliado, "0");
    _dateB.setDia(0);
    _dateB.setMes(0);
    _dateB.setAnio(0);
    _estado = true;

}
Paciente::Paciente(int DNI, const char *nombre, const char *apellido, const char *telefono, const char *email, const char *obraSocial, const char *numeroAfiliado, Fecha dateB){
            

}
