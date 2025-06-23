#include "FuncionesGlobales.h"

void cargarCadena(char *palabra, int tamano)
{
    cin.ignore();
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

void cuadrado()
{
    string lineaVertical = "|";
    string lineaHorizontal = "-";

    /* Arriba
    rlutil::locate(3,8);
    cout << lineaHorizontal;
    rlutil::locate(4,8);
    cout << lineaHorizontal;
    rlutil::locate(5,8);
    cout << lineaHorizontal;
    rlutil::locate(6,8);
    cout << lineaHorizontal;
    rlutil::locate(7,8);
    cout << lineaHorizontal;
    rlutil::locate(8,8);
    cout << lineaHorizontal;
    rlutil::locate(9,8);
    cout << lineaHorizontal;
    rlutil::locate(10,8);
    cout << lineaHorizontal;
    rlutil::locate(11,8);
    cout << lineaHorizontal;
    rlutil::locate(12,8);
    cout << lineaHorizontal;
    rlutil::locate(13,8);
    cout << lineaHorizontal;
    */

    int l = 3;
    int r = 33;

    int a = 18;

    /// Left
    rlutil::locate(l,9);
    cout << lineaVertical;
    rlutil::locate(l,10);
    cout << lineaVertical;
    rlutil::locate(l,11);
    cout << lineaVertical;
    rlutil::locate(l,12);
    cout << lineaVertical;
    rlutil::locate(l,13);
    cout << lineaVertical;
    rlutil::locate(l,14);
    cout << lineaVertical;
    rlutil::locate(l,15);
    cout << lineaVertical;
    rlutil::locate(l,16);
    cout << lineaVertical;
    rlutil::locate(l,17);
    cout << lineaVertical;
    rlutil::locate(l,18);
    cout << lineaVertical;


    /// Right
    rlutil::locate(r,9);
    cout << lineaVertical;
    rlutil::locate(r,10);
    cout << lineaVertical;
    rlutil::locate(r,11);
    cout << lineaVertical;
    rlutil::locate(r,12);
    cout << lineaVertical;
    rlutil::locate(r,13);
    cout << lineaVertical;
    rlutil::locate(r,14);
    cout << lineaVertical;
    rlutil::locate(r,15);
    cout << lineaVertical;
    rlutil::locate(r,16);
    cout << lineaVertical;
    rlutil::locate(r,17);
    cout << lineaVertical;
    rlutil::locate(r,18);
    cout << lineaVertical;


    /// Abajo
    rlutil::locate(3,a);
    cout << lineaHorizontal;
    rlutil::locate(4,a);
    cout << lineaHorizontal;
    rlutil::locate(5,a);
    cout << lineaHorizontal;
    rlutil::locate(6,a);
    cout << lineaHorizontal;
    rlutil::locate(7,a);
    cout << lineaHorizontal;
    rlutil::locate(8,a);
    cout << lineaHorizontal;
    rlutil::locate(9,a);
    cout << lineaHorizontal;
    rlutil::locate(10,a);
    cout << lineaHorizontal;
    rlutil::locate(11,a);
    cout << lineaHorizontal;
    rlutil::locate(12,a);
    cout << lineaHorizontal;
    rlutil::locate(13,a);
    cout << lineaHorizontal;

    rlutil::locate(14,a);
    cout << lineaHorizontal;
    rlutil::locate(15,a);
    cout << lineaHorizontal;
    rlutil::locate(16,a);
    cout << lineaHorizontal;
    rlutil::locate(17,a);
    cout << lineaHorizontal;
    rlutil::locate(18,a);
    cout << lineaHorizontal;
    rlutil::locate(19,a);
    cout << lineaHorizontal;
    rlutil::locate(20,a);
    cout << lineaHorizontal;
    rlutil::locate(21,a);
    cout << lineaHorizontal;
    rlutil::locate(22,a);
    cout << lineaHorizontal;
    rlutil::locate(23,a);
    cout << lineaHorizontal;
    rlutil::locate(24,a);
    cout << lineaHorizontal;

    rlutil::locate(25,a);
    cout << lineaHorizontal;
    rlutil::locate(26,a);
    cout << lineaHorizontal;
    rlutil::locate(27,a);
    cout << lineaHorizontal;
    rlutil::locate(28,a);
    cout << lineaHorizontal;
    rlutil::locate(29,a);
    cout << lineaHorizontal;
    rlutil::locate(30,a);
    cout << lineaHorizontal;
    rlutil::locate(31,a);
    cout << lineaHorizontal;
    rlutil::locate(32,a);
    cout << lineaHorizontal;
    rlutil::locate(33,a);
    cout << lineaHorizontal;
    rlutil::locate(34,a);
    cout << lineaHorizontal;
    rlutil::locate(35,a);
    cout << lineaHorizontal;
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
