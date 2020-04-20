#include "Mundo.h"
#include "Interaccion.h"
#include "glut.h"

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	caja.Dibuja();
	personaje.Dibuja();
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
	personaje.mueve(0.03f);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
		case 'a'://mover izq
				personaje.setVel(Vector2D(-20.0f, 0.0f));
			break;
		case 'd'://mover dcha
				personaje.setVel(Vector2D(20.0f, 0.0f));
			break;
		case 'p'://parar
				personaje.setVel(Vector2D(0.0f, 0.0f));
			break;
	}
}
