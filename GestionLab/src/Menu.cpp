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
            ///menuGestionTurnos();
            break;
        case 3:
           /// menuGestionEstudios();
            break;
        case 4:
           /// menuGestionDatosSistema();
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



