#include "Rectangulo.h"
#include "ETSIDI.h"
#include "glut.h"

Rectangulo::Rectangulo()
{
	arribaDcha = Vector2D(5.0f, 5.0f);
	arribaIzq = Vector2D(-5.0f, 5.0f);
	abajoDcha = Vector2D(5.0f, -5.0f);
	abajoIzq = Vector2D(-5.0f, -5.0f);
	VerticeCentro();//Saca el centro, ancho y alto a partir de las esquinas
	atravesar = false;
}

Rectangulo::Rectangulo(float anchoIn, float altoIn, Vector2D centroIn)
{
	ancho = anchoIn;
	alto = altoIn;
	centro = centroIn;
	CentroVertice(); //Saca las esquinas a partir de ancho/alto/centro
	atravesar = false;
}

Rectangulo::Rectangulo( Vector2D arribaIzqIn, Vector2D arribaDchaIn, Vector2D abajoDchaIn, Vector2D abajoIzqIn)
{
	arribaDcha = arribaDchaIn;
	arribaIzq = arribaIzqIn;
	abajoIzq = abajoIzqIn;
	abajoDcha = abajoDchaIn;
	VerticeCentro();
	atravesar = false;
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::Dibuja()
{
	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

		glColor3ub(55, 0, 0);
		glVertex2d(abajoIzq.x, abajoIzq.y);

		glColor3ub(55, 155, 0);
		glVertex2d(arribaIzq.x, arribaIzq.y);	
		glVertex2d(arribaDcha.x, arribaDcha.y);

		glColor3ub(55, 0, 0);
		glVertex2d(abajoDcha.x, abajoDcha.y);

	glEnd();
	glEnable(GL_LIGHTING);*/

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/plataforma2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex2f(centro.x - (ancho / 2), centro.y - (alto / 2));
	glTexCoord2d(1, 1);		glVertex2f(centro.x + (ancho / 2), centro.y - (alto / 2));
	glTexCoord2d(1, 0);		glVertex2f(centro.x + (ancho / 2), centro.y + (alto / 2));
	glTexCoord2d(0, 0);		glVertex2f(centro.x - (ancho / 2), centro.y + (alto / 2));
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Rectangulo::SetCentro(Vector2D centroIn)
{
	centro = centroIn;
	CentroVertice();
}

void Rectangulo::SetCentro(float x, float y)
{
	Rectangulo::SetCentro(Vector2D(x, y));
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

Vector2D Rectangulo::GetCentro()
{
	return centro;
}

Vector2D Rectangulo::GetAnchoAlto()
{
	return Vector2D(ancho,alto);
}

void Rectangulo::SetAnchoAlto(Vector2D anchoAltoIn) 
{
	ancho = anchoAltoIn.x;
	alto = anchoAltoIn.y;
}
/*
bool Rectangulo::GetMovil()
{
	return movil;
}

bool Rectangulo::GetAtravesar() {
	return atravesar;
}
*/