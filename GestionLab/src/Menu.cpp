#include "Menu.h"
#include <iostream>
using namespace std;

//Variable global
int consola_ancho = 100;

///INICIO FUNCIONES MENU GESTION

void Menu::menuGestionPacientes()
{

    PacienteManager manager;

    int y = 0;

    while(true)
    {
        //Titulo principal centrado
        string titulo = "MENU PACIENTES";
        string linea = "-----------------------------";

        rlutil::locate((consola_ancho - titulo.length()) / 2, 9);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;

        //Opciones del menu

        const char* opciones[] =
        {
            "REGISTRAR NUEVO PACIENTE",
            "BUSCAR UN PACIENTE",
            "EDITAR INFORMACION DE UN PACIENTE",
            "DAR DE BAJA UN PACIENTE",
            "RESTAURAR UN PACIENTE",
            "MOSTRAR LISTADO DE PACIENTES",
            "VOLVER AL MENU ANTERIOR"
        };

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        showItem(opciones[4], 20, y == 8);
        showItem(opciones[5], 22, y == 10);
        showItem(opciones[6], 24, y == 12);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: //DOWN
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y + 2;
            if(y > 12)
            {
                y = 12;
            }
            break;
        case 1: //ENTER

            rlutil::cls();

            switch (y)
            {
            case 0:
                manager.opcion1();
                break;
            case 2:
                manager.opcion2();
                break;
            case 4:
                manager.opcion3();
                break;
            case 6:
                manager.opcion4();
                break;
            case 8:
                manager.opcion5();
                break;
            case 10:
                manager.opcion6();
                break;
            case 12:
                return;
            }
            rlutil::cls();
            break;
        }
    }
}

void Menu::menuGestionTurnos()
{

    TurnoManager manager;

    int y = 0;

    //int opc;
    while(true)
    {

        rlutil::cls();

        //Titulo principal centrado
        string titulo = "MENU TURNOS";
        string linea = "-------------------------------------";

        rlutil::locate((consola_ancho - titulo.length()) / 2, 9);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;

        //Opciones del menu
        const char* opciones[] =
        {
            "AGENDAR NUEVO TURNO",
            "REPROGRAMAR TURNO",
            "MODIFICAR ESTADO DE UN TURNO",
            "BUSCAR TURNOS DE UN PACIENTE",
            "MOSTRAR LISTA DE TURNOS",
            "VOLVER AL MENU ANTERIOR"
        };

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        showItem(opciones[4], 20, y == 8);
        showItem(opciones[5], 22, y == 10);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: //DOWN
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y + 2;
            if(y > 10)
            {
                y = 10;
            }
            break;
        case 1: //ENTER

            rlutil::cls();

            switch (y)
            {
            case 0:
                manager.opcion1();
                break;
            case 2:
                manager.opcion2();
                break;
            case 4:
                manager.opcion3();
                break;
            case 6:
                manager.opcion4();
                break;
            case 8:
                manager.opcion5();
                break;
            case 10:
                return;
            }
            
            rlutil::cls();
            break;
        }
    }
}

void Menu::menuGestionEstudios()
{

    EstudioManager manager;

    int y = 0;

    while(true)
    {

        rlutil::cls();

        //Titulo principal centrado
        string titulo = "MENU ESTUDIOS";
        string linea = "-------------------------------------";

        rlutil::locate((consola_ancho - titulo.length()) / 2, 9);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;

        //Opciones del menu

        const char* opciones[] =
        {
            "REGISTRAR UN NUEVO ESTUDIO",
            "ELIMINAR UN ESTUDIO",
            "MODIFICAR UN ESTUDIO",
            "BUSCAR UN ESTUDIO",
            "LISTAR TODOS LOS ESTUDIOS",
            "VOLVER AL MENU ANTERIOR"
        };

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        showItem(opciones[4], 20, y == 8);
        showItem(opciones[5], 22, y == 10);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: //DOWN
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y + 2;
            if(y > 10)
            {
                y = 10;
            }
            break;
        case 1: //ENTER

            rlutil::cls();

            switch (y)
            {
            case 0:
                manager.opcion1();
                break;
            case 2:
                manager.opcion2();
                break;
            case 4:
                manager.opcion3();
                break;
            case 6:
                manager.opcion4();
                break;
            case 8:
                manager.opcion5();
                break;
            case 10:
                return;
            }
            rlutil::cls();
            break;
        }
    }
}

