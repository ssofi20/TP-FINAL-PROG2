#pragma once
#include <string>
#include "PacienteManager.h"
#include "TurnoManager.h"
#include "EstudioManager.h"
#include "TipoMuestraManager.h"
#include "TipoAnalisisManager.h"

class Menu {

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
        void menuGestiones();
        void menuInformes();
        void menuConfiguraciones();
};

