#include "Interaccion.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::choque(Rectangulo &pared, Rectangulo &personaje)
{
	bool interseccion;
	Vector2D distancia;

	distancia.x = abs(pared.centro.x - personaje.centro.x);
	distancia.y = abs(pared.centro.y - personaje.centro.y);

	if (distancia.x < ((pared.ancho / 2) + (personaje.ancho / 2)) && distancia.y < ((pared.alto / 2) + (personaje.alto / 2)))
	{
		personaje.centro.x = 0;
		personaje.centro.y = 0;
		interseccion = 1;
	}
	else
		interseccion = 0;

	return 0;
}
