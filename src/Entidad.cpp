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

		//Comprobaciones de l�mites: horizontal
		if (posicion.x > limDcha) //Si ha llegado al l�mite derecho
		{
			velocidad.x *= -1; //Cambia de direcci�n en x
		}
		else if (posicion.x < limIzq) //Si ha llegado al l�mite izq
			velocidad.x *= -1;

		//Comprobaciones de l�mites: vertical
		if (posicion.y > limArriba) //Si ha llegado al l�mite superior
		{
			velocidad.y *= -1; //Cambia de direcci�n en y
		}
		else if (posicion.y < limAbajo) //Si ha llegado al l�mite inf
		{
			velocidad.y *= -1;
		}
	}
}