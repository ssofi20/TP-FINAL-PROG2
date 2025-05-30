#include "Paciente.h"
#include <iostream>

using namespace std;

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

void Paciente::cargar(){

    cout << "DNI: ";
    cin >> _DNI;
    cout << "Nombre/s: ";
    cargarCadena(_nombre, 29);
    cout << "Apellido/s: ";
    cargarCadena(_apellido, 39);
    cout << "Telefono: ";
    cargarCadena(_telefono, 10);
    cout << "Email: ";
    cargarCadena(_email, 59);
    cout << "Obra Social: ";
    cargarCadena(_obraSocial, 59);
    cout << "Numero Afiliado: ";
    cargarCadena(_numeroAfiliado, 19);
    cout << "Fecha de Nacimiento" << endl;
    _dateB.cargar();
    _estado = true;
    
}
void Paciente::mostrar(){
    
    cout << "DNI: " << _DNI << endl;
    cout << "Nombre/s: " << _nombre << endl;
    cout << "Apellido/s: " << _apellido << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Obra Social: " << _obraSocial << endl;
    cout << "Numero Afiliado: " << _numeroAfiliado << endl;
    cout << "Fecha de Nacimiento: " << _dateB.toString() << endl;

}
