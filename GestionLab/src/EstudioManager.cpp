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
        obj.cargar();

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
            texto = "No se encontro un estudio con ese ID";
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
    int consola_ancho = 100;
    
    char idEstudio [11];
    string texto = "Ingrese el ID del estudio que desea modificar: ";
    rlutil::locate((consola_ancho - texto.length())/2, 14);
    cout << texto;
    rlutil::locate((consola_ancho - 10)/2, 16);
    cin.ignore();
    cargarCadena(idEstudio, 10);

    int pos = _archivo.buscar(idEstudio);

    if(pos < 0)
    {
        texto = "No se encontro un estudio con ese ID en el archivo";
        rlutil::locate((consola_ancho - texto.length())/2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33)/2, 16);
        system("pause");
        return;
    }

    Estudio registro = _archivo.leer(pos);
    
    int y = 0;
    
    rlutil::cls();
    
    while(true)
    {        
        //Texto centrado
        texto = "SELECCIONE LA OPCION QUE DESEA MODIFICAR";
        rlutil::locate((consola_ancho - texto.length())/2, 8);
        cout << texto;
        
        //Opciones del menu
        showItem("SALA", 12, y == 0);
        showItem("ANALISIS ASIGNADO", 14, y == 1);
        showItem("ESTADO DEL ESTUDIO", 16, y == 2);
        showItem("VOLVER", 18, y == 3);
        
        int key = rlutil::getkey();
        
        switch(key)
        {
        case 14:
            y--;
            if(y < 0) y = 0;
            break;
        case 15:
            y++;
            if(y > 3) y = 3;
            break;
        case 1:
            rlutil::cls();
            switch(y)
            {
                case 0:
                {
                    char newSala[6];
                    texto = "Ingrese la nueva sala: ";
                    rlutil::locate((consola_ancho - texto.length())/2, 10);
                    cout << texto;
                    rlutil::locate((consola_ancho - 4)/2, 12);
                    cargarCadena(newSala, 5);
                    registro.setSala(newSala);
                    
                    if(_archivo.guardar(registro, pos))
                    {
                        texto = "Modificado exitosamente!";
                    }
                    else
                    {
                        texto = "No se pudo modificar el registro!";
                    }
                    rlutil::cls();
                    rlutil::locate((consola_ancho - texto.length())/2, 14);
                    cout << texto;
                    rlutil::locate((consola_ancho - 33)/2, 16);
                    system("pause");
                }
                break;
                case 1:
                {
                    int idAnalisis;
                    int newId;
                    texto = "Ingrese el ID del analisis a modificar:";
                    rlutil::locate((consola_ancho - texto.length())/2, 10);
                    cout << texto;
                    rlutil::locate((consola_ancho - 3)/2, 12);
                    cin >> idAnalisis;

                    EstudioAnalisis reg;
                    EstudioAnalisisArchivo arch;
                    int cant = arch.cantidadRegistros();
                    
                    bool encontrado = false;

                    for (int x=0; x < cant; x++)
                    {
                        reg = arch.leer(x);
                        if (strcmp(reg.getIDEstudio(), idEstudio) == 0)
                        {
                            if (reg.getIDAnalisis() == idAnalisis)
                            {
                                encontrado = true;
                                texto = "Ingrese el nuevo ID del analisis: ";
                                rlutil::locate((consola_ancho - texto.length())/2, 15);
                                cout << texto;
                                rlutil::locate((consola_ancho - 10)/2, 17);
                                cin >> newId;
                                reg.setIDAnalisis(newId);
                                if (arch.guardar(reg, x))
                                {
                                    texto = "El ID fue modificado correctamente.";
                                }
                                else
                                {
                                    texto = "No se pudo modificar el ID.";
                                }
                            }
                        }
                        rlutil::cls();
                        rlutil::locate((consola_ancho - texto.length())/2, 14);
                        cout << texto;
                        rlutil::locate((consola_ancho - 33)/2, 16);
                        system("pause");
                    }
                    if(!encontrado)
                    {
                        texto = "No se encuentra registrado en este estudio el ID de analisis";
                        rlutil::locate((consola_ancho - texto.length())/2, 15);
                        cout << texto;
                        rlutil::locate((consola_ancho - 33)/2, 16);
                        system("pause");
                    }
                }
                break;
                case 2:
                {
                    texto = "SELECCIONE LA OPCION DESEADA";
                    rlutil::locate((consola_ancho - texto.length())/2, 9);
                    cout << texto;
                    int posy = 0;
                    while(true)
                    {
                        showItem("EN PROCESO", 12, posy == 0);
                        showItem("ESPERANDO RESULTADOS", 14, posy == 1);
                        showItem("RESULTADOS LISTOS", 16, posy == 2);
                        showItem("ANULADO", 18, posy == 3);

                        int ingreso = rlutil::getkey();

                        switch(ingreso) {
                        case 14:
                            posy--;
                            if(posy < 0) posy = 0;
                            break;
                        case 15:
                            posy++;
                            if(posy > 3) posy = 3;
                            break;
                        case 1:
                            registro.setEstadoEstudio(posy+1);
                            if(_archivo.guardar(registro, pos)) {
                                texto = "Modificado exitosamente!";
                            } else {
                                texto = "No se pudo modificar el registro!";
                            }
                            rlutil::cls();
                            rlutil::locate((consola_ancho - texto.length())/2, 14);
                            cout << texto;
                            rlutil::locate((consola_ancho - 33)/2, 16);
                            system("pause");
                            break;
                        }
                    }
                }
                break;
                case 3:
                    return;
                    break;
            }
            break;
        }
    }
}

//Buscar un estudio
void EstudioManager::opcion4()
{
    int consola_ancho = 100;

    char idEstudio [11];
    string texto = "Ingrese el ID del estudio que desea consultar: ";
    rlutil::locate((consola_ancho - texto.length())/2, 14);
    cout << texto;
    rlutil::locate((consola_ancho - 10)/2, 16);
    cin.ignore();
    cargarCadena(idEstudio, 10);

    int pos = _archivo.buscar(idEstudio);

    if(pos < 0)
    {
        texto = "No se encontro un estudio con ese ID en el archivo";
        rlutil::locate((consola_ancho - texto.length())/2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33)/2, 16);
        system("pause");
        return;
    }

    Estudio registro = _archivo.leer(pos);
    
    if(!registro.getEstado())
    {
        texto = "Este estudio se encuentra dado de baja";
        rlutil::locate((consola_ancho - texto.length())/2, 15);
        cout << texto;
        rlutil::locate((consola_ancho - 33)/2, 16);
        system("pause");
        return;
    }
    
    rlutil::cls();
    
    string titulo = "INFORMACION DEL ESTUDIO";
    rlutil::locate((100 - titulo.length()) / 2, 4);
    cout << titulo;

    registro.mostrar();

    //int cant = _archivoIntermedio.cantidadRegistros();

    /*
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
    */
    rlutil::locate((consola_ancho - 33)/2, 29);
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

