#include "Coordinador.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Archivo.h"
#include <conio.h>
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
    Archivo archivo;
    Nodo* cabecera = NULL;

    if (estado == INICIO)
    {
        system("cls");
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 100);
        ETSIDI::printxy("NINJA FROG", -6, 4);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 25);
        ETSIDI::printxy("by Equipo F", -6, 3);

        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 30);
        ETSIDI::printxy("MENU INICIO", -2, 1);
      
        ETSIDI::printxy("CONTROLES  [C]", -6, -1);

        ETSIDI::printxy("PUNTUACIONES [P]", -6, -3);

        ETSIDI::printxy("PULSE CUALQUIER TECLA PARA JUGAR", -6, -5);
    }
    else if (estado == JUEGO)
    {
        mundo.Dibuja();
    }
    else if (estado == PAUSA)
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
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 30);
        ETSIDI::printxy("VOLVER A INICIO  [ B ]", -3, -4);
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
    else if (estado == PUNTUACIONES)
    {
        gluLookAt(0, 0, 20, // posicion del ojo
            0.0, 0, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 50);
        ETSIDI::printxy("PUNTUACIONES", -4, 5);
        ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 20);
        ETSIDI::printxy("PUEDE VER LAS PUNTUACIONES EN LA PANTALLA DE LA CONSOLA", -7, 1);
        ETSIDI::printxy("VOLVER A INICIO  [ B ]", 0, -4);
        system("cls");
        cout << "PUNTUACIONES (TIEMPO MINIMO JUEGO COMPLETADO)\n" ;
        archivo.cargarLista(cabecera);
        archivo.mostrarElemento(cabecera);
    }
}

void Coordinador::Tecla(unsigned char key)
{
    if (estado == INICIO) 
    {
        if (key == 'c' || key == 'C')
        {
            estado = CONTROLES;
        }
        else if (key == 'p' || key == 'P')
        {
            estado = PUNTUACIONES;
            
        }
        else if(key != 'c' && key != 'C' && key != 'p' && key != 'P')// en inicio con cualquier tecla te lleva a "JUEGO"
        {
            mundo.Inicializa();
            estado = JUEGO;
        }        
    }
    else if (estado == JUEGO)
    {
        mundo.Tecla(key);
        if (key == 'g' || key == 'G')
        {
            estado = FIN;
        }
        else if (key == 'p' || key == 'P')
        {
            estado = PAUSA;
        }
    }
    else if (estado == CONTROLES && (key == 'b' || key == 'B'))
    {
        estado = INICIO;
    }
    else if (estado == PUNTUACIONES && (key == 'b' || key == 'B'))
    {
        system("cls");
        estado = INICIO;
    }
    else if (estado == GAMEOVER)
    {
        if (key == 'b' || key == 'B')
        {
            estado = INICIO;
        }
    }
    else if (estado == FIN)
    {
        if (key == 'b' || key == 'B')
        {
            estado = INICIO;
        }            
    }
    else if (estado == PAUSA)
    {
        if (key == 'p' || key == 'P')
        {
            estado = JUEGO;
        }
    }
}

void Coordinador::Mueve()
{
    bool gameover = mundo.GetMuerte();
    bool terminado = mundo.GetFinal();
    if (estado == JUEGO)
    {
        if (terminado == false && gameover == false)
        {
            mundo.Mueve();
        }
          
        else if (terminado)
        {
            estado = FIN;
        }
        else if (gameover)
        {
            estado = GAMEOVER;
        }
    }
}