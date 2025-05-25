#pragma once
#include <cstring>

class TipoAnalisis
{
    private:
    int _IDAnalisis;
    int _IDMuestra;
    char _nombre[60];
    bool _estado;

    public:
        /// Constructores

        TipoAnalisis();
        TipoAnalisis(int idAnalisis, int idMuestra, const char *name, bool estado);

        /// Setters

        void setIDAnalisis(int idAnalisis);
        void setIDMuestra(int idMuestra);
        void setNombre(const char *name);
        void setEstado(bool estado);

        /// Getters

        int getIDAnalisis();
        int getIDMuestra();
        const char *getNombre();
        bool getEstado();
};

