#include "Coordinador.h"
#include "ETSIDI.h"

Coordinador::Coordinador()
{
    estado = INICIO;
}

Coordinador::~Coordinador()
{

}

void Coordinador::Dibuja()
{
    if (estado == INICIO)
    {
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 30);
        ETSIDI::printxy("MENU INICIO", -2, 0);
    }
    else if (estado == JUEGO)
    {
        mundo.Dibuja();
    }
    else if (estado == FIN)
    {
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 40);
        ETSIDI::printxy("FIN", -1, 0);
    }
    else if (estado == GAMEOVER)
    {

    }
}

void Coordinador::Tecla(unsigned char key)
{
    if (estado == INICIO)
    {
        mundo.Inicializa();
        estado = JUEGO;
    }
    else if (estado == JUEGO && key != 'g')
    {
        mundo.Tecla(key);
    }
    else if (estado == JUEGO && key == 'g')
    {
        estado = FIN;
    }
}

void Coordinador::Mueve()
{
    if (estado == JUEGO)
    {
        mundo.Mueve();
    }
}