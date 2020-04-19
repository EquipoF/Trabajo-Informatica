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
	ancho = anchoIn;
	alto = altoIn;
	centro = centroIn;
	CentroVertice();

}

Rectangulo::Rectangulo( Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn)
{
	arribaDcha = arribaDchaIn;
	arribaIzq = arribaIzqIn;
	abajoIzq = abajoIzqIn;
	abajoDcha = abajoDchaIn;
	VerticeCentro();
}

Rectangulo::~Rectangulo()
{
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

void Rectangulo::setCentro(Vector2D centroIn)
{
	centro = centroIn;
}

void Rectangulo::setCentro(float x, float y)
{
	centro.x = x;
	centro.y = y;
}


void Rectangulo::CentroVertice()
{
	arribaDcha.x = centro.x + (ancho / 2);
	arribaDcha.y = centro.y + (alto / 2);
	arribaIzq.x = centro.x - (ancho / 2);
	arribaIzq.y = centro.y + (alto / 2);
	abajoIzq.x = centro.x - (ancho / 2);
	abajoIzq.y = centro.y - (alto / 2);
	abajoDcha.x = centro.x + (ancho / 2);
	abajoDcha.y = centro.y - (alto / 2);
}

void Rectangulo::VerticeCentro()
{
	ancho = arribaIzq.x - arribaDcha.x;
	alto = arribaIzq.y - abajoIzq.y;
	centro.x = abajoIzq.x + (ancho / 2);
	centro.y = abajoIzq.y + (alto / 2);
}
