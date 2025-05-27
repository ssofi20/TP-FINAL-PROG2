#include "Paciente.h"

//CONSTRUCTORES
Paciente::Paciente()
: _dateB(0,0,0)
{
    
    _DNI = 0;
    strcpy(_nombre, "SIN NOMBRE");
    strcpy(_apellido, "SIN APELLIDO");
    strcpy(_telefono, "0");
    strcpy(_email, "SIN EMAIL");
    strcpy(_obraSocial, "SIN OS");
    strcpy(_numeroAfiliado, "0");
    _estado = true;

}
Paciente::Paciente(int DNI, const char *nombre, const char *apellido, const char *telefono, const char *email, const char *obraSocial, const char *numeroAfiliado, Fecha dateB){
     
    setDNI(DNI);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setObraSocial(obraSocial);
    setNumeroAfiliado(numeroAfiliado);
    setDateB(dateB);
    setEstado(true);

}

//SETTERS
void Paciente::setDNI(int dni){
    _DNI = dni;
}
void Paciente::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}
void Paciente::setApellido(const char *apellido){
    strcpy(_apellido, apellido);
}
void Paciente::setTelefono(const char *telefono){
    strcpy(_telefono, telefono);
}
void Paciente::setEmail(const char *email){
    strcpy(_email, email);
}
void Paciente::setObraSocial(const char *obraSocial){
    strcpy(_obraSocial, obraSocial);
}
void Paciente::setNumeroAfiliado(const char *numeroAfiliado){
    strcpy(_numeroAfiliado, numeroAfiliado);
}
void Paciente::setDateB(Fecha dateB){
    _dateB = dateB;
}
void Paciente::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int Paciente::getDNI() const{
    return _DNI;
}
const char * Paciente::getNombre() const{
    return _nombre;
}
const char * Paciente::getApellido() const{
    return _apellido;
}
const char * Paciente::getTelefono() const{
    return _telefono;
}
const char * Paciente::getEmail() const{
    return _email;
}
const char * Paciente::getObraSocial() const{
    return _obraSocial;
}
const char * Paciente::getNumeroAfiliado() const{
    return _numeroAfiliado;
}
Fecha Paciente::getDateB() const{
    return _dateB;
}
bool Paciente::getEstado() const{
    return _estado;
}
