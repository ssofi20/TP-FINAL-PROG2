#include "TipoAnalisisManager.h"
#include <iostream>

using namespace std;

///Dar de alta un tipo de análisis
void TipoAnalisisManager::opcion1()
{
    TipoAnalisis registro;
    int IDAnalisis;
    int IDMuestra;
    char nombre[60];
    bool aux = true;

    while (aux)
    {
        cout << "Ingrese el ID del tipo de muestra: " << endl;
        cin >> IDMuestra;
        if (0<IDMuestra && IDMuestra <6)
        {
            aux = false;
        }
        else
        {
            cout << "El ID ingresado no es valido." << endl;
        }
    }

    registro.setIDMuestra(IDMuestra);

    switch (IDMuestra)
    {
    case 1:
    {
        cout << "Ingrese el ID del analisis: " << endl;
        cin >> IDAnalisis;
        if (200<IDAnalisis  && IDAnalisis <100)
        {
            return;
        }
        else
        {

            cout << "El ID ingresado no concuerda con el tipo de muestra anteriormente indicado." << endl;
            system("pause");
            return;
        }
    }
    break;

    case 2:
    {
        cout << "Ingrese el ID del analisis: " << endl;
        cin >> IDAnalisis;
        if (300<IDAnalisis  && IDAnalisis <200)
        {
            return;
        }
        else
        {

            cout << "El ID ingresado no concuerda con el tipo de muestra anteriormente indicado." << endl;
            system("pause");

            return;
        }
    }
    break;

    case 3:
    {
        cout << "Ingrese el ID del analisis: " << endl;
        cin >> IDAnalisis;
        if (400<IDAnalisis  && IDAnalisis <300)
        {
            return;
        }
        else
        {

            cout << "El ID ingresado no concuerda con el tipo de muestra anteriormente indicado." << endl;
            system("pause");

            return;
        }
    }
    break;

    case 4:
    {
        cout << "Ingrese el ID del analisis: " << endl;
        cin >> IDAnalisis;
        if (500<IDAnalisis  && IDAnalisis <400)
        {
            return;
        }
        else
        {

            cout << "El ID ingresado no concuerda con el tipo de muestra anteriormente indicado." << endl;
            system("pause");

            return;
        }
    }
    break;

    case 5:
    {
        cout << "Ingrese el ID del analisis: " << endl;
        cin >> IDAnalisis;
        if (600<IDAnalisis  && IDAnalisis <500)
        {
            return;
        }
        else
        {

            cout << "El ID ingresado no concuerda con el tipo de muestra anteriormente indicado." << endl;
            system("pause");

            return;
        }
    }
    break;
    }

    registro.setIDAnalisis(IDAnalisis);

    cout << "Ingrese el nombre del analisis: " << endl;
    cargarCadena(nombre, 59);

    registro.setNombre(nombre);

    bool estado = true;
    registro.setEstado(estado);

    if (_archivo.guardar(registro))
    {
        cout << "El nuevo analisis se registro de forma existosa." << endl;
    }
    else
    {
        cout << "El analisis no pudo ser registrado en archivo." << endl;
        system("pause");
        return;
    }

}

///Dar de baja un tipo de análisis
void TipoAnalisisManager::opcion2()
{

    TipoAnalisis registro;
    int IDAnalisis;
    cout << "Ingrese el ID del analisis a dar de baja: ";
    cin >> IDAnalisis;

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++)
    {
        registro = _archivo.leer(i);
        if (registro.getIDAnalisis() == IDAnalisis)
        {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado)
    {
        registro.setEstado(false);
        if(_archivo.guardar(registro, pos))
        {
            cout << "Analisis dado de baja exitosamente!" << endl;
        }
        else
        {
            cout << "Error al dar de baja el Analisis" << endl;
        }
        system("pause");
    }
    else
    {
        cout << "No se encontro un analisis con ese ID en el archivo" << endl;
        system("pause");
    }

}

///Modificar un tipo de análisis
void TipoAnalisisManager::opcion3()
{
    int idAnalisis;

    cout << "Ingrese el ID del analisis que desea modificar: "<< endl;
    cin >> idAnalisis;

    int pos = _archivo.buscar(idAnalisis);

     if(pos < 0)
    {
        cout << "No se encontro un analisis con ese ID en el archivo" << endl;
        system("pause");
        return;
    }

    TipoAnalisis registro = _archivo.leer(pos);

    int opcion;
    cout << "1- Modificar nombre" << endl;
    cout << "0- Cancelar y volver al menu anterior" << endl;
    cout << "Seleccion: ";
    cin >> opcion;


    char nombre [60];
    if (opcion == 1)
    {
        cout << "Ingresar el nuevo nombre del analisis: " << endl;
        cargarCadena(nombre, 59);
    }else {
        return;
    }

    registro.setNombre(nombre);

    if (_archivo.guardar(registro))
    {
        cout << "El nuevo nombre se guardo exitosamente. " << endl;
        return;
    }else {
    cout << "No se pudo modificar el nombre del analisis en archivo. " << endl;
    system("pause");
    return;
    }
}

/// Listar todos los tipos de análisis
void TipoAnalisisManager::opcion4()
{
     int cantidad = _archivo.cantidadRegistros();
    cout << "Listado de analisis" << endl << endl;

    for (int i = 0; i < cantidad; i++)
    {
        TipoAnalisis registro = _archivo.leer(i);
        if(registro.getEstado())
        {
            cout << "-------------------------" << endl;
            cout << "ID del analisis: "<< registro.getIDAnalisis() << endl;
            cout << "ID del tipo de muestra: " << registro.getIDMuestra() << endl;
            cout << "Nombre del analisis: " << registro.getNombre() << endl;
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");

}
