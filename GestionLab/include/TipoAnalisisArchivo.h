#pragma once
#include

class TipoAnalisisArchivo
{
    public:

TipoAnalisisArchivo (std::string nombreArchivo);
int cantidadRegistros();
TipoAnalisis leer(int posicion);
void leer(int cantidadRegistros, TipoAnalisis *vec);
int buscar(int IDAnalisis);
bool guardar(TipoAnalisis registro);
bool guardar(TipoAnalisis registro, int posicion);

private:
std::string _nombreArchivo;
};

