#include "Mundo.h"
#include "glut.h"

#define DIFF_TIEMPO 0.025 //tiempo n segundos que transcurre cada instante del juego. Diferencial de tiempo



void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	rectangulo1 = Rectangulo(5, 1, Vector2D(0, 3));
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	rectangulo1.Dibuja();
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
	personaje.setVel(-1.0, 1.0); //Velocidad de prueba
	personaje.mueve(DIFF_TIEMPO);
	//Interaccion::choque(caja.suelo, personaje.cuerpo);
	Interaccion::choque(caja, personaje);
	//Interaccion::choque(caja.paredD, personaje.cuerpo);
	//Interaccion::choque(caja.paredI, personaje.cuerpo);

}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;
}

void Mundo::Tecla(unsigned char key)
{

}
