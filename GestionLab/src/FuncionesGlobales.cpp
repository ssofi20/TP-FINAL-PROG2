#include "FuncionesGlobales.h"

void cargarCadena(char *palabra, int tamano)
{
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tamano; i++)
    {
        palabra[i] = cin.get();
        if (palabra[i] == '\n')
        {
            break;
        }
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void toLowerWord(char *palabra)
{

    for (int i = 0; palabra[i]; i++) {
        palabra[i] = tolower(palabra[i]);
    }

}

void showItem(const char *texto, int posy, bool selected)
{
    int tamConsola = 100;

    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::GREY);
    }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    }
    rlutil::locate((tamConsola - strlen(texto)) / 2, posy);
    cout << texto << endl;

    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
}










void showItemHorizontal(const char *texto, int posx, int posy, bool selected)
{
    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::GREY);
    }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    }
    rlutil::locate(posx, posy);
    cout << texto << endl;

    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
}
