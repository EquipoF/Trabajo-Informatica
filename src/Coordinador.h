#pragma once
#include "Mundo.h"

class Coordinador
{
public:
    Coordinador();
    virtual ~Coordinador();
    void Tecla(unsigned char key);
    void Mueve();
    void Dibuja();

protected:
    enum Estado { INICIO, JUEGO, FIN, GAMEOVER, CONTROLES};
    Estado estado;
    Mundo mundo;
};