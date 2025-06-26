#include "TipoAnalisisManager.h"
#include <iostream>

using namespace std;

int anchoConsola = 100;

///Dar de alta un tipo de analisis
void TipoAnalisisManager::opcion1()
{
    TipoAnalisis registro, objeto;

    int IDMuestra;
    int IDAnalisis;
    char nombre[60];

    rlutil::cls();
    string titulo = "ALTA DE TIPO DE ANALISIS";
    string linea =  "----------------------------------";

    int startLine = (anchoConsola - titulo.length() + 10);

    rlutil::locate( startLine /2, 8);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 9);
    cout << linea << endl;

    rlutil::locate((startLine - 10) / 2, 11);
    cout << "Ingrese el ID del tipo de muestra: " << endl;
    rlutil::locate((startLine + 60) / 2, 11);
    cin >> IDMuestra;
    registro.setIDMuestra(IDMuestra);

    rlutil::locate((startLine - 10) / 2, 12);
    cout << "Ingrese el ID del analisis: " << endl;
    rlutil::locate((startLine + 47) / 2, 12);
    cin >> IDAnalisis;
    registro.setIDAnalisis(IDAnalisis);

    int cant = _archivo.cantidadRegistros();
    for(int i = 0; i < cant; i++)
    {
        objeto = _archivo.leer(i);
        if(objeto.getIDAnalisis() == IDAnalisis && objeto.getEstado())
        {
            rlutil::cls();
            rlutil::locate((startLine - 10) / 2, 11);
            cout << "Ese ID ya existe en el archivo!." << endl;
            cout << endl;
            rlutil::locate((startLine - 10) / 2, 15);
            system("pause");
            return;
        }
    }

    rlutil::locate((startLine - 10) / 2, 13);
    cout << "Ingrese el nombre del analisis: " << endl;
    rlutil::locate((startLine + 55) / 2, 13);
    cin.ignore();
    cargarCadena(nombre, 59);
    registro.setNombre(nombre);
    cout << endl;
    rlutil::locate((startLine - 10) / 2, 17);
    system("pause");

    registro.setEstado(true);

    if (_archivo.guardar(registro))
    {

        rlutil::cls();
        rlutil::locate((startLine - 10) / 2, 11);
        cout << "El nuevo analisis se registro de forma existosa." << endl;
        cout << endl;
        rlutil::locate((startLine - 10) / 2, 15);
        system("pause");

    }
    else
    {

        rlutil::cls();
        rlutil::locate((startLine - 10) / 2, 11);
        cout << "El analisis no pudo ser registrado en archivo." << endl;
        cout << endl;
        rlutil::locate((startLine - 10) / 2, 15);
        system("pause");
    }
}

///Dar de baja un tipo de analisis
void TipoAnalisisManager::opcion2()
{

    TipoAnalisis registro;
    int IDAnalisis;

    rlutil::cls();
    string titulo = "DAR DE BAJA DE TIPO DE ANALISIS";
    string linea =  "-----------------------------------------";

    int startLine = (anchoConsola - titulo.length() + 10);

    rlutil::locate( startLine /2, 8);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 9);
    cout << linea << endl;

    rlutil::locate((startLine - 10) / 2, 11);
    cout << "Ingrese el ID del analisis a dar de baja: ";
    rlutil::locate((startLine + 74) / 2, 11);
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
            rlutil::cls();
            rlutil::locate((startLine - 10) / 2, 11);
            cout << "Analisis dado de baja exitosamente!" << endl;
            cout << endl;
            rlutil::locate((startLine - 10) / 2, 15);
            system("pause");
            return;
        }
        else
        {
            rlutil::cls();
            rlutil::locate((startLine - 10) / 2, 11);
            cout << "Error al dar de baja el Analisis" << endl;
            cout << endl;
            rlutil::locate((startLine - 10) / 2, 15);
            system("pause");
            return;
        }
    }
    else
    {
        rlutil::cls();
        rlutil::locate((startLine - 10) / 2, 11);
        cout << "No se encontro un analisis con ese ID en el archivo" << endl;
        cout << endl;
        rlutil::locate((startLine - 10) / 2, 15);
        system("pause");
        return;
    }
}

