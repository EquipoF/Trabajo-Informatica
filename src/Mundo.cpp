#include "Mundo.h"
#include "glut.h"

#define DIFF_TIEMPO 0.025 //tiempo n segundos que transcurre cada instante del juego. Diferencial de tiempo
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
	personaje.mueve(DIFF_TIEMPO);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;
}

void Mundo::Tecla(unsigned char key)
{
	Vector2D velActual = personaje.getVel();
	static bool espacioPresionado = 0;

	switch (key) 
	{
	//Movimiento horizontal
	case 'a':
	case 'A':
		personaje.setVel(-5.0, velActual.y);	//Sobrecargar Personaje::mueve para que vaya hacia un lado u otro
	break;

	case 'd':
	case 'D':
		personaje.setVel(5.0, velActual.y);
	break;

	//Movimiento vertical (salto)
	case ' ':
		if (espacioPresionado == 0)
		{
			personaje.setVel(velActual.x, 5.0);
		}
		espacioPresionado = 1;
	break;

	//Soltar teclas A y D
	case 'S':
		personaje.setVel(0.0, velActual.y);	//Crear funcion Personaje::Salta();
	break;

	case ESPACIO_SOLTADO:
		espacioPresionado = 0;
	break;
	}
}
