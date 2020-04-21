#include "Personaje.h"

//Parámetros del cuerpo
#define ALTO 2.0f
#define ANCHO 1.0f
#define GRAVEDAD -4.0f

//Nombres de las teclas
enum { DCHA = 'd', IZQ = 'a', STOP_EJE_X = 'S', ESPACIO = ' ', ESPACIO_SOLTADO=0};

//Tipos de salto
enum {NORMAL=0, PARED_DCHA=1, PARED_IZQ=2, ABAJO=3};

Personaje::Personaje()
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
	aceleracion.y = GRAVEDAD;
	vMov = 5.0;
	vSalto = 5.0;
	saltosRestantes = 2; //Doble salto
}
Personaje::~Personaje()
{
}

void Personaje::setSaltosRes(int saltosIn)
{
	saltosRestantes = saltosIn;
}
int Personaje::getSaltosRes(void)
{
	return saltosRestantes;
}

void Personaje::Dibuja()
{
	cuerpo.Dibuja();
}

void Personaje::Mueve(float t) {
	ObjetoMovil::Mueve(t);
	cuerpo.setCentro(posicion);
}

void Personaje::Tecla(unsigned char key) {
	static bool espacioPresionado = false;	//Hago un booleano que perdura en el timepo para guardar el estado de la barra espaciadora

	switch (key)
	{
	//Movimiento en el eje x
	case DCHA:
		velocidad.x = vMov;
		break;

	case IZQ:
		velocidad.x = -vMov;
		break;
	
	//Detener eje x
	case STOP_EJE_X:
		velocidad.x = 0.0f;
		break;
	
	//Se presiona la barra espaciadora => se solicita un salto
	case ESPACIO:
		if (!espacioPresionado) //Compruebo que no estaba presionada ya
		{
			Personaje::Salta(0); //Si no estaba pulsada antes, es decir, la acabo de pulsar, genero un salto
		}
		espacioPresionado = true; //Marco la barra espaciadora como pulsada.
		break;
	//Se suelta la barra espaciadora
	case ESPACIO_SOLTADO:
		espacioPresionado = false; //la marco como no pulsada.
		break;
	}
}

void Personaje::Salta(unsigned int tipoSalto) {
	//Comprobaciones para saltar
	if (saltosRestantes > 0) //Si hay saltos restantes
	{
		switch (tipoSalto) //Elijo el tipo de salto (hacia dónde va el mvto. vertical)
		{	
			case (NORMAL):
				velocidad.y = vSalto; //Velocidad en Y para hacer un salto normal (hacia arriba)
				break;

				case (PARED_DCHA): //Ángulo de 45 grados SOLO SI la vel. de mvto. y la de salto son iguales, sino se necesitan más cálculos.
				velocidad.x = -vMov / 1.414;
				velocidad.y = vSalto / 1.414;
				break;

				case (PARED_IZQ): 
				velocidad.x = vMov / 1.414;
				velocidad.y = vSalto / 1.414;
				break;

				case (ABAJO):
				velocidad.y = -vSalto;
				break;
		}			
		saltosRestantes--; //resto 1 al número de saltos
	}
}
