#include "EstudioAnalisis.h"
#include <iostream>

using namespace std;

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

//Metodos de la clase

void EstudioAnalisis::cargar(){

    cout << "ID Estudio: ";
    cin >> _IDEstudio;
    cout << "ID Analisis: ";
    cin >> _IDAnalisis;
    _estado = true;

}

void EstudioAnalisis::mostrar(){


    TipoAnalisisArchivo obj;
    TipoAnalisis registro;

    int cant = obj.cantidadRegistros();
    for (int i=0; i < cant; i++)
    {
        registro = obj.leer(i);
        if (registro.getIDAnalisis()==_IDAnalisis)
        {

            cout << "ID Analisis: " << _IDAnalisis << endl;
            cout << "NOMBRE DEL ANALISIS: " << registro.getNombre() << endl;

        }
    }

}
