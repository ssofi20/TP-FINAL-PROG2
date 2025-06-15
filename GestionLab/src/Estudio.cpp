#include "Estudio.h"
#include <iostream>

using namespace std;

/// Constructores

Estudio::Estudio()
{
    strcpy(_IDEstudio, "SIN ID");
    _DNI = 0;
    _estadoEstudio = 0;
    strcpy(_sala, "SIN SALA");
    _IDTurno = 0;
    _precio = 0;
    _estado = true;
}

Estudio::Estudio(const char *IDEstudio, int dni, int estEstudio, const char *sala, int IDTurno, float precio)
{
    setIDEstudio(IDEstudio);
    setDNI(dni);
    setEstadoEstudio(estEstudio);
    setSala(sala);
    setIDTurno(IDTurno);
    setEstado(true);
}

/// Setters

void Estudio::setIDEstudio(const char *idEstudio)
{
    strcpy(_IDEstudio, idEstudio);
}

void Estudio::setDNI (int dni)
{
    _DNI = dni;
}

void Estudio::setEstadoEstudio(int estadoEstudio)
{
    _estadoEstudio = estadoEstudio;
}

void Estudio::setSala (const char *sala)
{
    strcpy(_sala, sala);
}

void Estudio::setIDTurno(int IDTurno)
{
    _IDTurno = IDTurno;
}

void Estudio::setPrecio(float precio)
{
    if(precio > 0)
    {
        _precio = precio;
    }
}

void Estudio::setEstado(bool estado)
{
    _estado = estado;
}

/// Getters

const char * Estudio::getIDEstudio()
{
    return _IDEstudio;
}

int Estudio::getDNI()
{
    return _DNI;
}

int Estudio::getEstadoEstudio()
{
    return _estadoEstudio;
}

const char * Estudio::getSala()
{
    return _sala;
}

int Estudio::getIDTurno()
{
    return _IDTurno;
}

float Estudio::getPrecio()
{
    return _precio;
}

bool Estudio::getEstado()
{
    return _estado;
}

//METODOS CARGAR Y MOSTRAR
void Estudio::cargar()
{
    char IDEstudio[11];
    char sala[6];
    int dni, IDTurno;
    float precio;

    cout << "ID del estudio: ";
    cargarCadena(IDEstudio, 10);
    setIDEstudio(IDEstudio);

    cout << "DNI: ";
    cin >> dni;
    setDNI(dni);

    cout << "Sala: ";
    cargarCadena(sala, 5);
    setSala(sala);

    cout << "ID turno: ";
    cin >> IDTurno;
    setIDTurno(IDTurno);
    
    cout << "Precio: ";
    cin >> precio;
    setPrecio(precio);

    _estado = true;
    _estadoEstudio = 1;

    /**
    ANALISIS DEL ESTUDIO
    - Pedir los ID de los analisis a realizar
    - Guardalos en el archivo EstudioAnalisis junto con el IDEstudio previamente cargado.
    - No se pueden repetir registros (IDAnalisis - IDEstudio)
    */

    int IDAnalisis = 1;
    EstudioAnalisisArchivo archivo;
    EstudioAnalisis registro;
    while(IDAnalisis != 0){

        cout << "ID Analisis a realizar: ";
        cin >> IDAnalisis;

        if(IDAnalisis < 700 && IDAnalisis > 100){
            registro.setIDAnalisis(IDAnalisis);
            registro.setIDEstudio(IDEstudio);
            registro.setEstado(true);
            if(archivo.guardar(registro)){
                cout << "El analisis se registro exitosamente!" << endl;
            }
            else {
                cout << "No se pudo registrar el analisis :(" << endl;
            }
        }
        cout << "Desea registrar otro analisis? 1-SI  0-NO" << endl;
        cin >> IDAnalisis;
    }
}

void Estudio::mostrar()
{
    cout << "ID ESTUDIO: " << _IDEstudio << endl;
    cout << "DNI: " << _DNI << endl;
    cout << "SALA: " << _sala << endl;
    cout << "ID TURNO: " << _IDTurno << endl;
    cout << "PRECIO: $" << _precio << endl;
    cout << "ESTADO DEL ESTUDIO: ";
    switch(_estadoEstudio){
    case 1:
        cout << "En proceso" << endl;
        break;
    case 2:
        cout << "Esperando resultados" << endl;
        break;
    case 3:
        cout << "Resultados listos" << endl;
        break;
    case 4:
        cout << "Anulado" << endl;
        break;
    }

    EstudioAnalisisArchivo archivo;

    int cantReg = archivo.cantidadRegistros();

    for (int i=0; i < cantReg; i++)
    {
        EstudioAnalisis registro;
        registro = archivo.leer(i);

        if (strcmp (registro.getIDEstudio(), _IDEstudio)==0)
        {
            registro.mostrar();
        }
    }
}

