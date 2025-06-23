#include "EstudioManager.h"


//Registrar nuevo estudio.
void EstudioManager::opcion1()
{
    int consola_ancho = 100;
    Estudio obj;

    bool yaExiste = true;
    string texto;

    while (yaExiste) 
    {
        int posy = obj.cargar();

        int band = 0;
        rlutil::cls();

        int pos = _archivo.buscar(obj.getIDEstudio());
        if (pos >= 0) {
            texto = "Ya existe un estudio con ese ID. Intente nuevamente.";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto;
            band++;
            rlutil::locate((consola_ancho - 33) / 2, 16);
            system("pause");
        }

        PacienteArchivo archivoPaciente;
        pos = archivoPaciente.buscar(obj.getDNI());
        if (pos < 0) {
            texto = "No existe un paciente registrado con ese DNI.";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto;
            band++;
            rlutil::locate((consola_ancho - 33) / 2, 16);
            system("pause");
        }

        TurnoArchivo archivoTurno;
        
        pos = archivoTurno.buscar(obj.getIDTurno());
        if (pos < 0) 
        {
            texto = "No existe un turno con ese ID.";
            rlutil::locate((consola_ancho - texto.length()) / 2, 15);
            cout << texto;
            band++;
            rlutil::locate((consola_ancho - 33) / 2, 16);
            system("pause");
        } 
        else 
        {
            Turno turno = archivoTurno.leer(pos);
            if (turno.getDNIPaciente() != obj.getDNI()) 
            {
                texto = "Este ID de turno no corresponde a ese paciente.";
                rlutil::locate((consola_ancho - texto.length()) / 2, 15);
                cout << texto;
                band++;
                rlutil::locate((consola_ancho - 33) / 2, 16);
                system("pause");
            }
        }

        if (band == 0) {
            yaExiste = false;
        }

        rlutil::cls();
    }
    
    bool cargando = true;
    int x = 0;

    rlutil::cls();    
    obj.cargarAnalisis(10);
    
    while (cargando) 
    {

        texto = "¨Desea cargar m s an lisis?";
        rlutil::locate((consola_ancho - texto.length()) / 2, 18);
        cout << texto;

        showItemHorizontal("SI", 45, 20, x == 0);
        showItemHorizontal("NO", 55, 20, x == 1);

        int key = rlutil::getkey();

        switch (key) {
        case 16: // LEFT
            x--;
            if(x < 0){
                x = 0;
            }
            break;
        case 17:// RIGHT
            x++;
            if(x > 1){
                x = 1;
            }
            break;
        case 1:  // ENTER
            if (x == 1) {
                cargando = false;
            }
            else {
                rlutil::cls();    
                obj.cargarAnalisis(10);
            }
            break;
        }
    }
    
    rlutil::cls();

    texto = _archivo.guardar(obj)
        ? "­Se ha registrado exitosamente!"
        : "No se pudo registrar el estudio.";

    rlutil::locate((consola_ancho - texto.length()) / 2, 15);
    cout << texto;
    rlutil::locate((consola_ancho - 33) / 2, 16);
    system("pause");
}

//Eliminar estudio
void EstudioManager::opcion2()
{
    Estudio registro;
    char idEstudio [11];
    int consola_ancho = 100;
    
    string texto =  "Ingrese el ID del estudio a dar de baja: ";
    rlutil::locate((consola_ancho - texto.length())/2, 14);
    cout << texto;
    rlutil::locate((consola_ancho - 10)/2, 16);
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
    
    rlutil::cls();

    if(encontrado)
    {
        registro.setEstado(false);
        if(_archivo.guardar(registro, pos))
        {
            texto = "Estudio dado de baja exitosamente!";
            rlutil::locate((consola_ancho - texto.length())/2, 14);
            cout << texto;
        }
        else
        {
            texto = "Error al dar de baja el estudio";
            rlutil::locate((consola_ancho - texto.length())/2, 14);
            cout << texto;
        }
    }
    else
    {
        texto = "No se encontro un estudio con ese ID en el archivo";
        rlutil::locate((consola_ancho - texto.length())/2, 14);
        cout << texto;
    }
    
    rlutil::locate((consola_ancho - 33)/2, 16);
    system("pause");
}

//Modificar estudio (Sala - analisis asignados - estado)
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

//Buscar un estudio
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

//Listado de estudios
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