void Menu::menuGestionDatosSistema()
{

    TipoAnalisisManager mTipoAnalisis;
    TipoMuestraManager mTipoMuestra;

    int y = 0;

    while(true)
    {

        rlutil::cls();

        //Titulo principal centrado
        string titulo = "GESTION DE DATOS DEL SISTEMA";
        string linea = "-------------------------------------";

        rlutil::locate((consola_ancho - titulo.length()) / 2, 3);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 4);
        cout << linea << endl;

        const char* opciones[] =
        {
            "AGREGAR TIPO DE MUESTRA",
            "ELIMINAR TIPO DE MUESTRA",
            "MODIFICAR TIPO DE MUESTRA",
            "LISTAR TODOS LOS TIPOS DE MUESTRAS",
            "AGREGAR TIPO DE ANALISIS",
            "ELIMINAR TIPO DE ANALISIS",
            "MODIFICAR TIPO DE ANALISIS",
            "LISTAR TODOS LOS TIPOS DE ANALISIS",
            "VOLVER AL MENU ANTERIOR"
        };

        string subtitulo1 = "TIPOS DE MUESTRAS";

        rlutil::locate((consola_ancho - 60) / 2, 6);
        cout << subtitulo1 << endl;

        showItem(opciones[0], 8, y == 0);
        showItem(opciones[1], 10, y == 2);
        showItem(opciones[2], 12, y == 4);
        showItem(opciones[3], 14, y == 6);

        cout << endl;

        string subtitulo2 = "TIPOS DE ANALISIS";

        rlutil::locate((consola_ancho - 60) / 2, 16);
        cout << subtitulo2 << endl;

        showItem(opciones[4], 18, y == 8);
        showItem(opciones[5], 20, y == 10);
        showItem(opciones[6], 22, y == 12);
        showItem(opciones[7], 24, y == 14);

        showItem(opciones[8], 28, y == 16);

        const int filas[] =
        {
            8, 10, 12, 14, 18, 20, 22, 24, 28
        };

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, filas[y/2]);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, filas[y/2]);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: //DOWN
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, filas[y/2]);
            cout << " " << endl;
            y = y + 2;
            if(y > 16)
            {
                y = 16;
            }
            break;
        case 1: //ENTER

            rlutil::cls();

            switch(y)
            {
            case 0:
                mTipoMuestra.opcion1();
                break;
            case 2:
                mTipoMuestra.opcion2();
                break;
            case 4:
                mTipoMuestra.opcion3();
                break;
            case 6:
                mTipoMuestra.opcion4();
                break;
            case 8:
                mTipoAnalisis.opcion1();
                break;
            case 10:
                mTipoAnalisis.opcion2();
                break;
            case 12:
                mTipoAnalisis.opcion3();
                break;
            case 14:
                mTipoAnalisis.opcion4();
                break;
            case 16:
                return;
            }
            rlutil::cls();
            break;
        }
    }
}

///FIN FUNCIONES MENU GESTION

///INICIO MENU GESTION

void Menu::menuGestiones()
{
    int y = 0;

    while (true)
    {

        rlutil::cls();

        //Titulo principal centrado
        string titulo = "MENU GESTIONES";
        string linea = "---------------------";

        rlutil::locate((consola_ancho - titulo.length()) / 2, 9);
        cout << titulo << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;

        //Opciones del menu

        const char* opciones[] =
        {
            "PACIENTES",
            "TURNOS",
            "ESTUDIOS",
            "DATOS DEL SISTEMA",
            "VOLVER A ATRAS"
        } ;

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        showItem(opciones[4], 20, y == 8);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;
        case 15: //DOWN
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y + 2;
            if(y > 8)
            {
                y = 8;
            }
            break;
        case 1: //ENTER
            rlutil::cls();
            switch (y)
            {
                case 0:
                    menuGestionPacientes();
                    break;
                case 2:
                    menuGestionTurnos();
                    break;
                case 4:
                    menuGestionEstudios();
                    break;
                case 6:
                    menuGestionDatosSistema();
                    break;
                case 8:
                    return;
            }
            break;
        }
    }
}

///FIN MENU GESTION

///INICIO FUNCIONES MENU REPORTES

