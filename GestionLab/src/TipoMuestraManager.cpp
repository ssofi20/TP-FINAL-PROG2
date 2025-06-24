#include "TipoMuestraManager.h"
#include <iostream>

using namespace std;

int consolaAncho = 100;

///Dar de alta un tipo de muestra
void TipoMuestraManager::opcion1()
{
    TipoMuestra registro;

    int IDTipo;
    char nombre[35];

    bool invalido = true;
    int startLineAux = 87; /// Valor de startLine

    while(invalido)
    {
        rlutil::cls();
        string titulo = "ALTA DE TIPO DE MUESTRA";
        string linea =  "---------------------------------";

        int startLine = (consolaAncho - titulo.length() + 10);

        rlutil::locate( startLine /2, 8);
        cout << titulo << endl;
        rlutil::locate((startLine - 10) / 2,9);
        cout << linea << endl;

        rlutil::locate((startLine - 10) / 2, 11);
        cout << "Ingrese el ID: ";
        rlutil::locate((startLine + 19) / 2, 11);
        cin >> IDTipo;

        int pos = _archivo.buscar(IDTipo);
        if (pos <= 0)
        {
            rlutil::cls();
            rlutil::locate((startLine - 20) / 2, 11);
            cout << "Ya existe un tipo de muestra con este ID. Intente nuevamente." << endl;
            cout << endl;
            rlutil::locate((startLine - 20) / 2, 15);
            system("pause");
        }
        else
        {
            invalido = false;
        }
    }

    rlutil::locate((startLineAux - 10) / 2, 12);
    cout << "Ingrese el nombre del tipo de muestra: " << endl;
    rlutil::locate((startLineAux + 30) / 2, 12);
    cin >> nombre;
    cargarCadena(nombre, 34);
    registro.setIDMuestra(IDTipo);
    registro.setNombre(nombre);
    registro.setEstado(true);
    cout << endl;
    rlutil::locate((startLineAux - 20) / 2, 15);
    system("pause");


    if(_archivo.guardar(registro))
    {
        rlutil::cls();
        rlutil::locate((startLineAux - 20) / 2, 11);
        cout << "Se ha guardado con exito!" << endl;
        cout << endl;
        rlutil::locate((startLineAux - 20) / 2, 15);
        system("pause");
    }
    else
    {
        rlutil::cls();
        rlutil::locate((startLineAux - 20) / 2, 11);
        cout << "No se ha podido guardar :(" << endl;
        cout << endl;
        rlutil::locate((startLineAux - 20) / 2, 15);
        system("pause");
    }
}

///Dar de baja un tipo de muestra
void TipoMuestraManager::opcion2()
{
    rlutil::cls();
    string titulo = "DAR DE BAJA DE TIPO DE MUESTRA";
    string linea =  "----------------------------------------";

    int startLine = (consolaAncho - titulo.length() + 10);

    rlutil::locate(startLine /2, 8);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2,9);
    cout << linea << endl;

    int IDTipo;

    rlutil::locate((startLine - 20) / 2, 11);
    cout << "Ingrese el ID de tipo de muestra que desea dar de baja: ";
    rlutil::locate((startLine + 92) / 2, 11);
    cin >> IDTipo;

    int cant = _archivo.cantidadRegistros();

    bool encontrado = false;
    int posicion;
    TipoMuestra registro;

    for(int i = 0; i < cant; i++)
    {
        registro = _archivo.leer(i);
        if(registro.getIDMuestra() == IDTipo)
        {
            encontrado = true;
            posicion = i;
            break;
        }
    }

    if(!encontrado)
    {
        rlutil::cls();
        rlutil::locate((startLine - 20) / 2,11);
        cout << "El ID ingresado no existe en el archivo" << endl;
        cout << endl;
        rlutil::locate((startLine - 20) / 2, 15);
        system("pause");
        return;
    }

    registro = _archivo.leer(posicion);
    registro.setEstado(false);
    _archivo.guardar(registro, posicion);

}

///Modificar un tipo de muestra
void TipoMuestraManager::opcion3()
{
    rlutil::cls();
    string titulo = "MODIFICAR UN TIPO DE MUESTRA";
    string linea =  "--------------------------------------";

    int startLine = (consolaAncho - titulo.length() + 10);

    rlutil::locate( startLine /2, 8);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 9);
    cout << linea << endl;


    int IDTipo;
    rlutil::locate((startLine - 25) / 2,11);
    cout << "Ingrese el ID de tipo de muestra que desea modificar: ";
    rlutil::locate((startLine + 83) / 2,11);
    cin >> IDTipo;

    int cant = _archivo.cantidadRegistros();

    bool encontrado = false;
    int posicion;
    TipoMuestra registro;

    for(int i = 0; i < cant; i++)
    {
        registro = _archivo.leer(i);
        if(registro.getIDMuestra() == IDTipo && registro.getEstado())
        {
            encontrado = true;
            posicion = i;
            break;
        }
    }

    if(!encontrado)
    {
        rlutil::cls();
        rlutil::locate((startLine - 20) / 2, 11);
        cout << "El ID ingresado no existe en el archivo" << endl;
        cout << endl;
        rlutil::locate((startLine - 20) / 2, 15);
        system("pause");
        return;
    }

    char newNombre[35];
    rlutil::locate((startLine - 25) / 2, 12);
    cout << "Ingrese el nuevo nombre " << endl;
    rlutil::locate((startLine + 40) / 2, 12);
    cargarCadena(newNombre, 34);
    registro.setNombre(newNombre);
    cout << endl;
    rlutil::locate((startLine - 20) / 2, 15);
    system("pause");

    if(_archivo.guardar(registro, posicion))
    {
        rlutil::cls();
        rlutil::locate((startLine - 20) / 2, 11);
        cout << "El registro fue modificado exitosamente!" << endl;
        cout << endl;
        rlutil::locate((startLine - 20) / 2, 15);
        system("pause");
        return;
    }
    else
    {
        rlutil::cls();
        rlutil::locate((startLine - 20) / 2,11);
        cout << "El registro no pudo ser modificado" << endl;
        cout << endl;
        rlutil::locate((startLine - 20) / 2, 15);
        system("pause");
        return;
    }
}

///Listar todos los tipos de muestras
void TipoMuestraManager::opcion4()
{
    rlutil::cls();
    string titulo = "LISTADO DE LOS TIPO DE MUESTRA";
    string linea =  "----------------------------------------";

    int startLine = (consolaAncho - titulo.length() + 10);

    rlutil::locate( startLine /2, 4);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 5);
    cout << linea << endl;

    int cantidad = _archivo.cantidadRegistros();
    TipoMuestra registro;

    int y = 0;
    for(int i = 0; i < cantidad; i++)
    {
        registro = _archivo.leer(i);

        if(registro.getEstado())
        {

        int x = (y*4) + 7;

        rlutil::locate(( startLine + 10) / 2, x);
        cout << "ID Tipo Muestra: " << registro.getIDMuestra() << endl;
        rlutil::locate((startLine + 10) / 2, (x + 1));
        cout << "Nombre: " << registro.getNombre() << endl;

        rlutil::locate((startLine - 10) / 2, (x + 3));
        cout << linea << endl;
        y++;
        }
    }
    cout << endl;
    rlutil::locate((startLine - 10) / 2, (y*4 + 15));
    system("pause");
}
