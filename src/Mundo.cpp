#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"

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
	plataformas.Dibuja();
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
	SetVelMundo(0); //Aqui se cambia la velocidad de subida del mundo

	personaje.Mueve(DIFF_TIEMPO);	
		Interaccion::Choque(caja, personaje);
		Interaccion::Choque(plataformas, personaje);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;

	//Plataformas
	Rectangulo* rec1 = new Rectangulo(4.0f, 0.5f, Vector2D(1.0f, 2.0f));
	plataformas.Agregar(rec1);
	Rectangulo* rec2 = new Rectangulo(4.0f, 0.5f, Vector2D(-3.0f, 0.0f));
	plataformas.Agregar(rec2);
}

void Mundo::Tecla(unsigned char key)
{
	personaje.Tecla(key);
}

void Mundo::SetVelMundo(float velocidad)
{
	y_ojo = y_ojo + velocidad;
}