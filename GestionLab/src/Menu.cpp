#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::menuGestionPacientes()
{

    PacienteManager manager;

    int opc;
    while(true){

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
    while(true){

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
    while(true){

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

void Menu::menuGestionDatosSistema(){

    int opc;

    TipoAnalisisManager mTipoAnalisis;
    TipoMuestraManager mTipoMuestra;

    while(true){

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

        switch(opc){
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
            ///informe1();
            break;
        case 2:
            ///informe2();
            break;
        case 3:
            ///informe3();
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

void Menu::copiaSeguridad()
{
    int opcion;
    
    cout << "¨Esta seguro que desea realizar una copia de seguridad de todos los archivos?" << endl;
    cout << "1 - SI" << endl;
    cout << "0 - NO" << endl;
    cout << "Seleccion: ";
    cin >> opcion;
    
    if(!opcion)
    {
        cout << "No se han realizado la copia de seguridad" << endl;
        return;
    }
    
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
    
    if(pacienteArchivo.copiaSeguridad()){
        if(turnoArchivo.copiaSeguridad()){
            if(estudioArchivo.copiaSeguridad()){
                if(tipoAnalisisArchivo.copiaSeguridad()){
                    if(tipoMuestraArchivo.copiaSeguridad()){
                        if(estudioAnalisisArchivo.copiaSeguridad()){
                            cout << "La copia de seguridad de todos los archivos se realizo con exito!" << endl;
                        } else {
                            cout << "Error con la copia de seguridad de Analisis de estudios" << endl;
                        }
                    } else {
                        cout << "Error con la copia de seguridad de Tipos de Muestras" << endl;
                    }
                } else {
                    cout << "Error con la copia de seguridad de Tipos de Analisis" << endl;
                }
            } else {
                cout << "Error con la copia de seguridad de Estudios" << endl;
            }
       } else {
           cout << "Error con la copia de seguridad de Turnos" << endl;
       }
    } else {
        cout << "Error con la copia de seguridad de Pacientes" << endl;
    }
}

void Menu::restaurarCopiaSeguridad()
{
   int opcion;
    
    cout << "¨Esta seguro que desea realizar restaurar copia de seguridad de todos los archivos?" << endl;
    cout << "1 - SI" << endl;
    cout << "0 - NO" << endl;
    cout << "Seleccion: ";
    cin >> opcion;
    
    if(!opcion)
    {
        cout << "No se han realizado la copia de seguridad" << endl;
        return;
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
            copiaSeguridad();
            system("pause");
            break;
        case 2:
            restaurarCopiaSeguridad();
            system("pause");
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



