#include "EstudioAnalisis.h"
#include <iostream>

using namespace std;

EstudioAnalisis::EstudioAnalisis()
{

    strcpy(_IDEstudio, "0");
    _IDAnalisis = 0;
    _estado = true;

}
EstudioAnalisis::EstudioAnalisis(const char *IDEstudio, int IDAnalisis)
{
    setIDEstudio(IDEstudio);
    setIDAnalisis(IDAnalisis);
    setEstado(true);
}

//SETTERS
void EstudioAnalisis::setIDEstudio(const char *IDEstudio)
{
    strcpy(_IDEstudio, IDEstudio);
}
void EstudioAnalisis::setIDAnalisis(int IDAnalisis)
{
    _IDAnalisis = IDAnalisis;
}
void EstudioAnalisis::setEstado(bool estado)
{
    _estado = estado;
}

//GETTERS
const char * EstudioAnalisis::getIDEstudio()
{
    return _IDEstudio;
}
int EstudioAnalisis::getIDAnalisis()
{
    return _IDAnalisis;
}
bool EstudioAnalisis::getEstado()
{
    return _estado;
}

//Metodos de la clase

void EstudioAnalisis::cargar()
{
    cout << "ID Estudio: ";
    cin >> _IDEstudio;
    cout << "ID Analisis: ";
    cin >> _IDAnalisis;
    _estado = true;
}

void EstudioAnalisis::mostrar(int y)
{
    TipoAnalisisArchivo obj;
    TipoAnalisis registro;
    
    int xCampo = 30; 
    int xIngreso = 55; 

    int cant = obj.cantidadRegistros();
    for (int i=0; i < cant; i++)
    {
        registro = obj.leer(i);
        if (registro.getIDAnalisis()==_IDAnalisis)
        {
            rlutil::locate(xCampo, y);
            cout << "ID Analisis: ";
            rlutil::locate(xIngreso, y++);
            cout << _IDAnalisis;
            
            rlutil::locate(xCampo, ++y);
            cout << "Nombre: "; 
            rlutil::locate(xIngreso, y++);
            cout << registro.getNombre();

        }
    }

}
