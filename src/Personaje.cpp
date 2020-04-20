#include "Personaje.h"
#include "glut.h"

Personaje::Personaje()
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
	//aceleracion.y = -5.0f;
}

Personaje::~Personaje()
{
}

void Personaje::Dibuja()
{
	cuerpo.Dibuja();
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex2d(posicion.x - ANCHO/2, posicion.y - ALTO/2);
	glVertex2d(posicion.x - ANCHO/2, posicion.y + ALTO/2);
	glVertex2d(posicion.x + ANCHO/2, posicion.y + ALTO/2);
	glVertex2d(posicion.x + ANCHO/2, posicion.y - ALTO/2);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Personaje::mueve(float t) {
	ObjetoMovil::mueve(t);
	cuerpo.setCentro(posicion);
}
