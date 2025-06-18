#include "TipoAnalisisManager.h"
#include <iostream>

using namespace std;

///Dar de alta un tipo de analisis
void TipoAnalisisManager::opcion1()
{
    TipoAnalisis registro, objeto;
    
    int IDMuestra;
    int IDAnalisis;
    char nombre[60];
    
    cout << "Ingrese el ID del tipo de muestra: " << endl;
    cin >> IDMuestra;
    registro.setIDMuestra(IDMuestra);
    
    cout << "Ingrese el ID del analisis: " << endl;
    cin >> IDAnalisis;
    registro.setIDAnalisis(IDAnalisis);
    
    int cant = _archivo.cantidadRegistros();
    for(int i = 0; i < cant; i++)
    {
        objeto = _archivo.leer(i);
        if(objeto.getIDAnalisis() == IDAnalisis && objeto.getEstado())
        {
            cout << "Ese ID ya existe en el archivo!." << endl;
            system("pause");
            return;
        }
    }

    cout << "Ingrese el nombre del analisis: " << endl;
    cargarCadena(nombre, 59);
    registro.setNombre(nombre);

    registro.setEstado(true);

    if (_archivo.guardar(registro)) {
        cout << "El nuevo analisis se registro de forma existosa." << endl;
        system("pause");
    } else {
        cout << "El analisis no pudo ser registrado en archivo." << endl;
        system("pause");
    }
}

///Dar de baja un tipo de analisis
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

///Modificar un tipo de analisis
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

    if (_archivo.guardar(registro, pos))
    {
        cout << "El nuevo nombre se guardo exitosamente. " << endl;
        return;
    } 
    else {
        cout << "No se pudo modificar el nombre del analisis en archivo. " << endl;
        system("pause");
        return;
    }
}

/// Listar todos los tipos de analisis
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
