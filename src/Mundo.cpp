#include "Mundo.h"
#include "Interaccion.h"
#include "ETSIDI.h"
#include "glut.h"

#define DIFF_TIEMPO 0.025f //tiempo n segundos que transcurre cada instante del juego. Diferencial de tiempo
#define velPersonaje 5.0	//Velocidad a la que se mueve el personaje horizontalmente
#define velSalto 5.0
#define ESPACIO_SOLTADO 1

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	caja.Dibuja();
	personaje.Dibuja();

	l_rectangulos.dibuja();


	//dibujo del fondo
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex2f(-10, -15);
	glTexCoord2d(1, 1);		glVertex2f(10, -15);
	glTexCoord2d(1, 0);		glVertex2f(10, 15);
	glTexCoord2d(0, 0);		glVertex2f(-10, 15);
	glEnd();

	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//textos
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("fuentes/IRON MAN OF WAR 002 NCV.ttf", 20);
	ETSIDI::printxy("PLATAFORMAS", 3, 4);
}

void Mundo::SetOjo(float x, float y, float z)
{
}

float Mundo::GetOjo()
{
	return 0.0f;
}

void Mundo::Mueve()
{
	personaje.Mueve(DIFF_TIEMPO);
	Interaccion::choque(caja, personaje);

	l_rectangulos.choque(personaje);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;

	//Plataformas
	Rectangulo* rec1 = new Rectangulo(4.0f, 0.5f, Vector2D(1.0f, 2.0f));
	l_rectangulos.agregar(rec1);
	Rectangulo* rec2 = new Rectangulo(4.0f, 0.5f, Vector2D(-3.0f, 0.0f));
	l_rectangulos.agregar(rec2);
}

void Mundo::Tecla(unsigned char key)
{
	personaje.Tecla(key);
}