#include "Sierra.h"

Sierra::Sierra() : sprite("imagenes/sierra2.png", 8)
{
	velocidad.x = 2.0f;

	posicion = Vector2D(0.0f, 0.5f);
 
	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(1.0f, 1.0f);
}

Sierra::~Sierra()
{

}

void Sierra::Mueve(float t)
{
	ObjetoMovil::Mueve(t);
	if (posicion.x < -8)
		velocidad.x = -velocidad.x;
	if (posicion.x > 8)
		velocidad.x = -velocidad.x;
}

void Sierra::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	sprite.loop();
	glPopMatrix();
}

