#pragma once
#include "Mundo.h"

class Coordinador
{
public:
    Coordinador();
    virtual ~Coordinador();
    void TeclaEspecial(unsigned char key);
    void Tecla(unsigned char key);
    void Mueve();
    void Dibuja();

protected:
    enum Estado { INICIO, JUEGO, FIN, GAMEOVER};
    Estado estado;
    Mundo mundo;
};