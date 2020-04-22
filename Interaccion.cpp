#include "Interaccion.h"

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::choque(Caja &pared, Personaje &personaje)
{
	bool interseccion;
	Vector2D distancia;

	distancia.x = abs(pared.techo.centro.x - personaje.cuerpo.centro.x);
	distancia.y = abs(pared.techo.centro.y - personaje.cuerpo.centro.y);

	if (distancia.x < ((pared.techo.ancho / 2) + (personaje.cuerpo.ancho / 2)) && distancia.y < ((pared.techo.alto / 2) + (personaje.cuerpo.alto / 2)))
	{
		personaje.setPos(0.0, 0.0);
		interseccion = 1;
	}
	else
		interseccion = 0;

	return 0;
}
