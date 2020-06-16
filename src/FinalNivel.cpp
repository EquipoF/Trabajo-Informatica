#include "FinalNivel.h"

FinalNivel::FinalNivel() : sprite("imagenes/Bandera.png", 10)
{
	sprite.setCenter(0.5f, 0.5f);
	sprite.setSize(2.0f, 2.0f);
}

FinalNivel::~FinalNivel()
{

}

void FinalNivel::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	sprite.loop();
	glPopMatrix();
}

