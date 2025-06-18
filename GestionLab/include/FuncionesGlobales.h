#pragma once
#include <iostream>
#include <cctype>
#include "rlutil.h"

using namespace std;

/// Funciones Utiles
void cargarCadena(char *palabra, int tamano);

void toLowerWord(char *palabra);

void showItem(const char *texto, int posx, int posy, bool selected);
