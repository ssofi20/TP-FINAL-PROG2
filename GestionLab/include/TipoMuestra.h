#pragma once
#include <cstring>

class TipoMuestra
{
    public:
        
        TipoMuestra();
        
        //SETTERS
        void setIDMuestra(int IDMuestra);
        void setNombre(const char *nombre);
        void setEstado(bool estado);
        
        //GETTERS
        int getIDMuestra() const;
        const char * getNombre() const;
        bool getEstado() const;
        

    private:
        
        int _IDMuestra;
        char _nombre[35];
        bool _estado;
        
};
