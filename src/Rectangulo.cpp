#include "Rectangulo.h"
#include "glut.h"

Rectangulo::Rectangulo()
{
	arribaD = Vector2D(5.0f, 5.0f);
	arribaI = Vector2D(-5.0f, 5.0f);
	abajoD = Vector2D(5.0f, -5.0f);
	abajoI = Vector2D(-5.0f, -5.0f);
}

Rectangulo::Rectangulo(float anchoIn, float altoIn, Vector2D centroIn)
{

}

Rectangulo::Rectangulo( Vector2D arribaIIn, Vector2D arribaDIn, Vector2D abajoDIn, Vector2D abajoIIn)
{
	arribaD = arribaDIn;
	arribaI = arribaIIn;
	abajoI = abajoIIn;
	abajoD = abajoDIn;
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex2d(abajoI.x, abajoI.y);
	glVertex2d(arribaI.x, arribaI.y);
	glVertex2d(arribaD.x, arribaD.y);
	glVertex2d(abajoD.x, abajoD.y);
	glEnd();
	glEnable(GL_LIGHTING);
}
