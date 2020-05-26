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
        ETSIDI::printxy("MENU INICIO", -2, 2);

        ETSIDI::printxy("CONTROLES  [C]", -6, -1);

        ETSIDI::printxy("PULSE CUALQUIER TECLA PARA JUGAR", -6, -3);
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
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 40);
        ETSIDI::printxy("GAMEOVER", -2.5f, 0);
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 30);
        ETSIDI::printxy("VOLVER A INICIO  [ B ]", -3, -4);
    }
    else if (estado == CONTROLES)
    {
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 50);
        ETSIDI::printxy("CONTROLES", -3, 5);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 30);
        ETSIDI::printxy("MOVIMIENTO          [ W , D ]", -8, 1);
        ETSIDI::printxy("SALTO                           [ SPACE ]", -8, 0);
        ETSIDI::printxy("SALTO GRANDE    [ S SPACE ]", -8, -1);
        ETSIDI::printxy("VOLVER A INICIO  [ B ]", 0, -4);
    }
}

void Coordinador::Tecla(unsigned char key)
{
    if (estado == INICIO) 
    {
        if (key == 'c')
        {
            estado = CONTROLES;
        }
        else if(key != 'c')// en inicio con cualquier tecla te lleva a "JUEGO"
        {
            mundo.Inicializa();
            estado = JUEGO;
        }
        
    }
    else if (estado == JUEGO && key != 'g')
    {
        mundo.Tecla(key);
    }
    else if (estado == JUEGO && key == 'g')
    {
        estado = FIN;
    }
    else if (estado == CONTROLES && key == 'b')
    {
        estado = INICIO;
    }
    else if (estado == GAMEOVER && key == 'b')// al tocar cualquier tecla vas a "INICIO"
    {
        estado = INICIO;
    }
}

void Coordinador::Mueve()
{
    bool gameover = mundo.GetMuerte();
    if (estado == JUEGO)
    {
        mundo.Mueve();  
        if (gameover)
        {
            estado = GAMEOVER;
        }
    }
}