void Menu::informe4()
{
    string tituloInforme4 = "PACIENTES ORDENADOS ALFABETICAMENTE";
    string linea4 = "---------------------------------------------";

    int startLine4 = (consola_ancho - tituloInforme4.length() - 37);

    rlutil::locate((consola_ancho - startLine4) /2, 4);
    cout << tituloInforme4 << endl;
    rlutil::locate((consola_ancho - startLine4) - 83 / 2, 5);
    cout << linea4 << endl;


    PacienteArchivo archivo;

    int cant = archivo.cantidadRegistros();

    Paciente *vRegistros = new Paciente[cant];

    if(vRegistros == nullptr)
    {
        rlutil::cls();
        rlutil::locate((consola_ancho - startLine4) - 83 / 2, 10);
        cout << "Error al pedir memoria y leer el archivo" << endl;
        cout << endl;
        rlutil::locate((consola_ancho - startLine4) - 83 / 2, 15);
        system("pause");
        return;
    }

    archivo.leer(cant, vRegistros);

    for (int i = 0; i < cant; i++)
    {
        for (int j = i + 1; j < cant; j++)
        {

            //Hay que poner todas las cadenas en minusculas o mayusculas antes de
            //compararlas.

            char apellidoI[40], apellidoJ[40];
            strcpy(apellidoI, vRegistros[i].getApellido());
            strcpy(apellidoJ, vRegistros[j].getApellido());

            toLowerWord(apellidoI);
            toLowerWord(apellidoJ);

            if(strcmp(apellidoI, apellidoJ) > 0)
            {
                swap(vRegistros[i], vRegistros[j]);
            }
        }
    }

    //Mostrar por pantalla

    for(int i = 0; i < cant; i++)
    {
        int x = (i*9) + 7;

        rlutil::locate((consola_ancho - startLine4) / 2, (x + i));
        cout << "DNI: " << vRegistros[i].getDNI() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 1 + i));
        cout << "NOMBRE Y APELLIDO: " << vRegistros[i].getNombre() << " " << vRegistros[i].getApellido() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 2 + i));
        cout << "TELEFONO: " << vRegistros[i].getTelefono() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 3 + i));
        cout << "CORREO ELECTRONICO: " << vRegistros[i].getEmail() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 4 + i));
        cout << "OBRA SOCIAL:  " << vRegistros[i].getObraSocial() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 5 + i));
        cout << "NRO. DE AFILIADO: " << vRegistros[i].getNumeroAfiliado() << endl;
        rlutil::locate((consola_ancho - startLine4) / 2, (x + 6 + i));
        cout << "FECHA DE NACIMIENTO: " << vRegistros[i].getDateB().toString() << endl;

        rlutil::locate((consola_ancho - startLine4) - 83 / 2, (x + 8 + i));
        cout << linea4 << endl;

    }
    cout << endl;
    delete[] vRegistros;
}

void Menu::informe5()
{

    int dniPaciente;

    string tituloInforme5 = "HISTORIAL DE ESTUDIOS POR PACIENTE";
    string linea5 = "--------------------------------------------";

    int startLine5 = (consola_ancho - tituloInforme5.length() - 37);

    rlutil::locate((consola_ancho - startLine5) /2, 4);
    cout << tituloInforme5 << endl;
    rlutil::locate((consola_ancho - startLine5) - 83 / 2, 5);
    cout << linea5 << endl;

    string ingreso = "INGRESE EL DNI DEL PACIENTE: ";

    rlutil::locate((consola_ancho - startLine5) / 2, 6);
    cout << ingreso << endl;

    rlutil::locate((consola_ancho - startLine5) - 15 / 2, 6);
    cin >> dniPaciente;

    rlutil::locate((consola_ancho - startLine5) - 83 / 2, 7);
    cout << linea5 << endl;

    PacienteArchivo archivo;

    int pos = archivo.buscar(dniPaciente);

    Paciente registro = archivo.leer(pos);

    string titulo2 = "ESTUDIOS REALIZADOS POR ";

    rlutil::locate((consola_ancho - startLine5) / 2, 9);
    cout << titulo2 << registro.getNombre() << " " << registro.getApellido() << endl;

    EstudioArchivo archivoEstudios;

    int cant = archivoEstudios.cantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        Estudio estudio = archivoEstudios.leer(i);

        if(estudio.getDNI() == dniPaciente)
        {
            int x = (i*8) + 11;

            rlutil::locate((consola_ancho - startLine5) / 2, (x + i));
            cout << "ID ESTUDIO: " << estudio.getIDEstudio() << endl;
            rlutil::locate((consola_ancho - startLine5) / 2, (x + 1 + i));
            cout << "DNI: " << estudio.getDNI() << endl;
            rlutil::locate((consola_ancho - startLine5) / 2, (x + 2 + i));
            cout << "SALA: " << estudio.getSala() << endl;
            rlutil::locate((consola_ancho - startLine5) / 2, (x + 3 + i));
            cout << "ID TURNO: " << estudio.getIDTurno() << endl;
            rlutil::locate((consola_ancho - startLine5) / 2, (x + 4 + i));
            cout << "PRECIO: $" << estudio.getPrecio() << endl;
            rlutil::locate((consola_ancho - startLine5) / 2, (x + 5 + i));
            cout << "ESTADO DEL ESTUDIO: ";
            switch(estudio.getEstadoEstudio())
            {
            case 1:
                cout << "EN PROCESO" << endl;
                break;
            case 2:
                cout << "ESPERANDO RESULTADOS" << endl;
                break;
            case 3:
                cout << "RESULTADOS LISTOS" << endl;
                break;
            case 4:
                cout << "ANULADO" << endl;
                break;
            }


            rlutil::locate((consola_ancho - startLine5) - 83 / 2, (x + 7 + i));
            cout << linea5 << endl;
        }
    }
    cout << endl;
}

