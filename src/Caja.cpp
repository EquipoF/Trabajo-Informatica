#include "Caja.h"


Caja::Caja()
{
	suelo = Rectangulo(20.0, 2.0, Vector2D(0, -7)); // La caja tiene, con las dimensiones de ventana 800*600, un ancho de 20 y un alto de 14
	techo = Rectangulo(20.0, 1.0, Vector2D(0, 7));
	paredD = Rectangulo(2.0, 14.0, Vector2D(10, 0));
	paredI = Rectangulo(2.0, 14.0, Vector2D(-10, 0));
}

Caja::~Caja()
{
	
}

void Caja::Dibuja()
{
	suelo.Dibuja();
	techo.Dibuja();
	paredD.Dibuja();
	paredI.Dibuja();
}
