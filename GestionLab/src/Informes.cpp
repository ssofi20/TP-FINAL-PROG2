#include "Informes.h"
#include <iostream>

using namespace std;

///Mostrar el paciente con más cantidad de estudios realizados.
void Informes:: informe1()
{
    cout << "PACIENTE CON MAS ESTUDIOS REALIZADOS: " << endl;
    int dniMax;
    int contador = 0;
    int contador2 = 0;
    int cantidad = _arcPaci.cantidadRegistros();
    int cantReg = _arcEst.cantidadRegistros();
    for (int i = 0; i < cantidad; i++)/// Recorre los pacientes
    {
        Paciente reg = _arcPaci.leer(i);
        if (i==0)
        {
            dniMax = reg.getDNI();
            for (int x = 0; x < cantReg; i++)///recorre los estudios
            {
                Estudio regEst = _arcEst.leer(x);
                if (reg.getDNI() == regEst.getDNI())
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
                Estudio regEst = _arcEst.leer(j);
                if (reg.getDNI() == regEst.getDNI())
                {
                    contador++;
                }
                if (contador2 < contador)
                {
                    dniMax = reg.getDNI();
                    contador2 = contador;
                    contador = 0;
                }
            }
        }
    }

    Paciente obj;
    int pos = _arcPaci.buscar(dniMax);
    obj = _arcPaci.leer(pos);

    cout << "DNI PACIENTE: " << obj.getDNI() << endl;
    cout << "NOMBRE Y APELLIDO: " << obj.getNombre() << obj.getApellido() << endl;
    cout << "FECHA DE NACIMEINTO: " << obj.getDateB().getDia() << "/" << obj.getDateB().getMes() << "/" << obj.getDateB().getAnio() << endl;
}

///Recaudación por tipo de estudio.
void Informes::opcion2()
{

}


///Recaudación anual por mes.
void Informes::opcion3()
{

}


/// Sofi
void Informes::opcion4()
{

}
void Informes::opcion5()
{

}