void Menu::informe1()
{
    //int y = 0;
    rlutil::hidecursor();

    PacienteArchivo arcPaci;
    EstudioArchivo arcEst;

    int dniMax;
    int contador = 0;
    int contador2 = 0;
    int cantidad = arcPaci.cantidadRegistros();
    int cantReg = arcEst.cantidadRegistros();

    rlutil::cls();
    string tituloInforme1 = "PACIENTE CON MAS ESTUDIOS REALIZADOS: ";
    string lineaInforme1 = "-----------------------------------------------";

    int startLine = (tituloInforme1.length() - 10);

    rlutil::locate((consola_ancho - startLine) / 2, 8);
    cout << tituloInforme1 << endl;
    rlutil::locate((consola_ancho - startLine - 10) / 2, 9);
    cout << lineaInforme1 << endl;

    cout << endl;

    for (int i = 0; i < cantidad; i++)/// Recorre los pacientes
    {
        Paciente reg = arcPaci.leer(i);

        if (i==0)
        {
            dniMax = reg.getDNI();
            for (int x = 0; x < cantReg; x++)///recorre los estudios
            {
                Estudio regEst = arcEst.leer(x);
                if (dniMax == regEst.getDNI())
                {
                    contador++;
                }
            }
            contador2 = contador;
            contador = 0;
        }
        else
        {
            for (int j = 0; j < cantReg; j++)
            {
                Estudio regEst = arcEst.leer(j);
                if (reg.getDNI() == regEst.getDNI())
                {
                    contador++;
                }
            }
            if (contador2 < contador)
            {
                dniMax = reg.getDNI();
                contador2 = contador;
                contador = 0;
            }
        }
        Paciente obj;
        int pos = arcPaci.buscar(dniMax);
        obj = arcPaci.leer(pos);

/// MUESTRA DE RESULTADOS

        string dniLinea = "DNI PACIENTE: ";
        string nameLinea = "NOMBRE Y APELLIDO: ";
        string dobLinea = "FECHA DE NACIMEINTO: ";
        string cantAnalisis = "CANTIDAD DE ANALISIS REALIZADOS: ";

        rlutil::locate((consola_ancho - startLine) / 2, 11);
        cout << dniLinea << obj.getDNI() << endl;
        rlutil::locate((consola_ancho - startLine) / 2, 12);
        cout << nameLinea << obj.getNombre() << " " << obj.getApellido() << endl;
        rlutil::locate((consola_ancho - startLine) / 2, 13);
        cout << dobLinea << obj.getDateB().getDia() << "/" << obj.getDateB().getMes() << "/" << obj.getDateB().getAnio() << endl;
        cout << endl;
        rlutil::locate((consola_ancho - startLine) / 2, 15);
        cout << cantAnalisis << contador2 << endl;
        cout << endl;

        rlutil::locate((consola_ancho - startLine - 10) / 2, 20);
        system("pause");
        return;

    }
}

