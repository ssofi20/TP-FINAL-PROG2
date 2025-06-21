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
    
    const int xCampo = 30;
    const int xIngreso = 55;
    int y = 6;
    
    rlutil::cls();
    
    string titulo = "FORMULARIO DE INGRESO DE PACIENTE";
    rlutil::locate((100 - titulo.length()) / 2, y - 2);
    cout << titulo;

    rlutil::locate(xCampo, y);
    cout << "DNI: ";
    rlutil::locate(xIngreso, y++);
    cin >> _DNI;
    cin.ignore(); 

    rlutil::locate(xCampo, ++y);
    cout << "Nombre/s: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_nombre, 29);

    rlutil::locate(xCampo, ++y);
    cout << "Apellido/s: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_apellido, 39);

    rlutil::locate(xCampo, ++y);
    cout << "Telefono: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_telefono, 10);

    rlutil::locate(xCampo, ++y);
    cout << "Email: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_email, 59);

    rlutil::locate(xCampo, ++y);
    cout << "Nombre Obra Social: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_obraSocial, 59);

    rlutil::locate(xCampo, ++y);
    cout << "Numero Afiliado: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_numeroAfiliado, 19);

    rlutil::locate(xCampo, ++y);
    cout << "Fecha de Nacimiento: ";
    rlutil::locate(xIngreso, y++);
    _dateB.cargar();

    _estado = true;
    
}

void Paciente::mostrar(){
    
    const int xCampo = 30;
    const int xIngreso = 55;
    int y = 6;
    
    string titulo = "INFORMACION DEL PACIENTE";
    rlutil::locate((100 - titulo.length()) / 2, y - 2);
    cout << titulo;

    rlutil::locate(xCampo, y);
    cout << "DNI:";
    rlutil::locate(xIngreso, y++);
    cout << _DNI;

    rlutil::locate(xCampo, ++y);
    cout << "Nombre/s:";
    rlutil::locate(xIngreso, y++);
    cout << _nombre;

    rlutil::locate(xCampo, ++y);
    cout << "Apellido/s:";
    rlutil::locate(xIngreso, y++);
    cout << _apellido;

    rlutil::locate(xCampo, ++y);
    cout << "Telefono:";
    rlutil::locate(xIngreso, y++);
    cout << _telefono;

    rlutil::locate(xCampo, ++y);
    cout << "Email:";
    rlutil::locate(xIngreso, y++);
    cout << _email;

    rlutil::locate(xCampo, ++y);
    cout << "Obra Social:";
    rlutil::locate(xIngreso, y++);
    cout << _obraSocial;

    rlutil::locate(xCampo, ++y);
    cout << "Numero Afiliado:";
    rlutil::locate(xIngreso, y++);
    cout << _numeroAfiliado;

    rlutil::locate(xCampo, ++y);
    cout << "Fecha de Nacimiento:";
    rlutil::locate(xIngreso, y++);
    cout << _dateB.toString();

}

void Paciente::mostrarHorizontal(int y)
{
  
    rlutil::locate(2, y);
    cout << _DNI;

    rlutil::locate(12, y);
    cout << _apellido;

    rlutil::locate(28, y);
    cout << _nombre;

    rlutil::locate(42, y);
    cout << _telefono;

    rlutil::locate(56, y);
    cout << _numeroAfiliado;

    rlutil::locate(70, y);
    cout << _obraSocial;

    rlutil::locate(88, y);
    cout << _dateB.toString(); 
    
}
