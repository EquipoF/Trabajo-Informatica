#include "PowerUp.h"

PowerUp::PowerUp()
{
	atravesar = 1;
}
PowerUp::PowerUp(Rectangulo rectanguloIn)
{
	//Los powerups se atraviesan
	atravesar = 1;

	//Establecer rectángulo deseado
	centro = rectanguloIn.GetCentro();
	ancho = rectanguloIn.GetAnchoAlto().x;
	alto = rectanguloIn.GetAnchoAlto().y;
	CentroVertice();
}

PowerUp::~PowerUp()
{

}

void PowerUp::Dibuja()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

		glColor3ub(0, 0, 55);
		glVertex2d(abajoIzq.x, abajoIzq.y);

		glColor3ub(0, 0, 55);
		glVertex2d(arribaIzq.x, arribaIzq.y);
		glVertex2d(arribaDcha.x, arribaDcha.y);

		glColor3ub(0, 0, 55);
		glVertex2d(abajoDcha.x, abajoDcha.y);

	glEnd();
	glEnable(GL_LIGHTING);
}