void Menu::informe2()
{
    /// Recaudación por tipo de estudio.

    Estudio objEst;
    EstudioArchivo archivoEst;

    EstudioAnalisisArchivo archivoEstAnalisis;
    EstudioAnalisis objEstAnalisis;

    TipoAnalisisArchivo archivoAnalisis;
    TipoAnalisis objAnalisis;

    float auxSangre = 0;
    float auxOrina =0;
    float auxHeces = 0;
    float auxSec = 0;
    float auxBiopsias = 0;

    int cantEstudios = archivoEst.cantidadRegistros();
    int cantAnalisis = archivoEstAnalisis.cantidadRegistros();
    for (int i=0; i < cantEstudios; i++)
    {
        objEst = archivoEst.leer(i);

        for (int x = 0; x < cantAnalisis; x++)
        {
            objEstAnalisis = archivoEstAnalisis.leer(x);

            if (strcmp(objEst.getIDEstudio(),objEstAnalisis.getIDEstudio())==0)
            {
                int pos = archivoAnalisis.buscar(objEstAnalisis.getIDAnalisis());
                objAnalisis = archivoAnalisis.leer(pos);

                switch (objAnalisis.getIDMuestra())
                {
                case 1:
                    auxSangre += objEst.getPrecio();
                    break;

                case 2:
                    auxOrina += objEst.getPrecio();
                    break;

                case 3:
                    auxHeces += objEst.getPrecio();
                    break;

                case 4:
                    auxSec += objEst.getPrecio();
                    break;

                case 5:
                    auxBiopsias += objEst.getPrecio();
                    break;
                }
            }
        }
    }

    string tituloInforme2 = "RECAUDACION POR TIPO DE MUESTRA";
    string lineaInforme2 = "-----------------------------------------";

    int startLine2 = (consola_ancho - tituloInforme2.length() - 41 );

    rlutil::locate((consola_ancho - startLine2) / 2, 8);
    cout << tituloInforme2 << endl;
    rlutil::locate((consola_ancho - startLine2 - 10) / 2, 9);
    cout << lineaInforme2 << endl;


    string sangre = "FACTURACION TOTAL DE ESTUDIOS DE SANGRE: ";
    string orina = "FACTURACION TOTAL DE ESTUDIOS DE ORINA: ";
    string heces = "FACTURACION TOTAL DE ESTUDIOS DE HECES: ";
    string secreciones = "FACTURACION TOTAL DE ESTUDIOS DE SECRECIONES Y LIQUIDOS BIOLOGICOS: ";
    string biopsias = "FACTURACION TOTAL DE ESTUDIOS DE TEJIDOS Y BIOPSIAS: ";


    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 11);
    cout << sangre << auxSangre << endl;
    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 12);
    cout << orina << auxOrina << endl;
    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 13);
    cout << heces << auxHeces << endl;
    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 14);
    cout << secreciones << auxSec << endl;
    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 15);
    cout << biopsias << auxBiopsias << endl;

    rlutil::locate((consola_ancho - startLine2) - 81 / 2, 18);
    cout << endl;
}

void Menu::informe3()
{
    int anio;

    string tituloInforme3 ="RECAUDACION POR ANIO";
    string lineaInforme3 = "------------------------------";

    int startLine3 = (tituloInforme3.length() + 8);

    rlutil::locate((consola_ancho - startLine3) / 2, 8);
    cout << tituloInforme3 << endl;
    rlutil::locate((consola_ancho - startLine3) - 82 / 2, 9);
    cout << lineaInforme3 << endl;

    string ingreso = "INGRESE EL ANIO: ";

    rlutil::locate((consola_ancho - startLine3) / 2, 11);
    cout << ingreso << endl;
    rlutil::locate((consola_ancho - startLine3) - 37 / 2, 11);
    cin >> anio;

    EstudioArchivo archivoEst;
    Estudio objEst;

    TurnoArchivo archivoTurno;
    Turno objTurno;

    float aux = 0;

    int cantEstudios = archivoEst.cantidadRegistros();
    int cantTurnos = archivoTurno.cantidadRegistros();

    for (int i=0; i < cantEstudios; i++)
    {
        objEst = archivoEst.leer(i);
        for (int x = 0; x < cantTurnos; x++)
        {
            objTurno = archivoTurno.leer(x);
            if(objEst.getIDTurno() == objTurno.getIDTurno())
            {
                if (anio == objTurno.getFechaProgramada().getAnio())
                {
                    aux += objEst.getPrecio();
                }
            }
        }
    }

    string resultado = "RECAUDACION DEL ANIO ";

    rlutil::locate((consola_ancho - startLine3) / 2, 13);
    cout << resultado << anio << ": " <<  "$"  << aux << endl;
    cout << endl;

}

///FIN FUNCIONES MENU REPORTES

///INICIO MENU REPORTES

