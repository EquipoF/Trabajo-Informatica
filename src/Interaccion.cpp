#include "Interaccion.h"

Interaccion::Interaccion()
{

}

Interaccion::~Interaccion()
{

}

void Interaccion::colision(Personaje& h, Caja c)
{
	float xmax = c.suelo.arribaDcha.x;
	float xmin = c.suelo.arribaIzq.x;
	if (h.posicion.x > xmax)
	{
		h.velocidad.x = 0.0f;
		return true;
	}
	if (h.posicion.x < xmin)
	{
		h.velocidad.x = 0.0f;
		return true;
	}		
	return false;
}

void Interaccion::colision_suelo(Personaje& h, Caja c)
{
	if (h.posicion.y - ALTO <= c.suelo.arribaDcha.y)
	{
		h.aceleracion.y = 0.0f;
		return true
	}
}