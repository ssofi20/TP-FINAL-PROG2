#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::menuGestionPacientes()
{

    PacienteManager manager;
    
    int y = 0;
    int consola_ancho = 100;

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
        
        const char* opciones[] = {
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
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                largoTexto = strlen(opciones[y / 2]);
                rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
                cout << " " << endl;
                y = y + 2;
                if(y > 12){
                    y = 12;
                }
                break;
            case 1: //ENTER
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
                    default:
                        cout << "Opcion incorrecta! Intente nuevamente" << endl;
                        system("pause");
                        break;
                }
            break;
        }
    }
}

void Menu::menuGestionTurnos()
{

    TurnoManager manager;
    
    int y = 0;
    int consola_ancho = 100;

    int opc;
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
        
        const char* opciones[] = {
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
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                largoTexto = strlen(opciones[y / 2]);
                rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
                cout << " " << endl;
                y = y + 2;
                if(y > 10){
                    y = 10;
                }
                break;
            case 1: //ENTER
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
    int y = 0;
    int consola_ancho = 100;
    
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
        
        const char* opciones[] = {
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
                if(y < 0){
                    y = 0;
                }
                break;
            case 15: //DOWN
                largoTexto = strlen(opciones[y / 2]);
                rlutil::locate((consola_ancho - largoTexto) / 2 - 3, 12 + y);
                cout << " " << endl;
                y = y + 2;
                if(y > 8){
                    y = 8;
                }
                break;
            case 1: //ENTER
                
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
                    default:
                        cout << "Opcion incorrecta! Intente nuevamente" << endl;
                        system("pause");
                    break;
                }
            break;
        }
    }
}

///Listar pacientes alfab‚ticamente
void Menu::informe4()
{
    cout << "PACIENTES ORDENADOS ALFABETICAMENTE" << endl;
    
    PacienteArchivo archivo;
    
    int cant = archivo.cantidadRegistros();
    
    Paciente *vRegistros = new Paciente[cant];
    
    if(vRegistros == nullptr)
    {
        cout << "Error al pedir memoria y leer el archivo" << endl;
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
        cout << endl;
        vRegistros[i].mostrar();
        cout << endl;
    }
    
    delete[] vRegistros;
}

///Mostrar historial de un paciente (todos los estudios realizados por el paciente).
void Menu::informe5()
{

    int dniPaciente;
    
    cout << "Ingrese el DNI del paciente: ";
    cin >> dniPaciente;
    
    PacienteArchivo archivo;
    
    int pos = archivo.buscar(dniPaciente);
    
    Paciente registro = archivo.leer(pos);
    
    cout << "Estudios realizados por " << registro.getNombre() << " " << registro.getApellido() << endl << endl;
    
    EstudioArchivo archivoEstudios;
    
    int cant = archivoEstudios.cantidadRegistros();
    
    for (int i = 0; i < cant; i++)
    {
        Estudio estudio = archivoEstudios.leer(i);
        
        if(estudio.getDNI() == dniPaciente)
        {
            cout << "---------------" << endl;
            estudio.mostrar();
            cout << "---------------" << endl;
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
        for (int x = 0; x < cantTurnos; x++)
        {
            objTurno = archivoTurno.leer(x);
            if(objEst.getIDTurno() == objTurno.getIDTurno())
            {
                cout << objTurno.getFechaProgramada().getAnio() << endl;
                if (anio == objTurno.getFechaProgramada().getAnio())
                {
                    cout << aux << endl;
                    aux += objEst.getPrecio();
                    cout << aux << endl;
                }
            }
        }
    }

    cout << "RECAUDACION DEL ANIO  " << anio  << ": " <<  "$"  << aux << endl;

}

void Menu::menuInformes()
{
    int opc;
    while (true) {
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
        switch (opc) {
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
            informe4();
            system("pause");
            break;
        case 5:
            informe5();
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
        cout << "No se ha restaurado la copia de seguridad" << endl;
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
    
    if(pacienteArchivo.restaurarCopia()){
        if(turnoArchivo.restaurarCopia()){
            if(estudioArchivo.restaurarCopia()){
                if(tipoAnalisisArchivo.restaurarCopia()){
                    if(tipoMuestraArchivo.restaurarCopia()){
                        if(estudioAnalisisArchivo.restaurarCopia()){
                            cout << "La copia de seguridad de todos los archivos se restauro con exito!" << endl;
                        } else {
                            cout << "Error con la restauracion de la copia de seguridad de Analisis de estudios" << endl;
                        }
                    } else {
                        cout << "Error con la restauracion de la copia de seguridad de Tipos de Muestras" << endl;
                    }
                } else {
                    cout << "Error con la restauracion de la copia de seguridad de Tipos de Analisis" << endl;
                }
            } else {
                cout << "Error con la restauracion de la copia de seguridad de Estudios" << endl;
            }
       } else {
           cout << "Error con la restauracion de la copia de seguridad de Turnos" << endl;
       }
    } else {
        cout << "Error con la restauracion de la copia de seguridad de Pacientes" << endl;
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

