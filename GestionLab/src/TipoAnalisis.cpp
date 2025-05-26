#include "TipoAnalisis.h"

/// Constructores

TipoAnalisis::TipoAnalisis()
{
    _IDAnalisis = 0;
    _IDMuestra = 0;
    strcpy(_nombre, "SIN NOMBRE");
    _estado = true;
}

TipoAnalisis::TipoAnalisis(int idAnalisis, int idMuestra, const char *name)
{
    setIDAnalisis(idAnalisis);
    setIDMuestra(idMuestra);
    setNombre(name);
    setEstado(true);
}

/// Setters

void TipoAnalisis::setIDAnalisis(int idAnalisis)
{
    _IDAnalisis = idAnalisis;
}

void TipoAnalisis::setIDMuestra(int idMuestra)
{
    _IDMuestra = idMuestra;
}

void TipoAnalisis::setNombre(const char *name)
{
    strcpy(_nombre, name);
}

void TipoAnalisis::setEstado(bool estado)
{
    _estado = estado;
}

/// Getters

int TipoAnalisis::getIDAnalisis()
{
    return _IDAnalisis;
}

int TipoAnalisis::getIDMuestra()
{
    return _IDMuestra;
}

const char *TipoAnalisis::getNombre()
{
    return _nombre;
}

bool TipoAnalisis::getEstado()
{
    return  _estado;
}