void Menu::menuInformes()
{
    //int opc = 1;
    int y = 0;
    rlutil::hidecursor();
    while (true)
    {
        rlutil::cls();
        string title = "MENU INFORMES";
        string linea = "-----------------------------";

        rlutil::locate((consola_ancho - title.length()) / 2, 9);
        cout << title << endl;
        rlutil::locate((consola_ancho - linea.length()) / 2, 10);
        cout << linea << endl;

        const char* opciones[] =
        {
            "PACIENTE CON MAYOR CANTIDAD DE ESTUDIOS REALIZADOS",
            "RECAUDACION POR TIPO DE ESTUDIO",
            "RECAUDACION POR ANIO",
            "LISTAR PACIENTES EN ORDEN ALFABETICO",
            "MOSTRAR HISTORIAL DE UN PACIENTE",
            "VOLVER AL MENU ANTERIOR"
        };

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);
        showItem(opciones[3], 18, y == 6);
        showItem(opciones[4], 20, y == 8);
        showItem(opciones[5], 22, y == 10);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: // UP
            largoTexto = strlen(opciones[y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if(y < 0)
            {
                y = 0;
            }
            break;

        case 15: // DOWN
            largoTexto = strlen(opciones[y/2]);
            rlutil::locate((consola_ancho - largoTexto)/ 2 -3, 10 + y);
            cout << " " << endl;
            y = y + 2;
            if (y > 10)
            {
                y = 10;
            }
            break;

        case 1: // ENTER

            switch (y)
            {
            case 0:
                rlutil::cls();
                informe1();
                rlutil::locate((consola_ancho - linea.length()) / 2, 18);
                system("pause");
                break;

            case 2:
                rlutil::cls();
                informe2();
                rlutil::locate((consola_ancho - linea.length()) / 2, 18);
                system("pause");
                break;

            case 4:
                rlutil::cls();
                informe3();
                rlutil::locate((consola_ancho - linea.length()) / 2, 18);
                system("pause");
                break;

            case 6:
                rlutil::cls();
                informe4();
                rlutil::locate((consola_ancho - linea.length()) / 2, 18);
                system("pause");
                break;

            case 8:
                rlutil::cls();
                informe5();
                rlutil::locate((consola_ancho - linea.length()) / 2, 18);
                system("pause");
                break;

            case 10:
                return;
            }
        }
    }
}

///FIN MENU REPORTES

///INICIO FUNCIONES MENU CONFIGURACION

void Menu::copiaSeguridad()
{
    int op = 0, y = 0;
    while(op == 0)
    {
        rlutil::hidecursor();
        rlutil::cls();

        string titulo = "COPIAS DE SEGURIDAD";
        string linea = "-----------------------------";

        int startLine = (consola_ancho - titulo.length() + 10 );

        rlutil::locate(startLine / 2, 8);
        cout << titulo << endl;
        rlutil::locate((startLine - 10) / 2, 9);
        cout << linea << endl;

        rlutil::locate((startLine - 59) / 2, 11);
        cout << "Esta seguro que desea realizar una copia de seguridad de todos los archivos?" << endl;
        rlutil::locate((startLine + 18) / 2, 13);
        cout << "SI" << endl;
        rlutil::locate((startLine + 18) / 2, 15);
        cout << "NO" << endl;
        rlutil::locate((startLine + 18) / 2, 17);
        cout << "VOLVER AL MENU ANTERIOR" << endl;
        rlutil::locate((startLine + 14)/ 2, 13 + y);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: // UP
            if (y > 0)
            {
                y = y - 2;
            }

            break;

        case 15: // DOWN
            if (y < 4)
            {
                y = y + 2;
            }
            break;

        case 1: //ENTER
            switch(y)
            {
            case 0:
            {

                //Pacientes
                PacienteArchivo pacienteArchivo;
                //Turnos
                TurnoArchivo turnoArchivo;
                //Estudios
                EstudioArchivo estudioArchivo;
                //TiposAnalisis
                TipoAnalisisArchivo tipoAnalisisArchivo;
                //TiposMuestra
                TipoMuestraArchivo tipoMuestraArchivo;
                //EstudiosAnalisis
                EstudioAnalisisArchivo estudioAnalisisArchivo;

                if(pacienteArchivo.copiaSeguridad())
                {
                    if(turnoArchivo.copiaSeguridad())
                    {
                        if(estudioArchivo.copiaSeguridad())
                        {
                            if(tipoAnalisisArchivo.copiaSeguridad())
                            {
                                if(tipoMuestraArchivo.copiaSeguridad())
                                {
                                    if(estudioAnalisisArchivo.copiaSeguridad())
                                    {
                                        rlutil::cls();
                                        rlutil::locate((startLine - 10) / 2, 9);
                                        cout << "La copia de seguridad de todos los archivos se realizo con exito!" << endl;
                                        cout << endl;
                                        rlutil::locate((startLine - 10) / 2, 15);
                                        system("pause");
                                    }
                                    else
                                    {
                                        rlutil::cls();
                                        rlutil::locate((startLine - 10) / 2, 9);
                                        cout << "Error con la copia de seguridad de Analisis de estudios" << endl;
                                        cout << endl;
                                        rlutil::locate((startLine - 10) / 2, 15);
                                        system("pause");
                                    }
                                }
                                else
                                {
                                    rlutil::cls();
                                    rlutil::locate((startLine - 10) / 2, 9);
                                    cout << "Error con la copia de seguridad de Tipos de Muestras" << endl;
                                    cout << endl;
                                    rlutil::locate((startLine - 10) / 2, 15);
                                    system("pause");
                                }
                            }
                            else
                            {
                                rlutil::cls();
                                rlutil::locate((startLine - 10) / 2, 9);
                                cout << "Error con la copia de seguridad de Tipos de Analisis" << endl;
                                cout << endl;
                                rlutil::locate((startLine - 10) / 2, 15);
                                system("pause");
                            }
                        }
                        else
                        {
                            rlutil::cls();
                            rlutil::locate((startLine - 10) / 2, 9);
                            cout << "Error con la copia de seguridad de Estudios" << endl;
                            cout << endl;
                            rlutil::locate((startLine - 10) / 2, 15);
                            system("pause");
                        }
                    }
                    else
                    {
                        rlutil::cls();
                        rlutil::locate((startLine - 10) / 2, 9);
                        cout << "Error con la copia de seguridad de Turnos" << endl;
                        cout << endl;
                        rlutil::locate((startLine - 10) / 2, 15);
                        system("pause");
                    }
                }
                else
                {
                    rlutil::cls();
                    rlutil::locate((startLine - 10) / 2, 9);
                    cout << "Error con la copia de seguridad de Pacientes" << endl;
                    cout << endl;
                    rlutil::locate((startLine - 10) / 2, 15);
                    system("pause");
                }
                break;
            }

            case 2:

                rlutil::cls();
                rlutil::locate((startLine - 10) / 2, 9);
                cout << "No se han realizado la copia de seguridad" << endl;
                cout << endl;
                rlutil::locate((startLine - 10) / 2, 15);
                system("pause");
                break;

            case 4:
                rlutil::locate((startLine - 10) / 2, 20);
                return;
            }
        }
    }
}


