#include "Rectangulo.h"
#include "glut.h"

Rectangulo::Rectangulo()
{
	arribaDcha = Vector2D(5.0f, 5.0f);
	arribaIzq = Vector2D(-5.0f, 5.0f);
	abajoDcha = Vector2D(5.0f, -5.0f);
	abajoIzq = Vector2D(-5.0f, -5.0f);
}

Rectangulo::Rectangulo(float anchoIn, float altoIn, Vector2D centroIn)
{

}

Rectangulo::Rectangulo( Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn)
{
	arribaDcha = arribaDchaIn;
	arribaIzq = arribaIzqIn;
	abajoIzq = abajoIzqIn;
	abajoDcha = abajoDchaIn;
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::setCentro(Vector2D centroIn) {

}

void Rectangulo::setCentro(float xIn, float yIn) {

}

void Rectangulo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex2d(abajoIzq.x, abajoIzq.y);
	glVertex2d(arribaIzq.x, arribaIzq.y);
	glVertex2d(arribaDcha.x, arribaDcha.y);
	glVertex2d(abajoDcha.x, abajoDcha.y);
	glEnd();
	glEnable(GL_LIGHTING);
}
