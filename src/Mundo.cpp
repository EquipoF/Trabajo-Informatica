#include "Mundo.h"
#include "glut.h"

#define DIFF_TIEMPO 0.025 //tiempo n segundos que transcurre cada instante del juego. Diferencial de tiempo

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
	personaje.setVel(-1.0, 1.0); //Velocidad de prueba
	personaje.mueve(DIFF_TIEMPO);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;

	//Plataformas
	//Rectangulo* rec = new Rectangulo(0.5f, 4.0f, Vector2D(1.0f, 3.0f));

}

void Mundo::Tecla(unsigned char key)
{

}
