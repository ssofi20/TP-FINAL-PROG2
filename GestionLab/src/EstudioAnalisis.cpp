#include "EstudioAnalisis.h"

EstudioAnalisis::EstudioAnalisis(){
    
    strcpy(_IDEstudio, "0");
    _IDAnalisis = 0;
    _estado = true;
    
}
EstudioAnalisis::EstudioAnalisis(const char *IDEstudio, int IDAnalisis){
    setIDEstudio(IDEstudio);
    setIDAnalisis(IDAnalisis);
    setEstado(true);
}
        
//SETTERS
void EstudioAnalisis::setIDEstudio(const char *IDEstudio){
    strcpy(_IDEstudio, IDEstudio);
}
void EstudioAnalisis::setIDAnalisis(int IDAnalisis){
    _IDAnalisis = IDAnalisis;
}
void EstudioAnalisis::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
const char * EstudioAnalisis::getIDEstudio(){
    return _IDEstudio;
}
int EstudioAnalisis::getIDAnalisis(){
    return _IDAnalisis;
}
bool EstudioAnalisis::getEstado(){
    return _estado;
}
