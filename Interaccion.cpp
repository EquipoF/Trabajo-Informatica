#include "Interaccion.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::choque(Caja &pared, Personaje &personaje)
{
	if ( Interaccion::choque(pared.suelo, personaje.cuerpo) )
		
	{
		personaje.setAcc(0.0, 0.0);
		personaje.setVel(0.0, 0.0);
		return true;
	}	
	else if (Interaccion::choque(pared.techo, personaje.cuerpo) || Interaccion::choque(pared.paredD, personaje.cuerpo) || Interaccion::choque(pared.paredI, personaje.cuerpo))
	{
		return true;
	}
	else
	{
		personaje.setAcc(0.0, -4.0);
		return false;
	}

}

bool Interaccion::choque(Rectangulo& r1, Rectangulo& r2)
{
	Vector2D distancia;

	distancia.x = abs(r1.centro.x - r2.centro.x);
	distancia.y = abs(r1.centro.y - r2.centro.y);

	if (distancia.x < ((r1.ancho / 2) + (r2.ancho / 2)) && distancia.y < ((r1.alto / 2) + (r2.alto / 2)))
		return true;
	else
		return false;
}

bool Interaccion::choque(Rectangulo& rectangulo, Personaje& personaje)
{
	if (Interaccion::choque(rectangulo, personaje.cuerpo))
	{
		personaje.setVel(0.0, 0.0);
		return true;
	}
	else
	{
		return false;
	}
}
