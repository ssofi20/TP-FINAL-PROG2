#include "EstudioManager.h"

///Registrar nuevo estudio.
void EstudioManager::opcion1()
{
    Estudio obj;
    obj.cargar();
    if (_archivo.guardar(obj))
    {
        cout << "Se pudo guardar el paciente exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el paciente. ";
    }
    system("pause");
}

/// Eliminar estudios
void EstudioManager::opcion2()
{
    Estudio registro;
    char idEstudio [11];
    cout << "Ingrese el ID del estudio a dar de baja: ";
    cargarCadena(idEstudio, 10);

    int cantidadReg = _archivo.cantidadRegistros();

    bool encontrado = false;
    int pos;
    for(int i = 0; i < cantidadReg; i++){
        registro = _archivo.leer(i);
        if (strcmp(registro.getIDEstudio(), idEstudio))
        {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if(encontrado){
        registro.setEstado(false);
        if(_archivo.guardar(registro, pos)){
            cout << "Estudio dado de baja exitosamente!" << endl;
        }
        else{
            cout << "Error al dar de baja el estudio" << endl;
        }
        system("pause");
    }
    else {
        cout << "No se encontro un estudio con ese ID en el archivo" << endl;
        system("pause");
    }


}
