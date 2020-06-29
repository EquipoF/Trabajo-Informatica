#include "Sierra.h"

Sierra::Sierra() : sprite("imagenes/sierra2.png", 8)
{
	movil = false;

	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(1.0f, 1.0f);
}

Sierra::Sierra(bool movilIn, float posXIn, float posYIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn, float velXIn, float velYIn) : sprite("imagenes/sierra2.png", 8)
{
	//Sprite y tama�o de la sierra
	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(1.0f, 1.0f);

	//Definir si se mueve o est� quieta
	movil = movilIn;

	//Establecer l�mites
	limDcha = limDchaIn;		limIzq = limIzqIn;
	limArriba = limArribaIn;	limAbajo = limAbajoIn;

	//Establecer posicion
	posicion = Vector2D(posXIn, posYIn);

	//Establecer velocidad
	velocidad = Vector2D(velXIn, velYIn);
}

Sierra::~Sierra()
{

}

void Sierra::Mueve(float t)
{
	//Movimiento normal y corriente
	ObjetoMovil::Mueve(t);

	//Comprobaciones de l�mites: horizontal
	if (posicion.x > limDcha) //Si ha llegado al l�mite derecho
		velocidad.x *= -1; //Cambia de direcci�n en x

	if (posicion.x < limIzq)
		velocidad.x *= -1;

	//Comprobaciones de l�mites: vertical
	if (posicion.y > limArriba) //Si ha llegado al l�mite superior
		velocidad.y *= -1; //Cambia de direcci�n en y

	if (posicion.y < limAbajo) //Si ha llegado al l�mite inf
		velocidad.y *= -1;
}

void Sierra::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	sprite.loop();
	glPopMatrix();
}

bool Sierra::GetMovil()
{
	return movil;
}