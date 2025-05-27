#pragma once

class Menu
{
private:

//FUNCIONES MENU PRINCIPAL
    void menuGestionPacientes();
    void menuGestionTurnos();
    void menuGestionEstudios();
    void menuGestionDatosSistema();

//FUNCIONES MENU INFORMES
    void informe1();
    void informe2();
    void informe3();
    void informe4();
    void informe5();

//FUNCIONES MENU CONFIGURACION
    void copiaSeguridad();
    void restaurarCopiaSeguridad();

public:
    Menu();
    void menuPrincipal();
    void menuInformes();
    void menuConfiguraciones();


};

