#include <iostream>
#include "AppManager.h"

using namespace std;

int main()
{

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setConsoleTitle("LABORATORIO ANALISIS CLINICOS");
    rlutil::cls();

    AppManager app;

    app.menuInicio();
    
    rlutil::msleep(2000);
    
    rlutil::locate(1, 28);
    return 0;
}
