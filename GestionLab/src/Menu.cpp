#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::menuGestionPacientes()
{

    PacienteManager manager;

    int opc;
    while(true)
    {

        system("cls");
        cout << "Menu Pacientes" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Registrar nuevo paciente " << endl;
        cout << "2. Buscar un paciente " << endl;
        cout << "3. Editar información de un paciente " << endl;
        cout << "4. Dar de baja un paciente  " << endl;
        cout << "5. Restaurar un paciente  " << endl;
        cout << "6. Mostrar lista de pacientes  " << endl;
        cout << "0. Volver al menu anterior  " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opc;
        system ("cls");
        switch (opc)
        {
        case 1:
            manager.opcion1();
            break;
        case 2:
            manager.opcion2();
            break;
        case 3:
            manager.opcion3();
            break;
        case 4:
            manager.opcion4();
            break;
        case 5:
            manager.opcion5();
            break;
        case 6:
            manager.opcion6();
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::menuGestionTurnos()
{

    TurnoManager manager;

    int opc;
    while(true)
    {

        system("cls");
        cout << "Menu Turnos" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Agendar nuevo turno " << endl;
        cout << "2. Reprogramar turno " << endl;
        cout << "3. Modificar estado de un turno " << endl;
        cout << "4. Buscar turnos de un paciente  " << endl;
        cout << "5. Mostrar lista de turnos  " << endl;
        cout << "0. Volver al menu anterior  " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opc;
        system ("cls");
        switch (opc)
        {
        case 1:
            manager.opcion1();
            break;
        case 2:
            manager.opcion2();
            break;
        case 3:
            manager.opcion3();
            break;
        case 4:
            manager.opcion4();
            break;
        case 5:
            manager.opcion5();
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::menuGestionEstudios()
{

    EstudioManager manager;

    int opc;
    while(true)
    {

        system("cls");
        cout << "Menu Estudios" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Registrar nuevo estudio" << endl;
        cout << "2. Eliminar estudio" << endl;
        cout << "3. Modificar un estudio" << endl;
        cout << "4. Buscar un estudio" << endl;
        cout << "5. Listar todos los estudios" << endl;
        cout << "0. Volver al menu anterior  " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opc;
        system ("cls");
        switch (opc)
        {
        case 1:
            manager.opcion1();
            break;
        case 2:
            manager.opcion2();
            break;
        case 3:
            manager.opcion3();
            break;
        case 4:
            manager.opcion4();
            break;
        case 5:
            manager.opcion5();
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::menuGestionDatosSistema()
{

    int opc;

    TipoAnalisisManager mTipoAnalisis;
    TipoMuestraManager mTipoMuestra;

    while(true)
    {

        system("cls");
        cout << "Menu Gestion Datos del Sistema" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Tipos de Muestras" << endl;
        cout << "   1. Agregar tipo de muestra" << endl;
        cout << "   2. Eliminar un tipo de muestra" << endl;
        cout << "   3. Modificar un tipo de muestra" << endl;
        cout << "   4. Listar todos los tipos de muestras" << endl;
        cout << "-------------------------------------" << endl;
        cout << "   5. Agregar tipo de analisis" << endl;
        cout << "   6. Eliminar un tipo de analisis" << endl;
        cout << "   7. Modificar un tipo de analisis" << endl;
        cout << "   8. Listar todos los tipos de analisis" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0. Volver al menu anterior  " << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opc;
        system ("cls");

        switch(opc)
        {
        case 1:
            mTipoMuestra.opcion1();
            break;
        case 2:
            mTipoMuestra.opcion2();
            break;
        case 3:
            mTipoMuestra.opcion3();
            break;
        case 4:
            mTipoMuestra.opcion4();
            break;
        case 5:
            mTipoAnalisis.opcion1();
            break;
        case 6:
            mTipoAnalisis.opcion2();
            break;
        case 7:
            mTipoAnalisis.opcion3();
            break;
        case 8:
            mTipoAnalisis.opcion4();
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }

    }
}

void Menu::menuGestiones()
{
    int opc;
    while (true)
    {
        system("cls");
        cout << "Menu Gestiones" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Gestion de Pacientes " << endl;
        cout << "2. Gestion de Turnos " << endl;
        cout << "3. Gestion de Estudios " << endl;
        cout << "4. Gestion de datos del sistema " << endl;
        cout << "0. Volver a atras " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opc;
        system ("cls");
        switch (opc)
        {
        case 1:
            menuGestionPacientes();
            break;
        case 2:
            menuGestionTurnos();
            break;
        case 3:
            menuGestionEstudios();
            break;
        case 4:
            menuGestionDatosSistema();
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta! Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::informe1()
{
    PacienteArchivo arcPaci;
    EstudioArchivo arcEst;

    int dniMax;
    int contador = 0;
    int contador2 = 0;
    int cantidad = arcPaci.cantidadRegistros();
    int cantReg = arcEst.cantidadRegistros();

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
    }

    Paciente obj;
    int pos = arcPaci.buscar(dniMax);
    obj = arcPaci.leer(pos);

    cout << "PACIENTE CON MAS ESTUDIOS REALIZADOS: " << endl;

    cout << endl;

    cout << "DNI PACIENTE: " << obj.getDNI() << endl;
    cout << "NOMBRE Y APELLIDO: " << obj.getNombre() << obj.getApellido() << endl;
    cout << "FECHA DE NACIMEINTO: " << obj.getDateB().getDia() << "/" << obj.getDateB().getMes() << "/" << obj.getDateB().getAnio() << endl;

    cout << endl;

    cout << "CANTIDAD DE ANALISIS REALIZADOS: " << contador2 << endl;
    return;

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

    cout << "RECAUDACION POR TIPO DE MUESTRA" << endl;
    cout << endl;

    cout << "FACTURACION TOTAL DE ESTUDIOS DE SANGRE: " << auxSangre << endl;
    cout << "FACTURACION TOTAL DE ESTUDIOS DE ORINA: " << auxOrina << endl;
    cout << "FACTURACION TOTAL DE ESTUDIOS DE HECES: " << auxHeces << endl;
    cout << "FACTURACION TOTAL DE ESTUDIOS DE SECRECIONES Y LIQUIDOS BIOLOGICOS: " << auxSec << endl;
    cout << "FACTURACION TOTAL DE ESTUDIOS DE TEJIDOS Y BIOPSIAS: " << auxBiopsias << endl;
    return;
}

void Menu::informe3()
{
    int anio;
    cout << "Ingrese el anio: " << endl;
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
        for (int x; x < cantTurnos; x++)
        {
            objTurno = archivoTurno.leer(x);
            if (anio == objTurno.getFechaProgramada().getAnio())
            {
                aux += objEst.getPrecio();
            }
        }
    }

    cout << "RECAUDACION DEL ANIO  " << anio  << ": " <<  "$"  << aux << endl;

}

    void Menu::menuInformes()
    {
        int opc;
        while (true)
        {
            system("cls");
            cout << "Menu Informes" << endl;
            cout << "-------------------------------------" << endl;
            cout << "1. Paciente con mayor cantidad de estudios realizados.  " << endl;
            cout << "2. Recaudacion por tipo de estudio. " << endl;
            cout << "3. Recaudacion anual por mes. " << endl;
            cout << "4. Listar pacientes en orden alfabetico.  " << endl;
            cout << "5. Mostrar historial de un paciente.  " << endl;
            cout << "0. Volver a atras " << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese la opcion deseada: ";
            cin >> opc;
            system ("cls");
            switch (opc)
            {
            case 1:
                informe1();
                system("pause");
                break;
            case 2:
                informe2();
                system("pause");
                break;
            case 3:
                informe3();
                system("pause");
                break;
            case 4:
                ///informe4();
                break;
            case 5:
                ///informe5();
                break;
            case 0:
                return;
            default:
                cout << "Opcion incorrecta! Intente nuevamente" << endl;
                system("pause");
                break;
            }
        }
    }

    void Menu::menuConfiguraciones()
    {
        int opc;
        while (true)
        {
            system("cls");
            cout << "Menu de Configuraciones" << endl;
            cout << "-------------------------------------" << endl;
            cout << "1. Copias de Seguridad" << endl;
            cout << "2. Restaurar copias de Seguridad" << endl;
            cout << "0. Volver a atras" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese la opcion deseada: ";
            cin >> opc;
            system ("cls");
            switch (opc)
            {
            case 1:
                ///copiaSeguridad();
                break;
            case 2:
                ///restaurarCopiaSeguridad();
                break;
            case 0:
                return;
            default:
                cout << "Opcion incorrecta! Intente nuevamente" << endl;
                system("pause");
                break;
            }
        }
    }



