#include "Caja.h"

Caja::Caja()
{
	suelo = Rectangulo(Vector2D(-5, -4), Vector2D(5, -4), Vector2D(5, -5), Vector2D(-5, -5));
	//techo = 
	//paredD = 
	//paredI =
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