void Menu::restaurarCopiaSeguridad()
{
    int opc = 0, y = 0;

    while (opc == 0)
    {
        rlutil::hidecursor();
        rlutil::cls();

        string titulo = "RESTAURAR COPIAS DE SEGURIDAD";
        string linea =  "---------------------------------------";

        int startLine = (consola_ancho - titulo.length() + 10 );

        rlutil::locate(startLine / 2, 8);
        cout << titulo << endl;
        rlutil::locate((startLine - 10) / 2, 9);
        cout << linea << endl;

        rlutil::locate((startLine - 59) / 2, 11);
        cout << "¨Esta seguro que desea restaurar la copia de seguridad de todos los archivos?" << endl;
        rlutil::locate((startLine + 20) / 2, 13);
        cout << "SI" << endl;
        rlutil::locate((startLine + 20) / 2, 15);
        cout << "NO" << endl;
        rlutil::locate((startLine + 20) / 2, 17);
        cout << "VOLVER AL MENU ANTERIOR" << endl;
        rlutil::locate((startLine + 16)/ 2, 13 + y);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: // UP
            if (y > 0)
            {
                y = y - 2;
            }

            break;

        case 15: // DOWN
            if (y < 4)
            {
                y = y + 2;
            }
            break;

        case 1: //ENTER
            switch(y)
            {
            case 0:
            {

                //Pacientes
                PacienteArchivo pacienteArchivo;
                //Turnos
                TurnoArchivo turnoArchivo;
                //Estudios
                EstudioArchivo estudioArchivo;
                //TiposAnalisis
                TipoAnalisisArchivo tipoAnalisisArchivo;
                //TiposMuestra
                TipoMuestraArchivo tipoMuestraArchivo;
                //EstudiosAnalisis
                EstudioAnalisisArchivo estudioAnalisisArchivo;

                if(pacienteArchivo.restaurarCopia())
                {
                    if(turnoArchivo.restaurarCopia())
                    {
                        if(estudioArchivo.restaurarCopia())
                        {
                            if(tipoAnalisisArchivo.restaurarCopia())
                            {
                                if(tipoMuestraArchivo.restaurarCopia())
                                {
                                    if(estudioAnalisisArchivo.restaurarCopia())
                                    {
                                        rlutil::cls();
                                        rlutil::locate((startLine - 20) / 2, 9);
                                        cout << "La copia de seguridad de todos los archivos se restauro con exito!" << endl;
                                        cout << endl;
                                        rlutil::locate((startLine - 10) / 2, 15);
                                        system("pause");
                                    }
                                    else
                                    {
                                        rlutil::cls();
                                        rlutil::locate((startLine - 20) / 2, 9);
                                        cout << "Error con la restauracion de la copia de seguridad de Analisis de estudios" << endl;
                                        cout << endl;
                                        rlutil::locate((startLine - 10) / 2, 15);
                                        system("pause");
                                    }
                                }
                                else
                                {
                                    rlutil::cls();
                                    rlutil::locate((startLine - 20) / 2, 9);
                                    cout << "Error con la restauracion de la copia de seguridad de Tipos de Muestras" << endl;
                                    cout << endl;
                                    rlutil::locate((startLine - 10) / 2, 15);
                                    system("pause");
                                }
                            }
                            else
                            {
                                rlutil::cls();
                                rlutil::locate((startLine - 20) / 2, 9);
                                cout << "Error con la restauracion de la copia de seguridad de Tipos de Analisis" << endl;
                                cout << endl;
                                rlutil::locate((startLine - 10) / 2, 15);
                                system("pause");
                            }
                        }
                        else
                        {
                            rlutil::cls();
                            rlutil::locate((startLine - 20) / 2, 9);
                            cout << "Error con la restauracion de la copia de seguridad de Estudios" << endl;
                            cout << endl;
                            rlutil::locate((startLine - 10) / 2, 15);
                            system("pause");
                        }
                    }
                    else
                    {
                        rlutil::cls();
                        rlutil::locate((startLine - 20) / 2, 9);
                        cout << "Error con la restauracion de la copia de seguridad de Turnos" << endl;
                        cout << endl;
                        rlutil::locate((startLine - 10) / 2, 15);
                        system("pause");
                    }
                }
                else
                {
                    rlutil::cls();
                    rlutil::locate((startLine - 20) / 2, 9);
                    cout << "Error con la restauracion de la copia de seguridad de Pacientes" << endl;
                    cout << endl;
                    rlutil::locate((startLine - 10) / 2, 15);
                    system("pause");
                }
                break;
            }

            case 2:

                rlutil::cls();
                rlutil::locate((startLine - 10) / 2, 9);
                cout << "No se ha restaurado la copia de seguridad" << endl;
                cout << endl;
                rlutil::locate((startLine - 10) / 2, 15);
                system("pause");
                break;

            case 4:
                rlutil::locate((startLine - 10) / 2, 20);
                return;
            }
        }
    }
}

