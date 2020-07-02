#include "Sierra.h"

Sierra::Sierra() : sprite("imagenes/sierra2.png", 8)
{
	movil = false;

	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(1.0f, 1.0f);
}

Sierra::Sierra(bool movilIn, float posXIn, float posYIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn, float velXIn, float velYIn) : sprite("imagenes/sierra2.png", 8)
{
	//Sprite y tamaño de la sierra
	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(1.0f, 1.0f);

	//Definir si se mueve o está quieta
	movil = movilIn;

	//Establecer límites
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

void Sierra::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	sprite.loop();
	glPopMatrix();
}