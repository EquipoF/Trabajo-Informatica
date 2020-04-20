#include "Personaje.h"

Personaje::Personaje()
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
}

Personaje::~Personaje()
{
}

void Personaje::Dibuja()
{
	cuerpo.Dibuja();
}

void Personaje::mueve(float t) {
	ObjetoMovil::mueve(t);
	cuerpo.setCentro(posicion);
}
