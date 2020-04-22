#include "Personaje.h"

//Parámetros del cuerpo
#define ALTO 2.0f
#define ANCHO 1.0f
#define GRAVEDAD -4.0f
#define COS_45 1/1.414f
#define SEN_45 1/1.414f

//Nombres de las teclas
enum { DCHA = 'd', IZQ = 'a', STOP_EJE_X = 'S', ESPACIO = ' ', ESPACIO_SOLTADO = 0, DCHA_SOLTADO = 1, IZQ_SOLTADO = 2 };

//Tipos de salto
enum {NORMAL=0, PARED_DCHA=1, PARED_IZQ=2, ABAJO=3};

Personaje::Personaje()
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
	aceleracion.y = GRAVEDAD;
	vMov = 5.0;
	vSalto = 5.0;
	saltosRestantes = 3; //nº de saltos para probar
	//variables de contacto para probar los saltos de pared
	contactoParedDcha = true;
	contactoParedIzq = true;
}
Personaje::~Personaje()
{
}

void Personaje::setvMov(float vIn) 
{
	vMov = vIn;
}
void Personaje::setvSalto(float vIn) 
{
	vSalto = vIn;
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

void Personaje::Tecla(unsigned char key) 
{   // ¿Separar este método de la ejecucuón de movimientos (que solo procese los flags de las teclas) => hacer Personaje::Accion para llamar a los saltos y cambiar las velocidades de X?
	//Flags para la detección de teclas.
	static bool espacioPresionado = false;	//Hago un booleano que perdura en el timepo para guardar el estado de las teclas
	static bool dchaPresionado = false;
	static bool izqPresionado = false;

	switch (key)
	{
	//Movimiento en el eje x
	case DCHA:
		velocidad.x = vMov;
		dchaPresionado = true;
		break;

	case IZQ:
		velocidad.x = -vMov;
		izqPresionado = true;
		break;
	
	//Detener eje x
	case DCHA_SOLTADO:
		dchaPresionado = false;
		break;

	case IZQ_SOLTADO:
		izqPresionado = false;
		break;
	
	//Se presiona la barra espaciadora => se solicita un salto
	case ESPACIO:
		//Meter aquí los distintos tipos de salto.
		if (!espacioPresionado) //Si no estaba pulsada antes, es decir, la acabo de pulsar, genero un salto
		{
			if (contactoParedDcha && dchaPresionado) {	//Salto de pared
				Personaje::Salta(1);
			}
			else if (contactoParedIzq && izqPresionado) {	//Salto de pared
				Personaje::Salta(2);
			}
			else {	//Salto normal
				Personaje::Salta(0);
			}
		}
		espacioPresionado = true; //Marco la barra espaciadora como pulsada.
		break;
	//Se suelta la barra espaciadora
	case ESPACIO_SOLTADO:
		espacioPresionado = false; //la marco como no pulsada.
		break;
	}
	if (!dchaPresionado && !izqPresionado) //Parche para el BUG#1
	{
		velocidad.x = 0.0f;
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
				velocidad.x = -vMov * COS_45;
				velocidad.y = vSalto * SEN_45;
				break;

			case (PARED_IZQ): 
				velocidad.x = vMov * COS_45;
				velocidad.y = vSalto * SEN_45;
				break;

			case (ABAJO):
				velocidad.y = -vSalto;
				break;
		}			
		saltosRestantes--; //resto 1 al número de saltos
	}
}