#include "Estudio.h"
#include <iostream>

using namespace std;

/// Constructores

Estudio::Estudio()
{
    _IDEstudio = 0;
    _DNI = 0;
    _estadoEstudio = 0;
    strcpy(_sala, "SIN SALA");
    _IDTurno = 0;
    _precio = 0;
    _estado = true;
}

Estudio::Estudio(int IDEstudio, int dni, int estEstudio, const char *sala, int IDTurno, float precio)
{
    setIDEstudio(IDEstudio);
    setDNI(dni);
    setEstadoEstudio(estEstudio);
    setSala(sala);
    setIDTurno(IDTurno);
    setEstado(true);
}

/// Setters

void Estudio::setIDEstudio (int idEstudio)
{
    _IDEstudio = idEstudio;
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

int Estudio::getIDEstudio()
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

void Estudio::cargarAnalisis(int y)
{
    EstudioAnalisisArchivo archivo;
    TipoAnalisisArchivo archivoAnalisis;
    EstudioAnalisis registro;

    int IDAnalisis;
    string texto;
    bool isExist = true;

    int xCampo = 30;
    int xIngreso = 55;

    texto = "ANALISIS DE LA MUESTRA";
    rlutil::locate(xCampo, y);
    cout << texto;

    while (isExist) {
        texto = "ID Analisis a realizar:";
        rlutil::locate(xCampo, y + 2);
        cout << texto;
        rlutil::locate(xIngreso, y + 2);
        cin >> IDAnalisis;

        // Verificar si existe el tipo de an lisis
        int pos = archivoAnalisis.buscar(IDAnalisis);
        if (pos < 0) {
            texto = "El tipo de an lisis no existe en el sistema. Intente nuevamente.";
            rlutil::locate((100 - texto.length()) / 2, y + 4);
            cout << texto;
            rlutil::locate((100 - 33) / 2, y + 4);
            system("pause");
            return;
        }

        // Verificar si ya est  registrado para este estudio
        int cant = archivo.cantidadRegistros();
        for (int i = 0; i < cant; i++) {
            EstudioAnalisis reg = archivo.leer(i);
            if (reg.getIDAnalisis() == IDAnalisis && reg.getIDEstudio() == _IDEstudio) {
                texto = "Ese an lisis ya fue registrado para este estudio.";
                rlutil::locate((100 - texto.length()) / 2, y + 4);
                cout << texto;
                rlutil::locate((100 - 33) / 2, y + 4);
                system("pause");
                return;
            }
        }

        isExist = false;
    }

    registro.setIDAnalisis(IDAnalisis);
    registro.setIDEstudio(_IDEstudio);
    registro.setEstado(true);

    if (archivo.guardar(registro)) {
        texto = "­El an lisis se registr¢ exitosamente!";
    } else {
        texto = "No se pudo registrar el an lisis.";
    }
    rlutil::locate((100 - texto.length()) / 2, y + 4);
    cout << texto;
    rlutil::locate((100 - 33) / 2, y + 5);
    system("pause");
}

void Estudio::cargar()
{
    const int xCampo = 30;
    const int xIngreso = 55;
    int y = 6;
    string texto;

    // T¡tulo centrado
    texto = "FORMULARIO REGISTRO DE ESTUDIO";
    rlutil::locate((100 - texto.length()) / 2, y - 2);
    cout << texto;

    rlutil::locate(xCampo, y);
    cout << "ID Generado: ";
    rlutil::locate(xIngreso, y++);
    cout << _IDEstudio;

    rlutil::locate(xCampo, ++y);
    cout << "DNI Paciente: ";
    rlutil::locate(xIngreso, y++);
    cin >> _DNI;
    
    cin.ignore();
    rlutil::locate(xCampo, ++y);
    cout << "Sala: ";
    rlutil::locate(xIngreso, y++);
    cargarCadena(_sala, 5);

    rlutil::locate(xCampo, ++y);
    cout << "ID turno: ";
    rlutil::locate(xIngreso, y++);
    cin >> _IDTurno;

    rlutil::locate(xCampo, ++y);
    cout << "Precio: ";
    rlutil::locate(xIngreso, y++);
    cin >> _precio;

    _estado = true;
    _estadoEstudio = 1;

}

string Estudio::toStringEstado()
{
    switch(_estadoEstudio)
    {
    case 1:
        return "En proceso";
        break;
    case 2:
        return "Esperando resultados";
        break;
    case 3:
        return "Resultados listos";
        break;
    case 4:
        return "Anulado";
        break;
    }
}

void Estudio::mostrar()
{
    const int xCampo = 30;
    const int xIngreso = 55;
    int y = 6;
    
    rlutil::locate(xCampo, y);
    cout << "ID Estudio:";
    rlutil::locate(xIngreso, y++);
    cout << _IDEstudio;

    rlutil::locate(xCampo, ++y);
    cout << "DNI Paciente:";
    rlutil::locate(xIngreso, y++);
    cout << _DNI;
    
    rlutil::locate(xCampo, ++y);
    cout << "Sala:";
    rlutil::locate(xIngreso, y++);
    cout << _sala;
    
    rlutil::locate(xCampo, ++y);
    cout << "ID Turno:";
    rlutil::locate(xIngreso, y++);
    cout << _IDTurno;
    
    rlutil::locate(xCampo, ++y);
    cout << "Precio:";
    rlutil::locate(xIngreso, y++);
    cout << _precio;
    
    rlutil::locate(xCampo, ++y);
    cout << "Estado del estudio:";
    rlutil::locate(xIngreso, y++);
    cout << toStringEstado();
    
    int posActual = y+1;

    EstudioAnalisisArchivo archivo;

    int cantReg = archivo.cantidadRegistros();
    
    string texto = "ANALISIS DEL ESTUDIO";
    rlutil::locate(xCampo, posActual);
    cout << texto;

    for (int i=0; i < cantReg; i++)
    {
        EstudioAnalisis registro;
        registro = archivo.leer(i);

        if (registro.getIDEstudio() == _IDEstudio)
        {
            registro.mostrar(posActual+2);
        }
    }
}

int Estudio::mostrarHorizontal(int y)
{
    rlutil::locate(2, y);
    cout << _IDEstudio;

    rlutil::locate(14, y);
    cout << _DNI;

    rlutil::locate(28, y);
    cout << _sala;

    rlutil::locate(36, y);
    cout << _IDTurno;

    rlutil::locate(48, y);
    cout << _precio;

    rlutil::locate(60, y);
    cout << toStringEstado();
    
    //Nombres de los analisis
    EstudioAnalisisArchivo archivo;
    TipoAnalisisArchivo archivoAnalisis;
    TipoAnalisis tipoAnalisis;

    int cantReg = archivo.cantidadRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        EstudioAnalisis registro;
        registro = archivo.leer(i);

        if (registro.getIDEstudio() == _IDEstudio)
        {
            int pos = archivoAnalisis.buscar(registro.getIDAnalisis());
            tipoAnalisis = archivoAnalisis.leer(pos);
            
            rlutil::locate(75, y);
            cout << tipoAnalisis.getNombre();
            y++;
        }
    }
    
    return y;
}
