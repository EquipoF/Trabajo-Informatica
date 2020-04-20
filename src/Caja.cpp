#include "Caja.h"
#define grosor 4

Caja::Caja()
{
	suelo = Rectangulo(Vector2D(-5, -4), Vector2D(5, -4), Vector2D(5, -5), Vector2D(-5, -5));
	techo = Rectangulo(Vector2D(-5, -4), Vector2D(5, -4), Vector2D(5, -5), Vector2D(-5, -5));
	paredD = Rectangulo(Vector2D(-5, -4), Vector2D(5, -4), Vector2D(5, -5), Vector2D(-5, -5));
	paredI = Rectangulo(Vector2D(-5, -4), Vector2D(5, -4), Vector2D(5, -5), Vector2D(-5, -5));
}

Caja::~Caja()
{
	
}

void Caja::Dibuja()
{
	suelo.Dibuja();
	//techo.Dibuja();
	//paredD.Dibuja();
	//paredI.Dibuja();
}
