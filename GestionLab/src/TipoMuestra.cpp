#include "TipoMuestra.h"

TipoMuestra::TipoMuestra(){
   
   _IDMuestra = 0;
   strcpy(_nombre, "SIN NOMBRE");
   _estado = true;
    
}

TipoMuestra::TipoMuestra(int IDMuestra, const char *nombre){
   
   setIDMuestra(IDMuestra);
   setNombre(nombre);
   setEstado(true);
    
}

//SETTERS
void TipoMuestra::setIDMuestra(int IDMuestra){
    _IDMuestra = IDMuestra;
}
void TipoMuestra::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}
void TipoMuestra::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int TipoMuestra::getIDMuestra() const{
    return _IDMuestra;
}
const char * TipoMuestra::getNombre() const{
    return _nombre;
}
bool TipoMuestra::getEstado() const{
    return _estado;
}
