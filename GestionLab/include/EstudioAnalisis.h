#pragma once
#include <cstring>

class EstudioAnalisis
{
    public:
        
        EstudioAnalisis();
        EstudioAnalisis(const char *IDEstudio, int IDAnalisis);
        
        //SETTERS
        void setIDEstudio(const char *IDEstudio);
        void setIDAnalisis(int IDAnalisis);
        void setEstado(bool estado);
        
        //GETTERS
        const char * getIDEstudio();
        int getIDAnalisis();
        bool getEstado();
        
        //Metodos de la clase
        void cargar();

    private:
        
        char _IDEstudio[11];
        int _IDAnalisis;
        bool _estado; 
};