///Modificar un tipo de analisis
void TipoAnalisisManager::opcion3()
{
    int idAnalisis;
    int y = 0, opc = 0;

    rlutil::cls();
    string titulo = "MODIFICAR UN TIPO DE ANALISIS";
    string linea =  "--------------------------------------";

    int startLine = (anchoConsola - titulo.length() + 10);

    rlutil::locate( startLine /2, 8);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 9);
    cout << linea << endl;


    rlutil::locate((startLine - 25) / 2, 11);
    cout << "Ingrese el ID del analisis que desea modificar: "<< endl;
    rlutil::locate((startLine + 71) / 2, 11);
    cin >> idAnalisis;

    int pos = _archivo.buscar(idAnalisis);

    if(pos < 0)
    {
        rlutil::cls();
        rlutil::locate((startLine - 20) / 2, 11);
        cout << "No se encontro un analisis con ese ID en el archivo" << endl;
        cout << endl;
        rlutil::locate((startLine - 10) / 2, 15);
        system("pause");
    }

    TipoAnalisis registro = _archivo.leer(pos);

    char nombre [60];

    while (opc == 0)
    {
        rlutil::cls();

        rlutil::locate( startLine /2, 10);
        cout << titulo << endl;
        rlutil::locate((startLine - 10) / 2, 11);
        cout << linea << endl;

        rlutil::locate((startLine + 5) / 2, 13);
        cout << "Modificar nombre." << endl;
        rlutil::locate((startLine + 5) / 2, 15);
        cout << "Cancelar y volver al menu anterior." << endl;
        rlutil::locate((startLine + 1) / 2, 13 + y);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14:
            if (y > 0)
            {
                y = y - 2;
            }
            break;

        case 15:
            if (y < 2)
            {
                y = y +2;
            }
            break;

        case 1:
            switch(y)
            {
            case 0:
            {
                rlutil::cls();
                rlutil::locate((startLine - 10) / 2, 11);
                cout << "Ingresar el nuevo nombre del analisis: " << endl;
                rlutil::locate((startLine + 68) / 2, 11);
                cin.ignore();
                cargarCadena(nombre, 59);
                cout << endl;
                rlutil::locate((startLine - 10) / 2, 15);
                system("pause");
                registro.setNombre(nombre);

                if (_archivo.guardar(registro, pos))
                {
                    rlutil::cls();
                    rlutil::locate((startLine - 10) / 2, 11);
                    cout << "El nuevo nombre se guardo exitosamente. " << endl;
                    cout << endl;
                    rlutil::locate((startLine - 10) / 2, 15);
                    system("pause");
                    return;
                }
                else
                {
                    rlutil::cls();
                    rlutil::locate((startLine - 10) / 2, 11);
                    cout << "No se pudo modificar el nombre del analisis en archivo. " << endl;
                    cout << endl;
                    rlutil::locate((startLine - 10) / 2, 15);
                    system("pause");
                    return;
                }
                break;
            }

            case 2:
                return;
            }
            break;
        }

    }
}


/// Listar todos los tipos de analisis
void TipoAnalisisManager::opcion4()
{
    int cantidad = _archivo.cantidadRegistros();
    rlutil::cls();
    string titulo = "LISTADO DE LOS TIPO DE ANALISIS";
    string linea =  "-----------------------------------------";

    int startLine = (anchoConsola - titulo.length() + 10);

    rlutil::locate( startLine /2, 4);
    cout << titulo << endl;
    rlutil::locate((startLine - 10) / 2, 5);
    cout << linea << endl;

    int y = 0;
    for (int i = 0; i < cantidad; i++)
    {
        TipoAnalisis registro = _archivo.leer(i);
        if(registro.getEstado())
        {
           int x = (y*5) + 7;

        rlutil::locate(( startLine + 5) / 2, (x + i));
        cout << "ID del analisis: "<< registro.getIDAnalisis() << endl;
        rlutil::locate((startLine + 5) / 2, (x + 1 + i));
        cout << "ID del tipo de muestra: " << registro.getIDMuestra() << endl;
        rlutil::locate((startLine + 5) / 2, (x + 2 + i));
        cout << "Nombre del analisis: " << registro.getNombre() << endl;

        rlutil::locate((startLine - 10) / 2, (x + 4 + i));
        cout << linea << endl;
        y++;
        }
    }
    rlutil::locate((startLine - 10) / 2, (y*5 + 40));
    system("pause");
}
