#include "EstudioManager.h"


///Registrar nuevo estudio.
void EstudioManager::opcion1()
{
    int consola_ancho = 100;
    Estudio obj;
    
    bool yaExiste = true;
    string texto;
    
    while (yaExiste)
    {
        obj.cargar();
        
        int band = 0;
        
        int pos = _archivo.buscar(obj.getIDEstudio());
        
        rlutil::cls();
        
        if(pos >= 0)
        {
            texto = "Ya existe un estudio con ese ID. Intente nuevamente";
            rlutil::locate((consola_ancho - texto.length())/2, 15);
            cout << texto;
            band ++;
            rlutil::locate((consola_ancho - 33)/2, 16);
            system("pause");
        }
        
        PacienteArchivo archivoPaciente;
        
        pos = archivoPaciente.buscar(obj.getDNI());
        
        if(pos < 0)
        {
            texto = "No existe un paciente registrado en el sistema con ese DNI.";
            rlutil::locate((consola_ancho - texto.length())/2, 15);
            cout << texto;
            band ++;
            rlutil::locate((consola_ancho - 33)/2, 16);
            system("pause");
        }
        
        TurnoArchivo archivoTurno;
        
        pos = archivoTurno.buscar(obj.getIDTurno());
        
        Turno turno = archivoTurno.leer(pos);
        
        if(turno.getDNIPaciente() != obj.getDNI())
        {
            texto = "Este ID de turno no esta registrado al nombre de este paciente.";
            rlutil::locate((consola_ancho - texto.length())/2, 15);
            cout << texto;
            band ++;
            rlutil::locate((consola_ancho - 33)/2, 16);
            system("pause");
        } 
        else if (pos < 0)
        {
            texto = "No existe un turno registrado en el sistema con ese ID.";
            rlutil::locate((consola_ancho - texto.length())/2, 15);
            band ++;
            rlutil::locate((consola_ancho - 33)/2, 16);
            system("pause");
        }
        
        if(band == 0)
        {
            yaExiste = false;
        }
        
        rlutil::cls();
    }

    if (_archivo.guardar(obj))
    {
        texto = "Se ha registrado exitosamente!";
        rlutil::locate((consola_ancho - texto.length())/2, 15);
    }
    else
    {
        texto= "No se pudo registrar el estudio. ";
        rlutil::locate((consola_ancho - texto.length())/2, 15);
    }
    rlutil::locate((consola_ancho - 33)/2, 16);
    system("pause");
    
}

/// Eliminar estudio
void EstudioManager::opcion2()
{
    Estudio registro;
    char idEstudio [11];
    cout << "Ingrese el ID del estudio a dar de baja: ";
    cargarCadena(idEstudio, 10);

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++)
    {
        registro = _archivo.leer(i);
        if (strcmp(registro.getIDEstudio(), idEstudio) == 0)
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
            cout << "Estudio dado de baja exitosamente!" << endl;
        }
        else
        {
            cout << "Error al dar de baja el estudio" << endl;
        }
        system("pause");
    }
    else
    {
        cout << "No se encontro un estudio con ese ID en el archivo" << endl;
        system("pause");
    }
}

///Modificar estudio (Sala - analisis asignados - estado)
void EstudioManager::opcion3()
{

    char idEstudio [11];
    cout << "Ingrese el ID del estudio que desea modificar: ";
    cargarCadena(idEstudio, 10);

    int pos = _archivo.buscar(idEstudio);

    if(pos < 0)
    {
        cout << "No se encontro un estudio con ese ID en el archivo" << endl;
        system("pause");
        return;
    }

    Estudio registro = _archivo.leer(pos);

    int opcion;
    cout << "Seleccione la opcion que corresponda: " << endl;
    cout << "1- Modificar sala" << endl;
    cout << "2- Modificar analisis asignados" << endl;
    cout << "3- Modificar estado del estudio" << endl;
    cout << "0- Cancelar y volver al menu anterior" << endl;
    cout << "Seleccion: ";
    cin >> opcion;

    switch(opcion)
    {
    case 1:
    {
        char newSala[6];
        cout << "Ingrese la nueva sala: ";
        cargarCadena(newSala, 5);
        registro.setSala(newSala);
        if(_archivo.guardar(registro, pos))
        {
            cout << "Modificado exitosamente!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro!" << endl;
        }
    }
    break;
    case 2:
    {
        int idAnalisis;
        int newId;
        cout << "Ingrese el ID del analisis a modificar: " ;
        cin >> idAnalisis;

        EstudioAnalisis reg;
        EstudioAnalisisArchivo arch;
        int cant = arch.cantidadRegistros();

        for (int x=0; x < cant; x++)
        {
            reg = arch.leer(x);
            if (strcmp(reg.getIDEstudio(), idEstudio)==0)
            {
                if (reg.getIDAnalisis() == idAnalisis)
                {
                    cout << "Ingrese el nuevo ID del analisis: " << endl;
                    cin >> newId;
                    reg.setIDAnalisis(newId);
                    if (arch.guardar(reg, x))
                    {
                        cout << "El ID fue modificado correctamente. " << endl;
                    }
                    else
                    {
                        cout << "No se pudo modificar el ID.";
                    }
                }
            }
            else
            {
                cout << "No se encontro el ID del analisis.";
            }
        }
    }
    break;
    case 3:
    {
        int newEstado;
        cout << "Seleccione segun corresponda: " << endl;
        cout << "1. En proceso" << endl;
        cout << "2. Esperando resultados" << endl;
        cout << "3. Resultados listos" << endl;
        cout << "4. Anulado" << endl;
        cin >> newEstado;
        registro.setEstadoEstudio(newEstado);
        if(_archivo.guardar(registro, pos))
        {
            cout << "Modificado exitosamente!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro!" << endl;
        }
    }
    break;
    case 0:
        return;
    default:
        cout << "Seleccion invalida!" << endl;
    }
    system("pause");

}

///Buscar un estudio
void EstudioManager::opcion4()
{

    char idEstudio [11];
    cout << "Ingrese el ID del estudio: ";
    cargarCadena(idEstudio, 10);

    int pos = _archivo.buscar(idEstudio);

    if(pos < 0)
    {
        cout << "No se encontro un estudio con ese ID en el archivo" << endl;
        system("pause");
        return;
    }

    Estudio registro = _archivo.leer(pos);

    registro.mostrar();

    int cant = _archivoIntermedio.cantidadRegistros();

    for(int i = 0; i < cant; i++){
        EstudioAnalisis reg = _archivoIntermedio.leer(i);
        if(strcmp(reg.getIDEstudio(), idEstudio) == 0){
            ///Tipo Analisis
            cout << "Analisis Realizados: " << endl;
            int pos = _archivoAnalisis.buscar(reg.getIDAnalisis());
            TipoAnalisis obj = _archivoAnalisis.leer(pos);
            cout << obj.getNombre() << endl;
        }
    }
    system("pause");
}

///Listado de estudios
void EstudioManager::opcion5()
{
    int cantidad = _archivo.cantidadRegistros();
    cout << "Listado de estudios" << endl << endl;

    for (int i = 0; i < cantidad; i++)
    {
        Estudio registro = _archivo.leer(i);
        if(registro.getEstado())
        {
            cout << "-------------------------" << endl;
            registro.mostrar();
            cout << "-------------------------" << endl << endl;
        }
    }
    system("pause");
}

