#include "Entidad.h"

Entidad::Entidad() {
	movil = true;
	atravesar = false;

	limDcha = posicion.x;	limIzq = posicion.x;
	limArriba = posicion.y; limAbajo = posicion.y;
}

Entidad::~Entidad() {

}

void Entidad::Dibuja()
{

}

void Entidad::Mueve(float t) {
	if (movil)
	{
		ObjetoMovil::Mueve(t);

		//Comprobaciones de límites: horizontal
		if (posicion.x > limDcha) //Si ha llegado al límite derecho
		{
			velocidad.x *= -1; //Cambia de dirección en x
		}
		else if (posicion.x < limIzq) //Si ha llegado al límite izq
			velocidad.x *= -1;

		//Comprobaciones de límites: vertical
		if (posicion.y > limArriba) //Si ha llegado al límite superior
		{
			velocidad.y *= -1; //Cambia de dirección en y
		}
		else if (posicion.y < limAbajo) //Si ha llegado al límite inf
		{
			velocidad.y *= -1;
		}
	}
}