///FIN FUNCIONES MENU CONFIGURACION

///INICIO MENU CONFIGURACION
void Menu::menuConfiguraciones()
{
    int y = 0;
    rlutil::hidecursor();
    while (true)
    {
        rlutil::cls();
        string tituloConfig = "MENU DE CONFIGURACIONES";
        string lineaConfig =  "---------------------------------";

        rlutil::locate((consola_ancho - tituloConfig.length()) / 2, 9);
        cout << tituloConfig << endl;
        rlutil::locate((consola_ancho - lineaConfig.length()) / 2, 10);
        cout << lineaConfig << endl;

        const char* opciones[] =
        {
            "COPIAS DE SEGURIDAD",
            "RESTAURAR COPIAS DE SEGURIDAD",
            "VOLVER AL MENU ANTERIOR"
        };

        showItem(opciones[0], 12, y == 0);
        showItem(opciones[1], 14, y == 2);
        showItem(opciones[2], 16, y == 4);

        int largoTexto = strlen(opciones[y / 2]);
        rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
        cout << (char)175;

        int key = rlutil::getkey();
        switch (key)
        {
        case 14: // UP
            largoTexto = strlen(opciones [y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
            cout << " " << endl;
            y = y - 2;
            if (y < 0)
            {
                y = 0;
            }
            break;
        case 15: // DOWN
            largoTexto = strlen(opciones [y / 2]);
            rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 10 + y);
            cout << " " << endl;
            y = y + 2;
            if (y > 4)
            {
                y = 4;
            }
            break;
        case 1: /// ENTER
            rlutil::cls();
            switch(y)
            {
            case 0:
                rlutil::cls();
                copiaSeguridad();
                rlutil::locate((consola_ancho - lineaConfig.length()) / 2, 20);
                system("pause");
                break;

            case 2:
                rlutil::cls();
                restaurarCopiaSeguridad();
                rlutil::locate((consola_ancho - lineaConfig.length()) / 2, 20);
                system("pause");
                break;

            case 4:
                rlutil::locate((consola_ancho - lineaConfig.length()) / 2, 20);
                return;
            }
        }
    }
}

///FIN MENU CONFIGURACION
