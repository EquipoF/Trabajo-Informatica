#include "Personaje.h"

//Parámetros del cuerpo
#define ALTO 2.0f
#define ANCHO 1.0f
#define GRAVEDAD -2.0f
//Teclas que mueven el personaje
#define DCHA 'd' 
#define IZQ 'a'
#define STOP_EJE_X 'S'
#define ESPACIO ' '
#define ESPACIO_SOLTADO 0
#define PRESS true
#define RELEASE false

Personaje::Personaje()
{
	cuerpo = Rectangulo(ANCHO, ALTO, Vector2D(0,0)); //Inicializo el personaje como su ancho, alto y lo pongo en la posición inicial.
	aceleracion.y = GRAVEDAD;
	vMov = 5.0;
	vSalto = 5.0;
}

Personaje::~Personaje()
{
}

void Personaje::Dibuja()
{
	cuerpo.Dibuja();
}

void Personaje::mueve(float t) {
	ObjetoMovil::mueve(t);
	cuerpo.setCentro(posicion);
}
void Personaje::mueve(unsigned char dir) {
	switch (dir)
	{
	//Movimiento en el eje x
	case DCHA:
		velocidad.x = vMov;
	break;

	case IZQ:
		velocidad.x = -vMov; //Sobrecargar Personaje::mueve para que vaya hacia un lado u otro
	break;
	
	//Detener eje x
	case STOP_EJE_X:
		velocidad.x = 0.0f; //Crear funcion Personaje::Salta();
	break;
	
	//Se presiona la barra espaciadora => se solicita un salto
	case ESPACIO:
		Personaje::Salta(PRESS);
	break;
	//Se suelta la barra espaciadora
	case ESPACIO_SOLTADO:
		Personaje::Salta(RELEASE);
	break;
	}
}
void Personaje::Salta(bool solicitado) {
	static bool espacioPresionado = false;	//Hago un booleano que perdura en el timepo para guardar el estado de la barra espaciadora

	if (solicitado) {	//Si he presionado la barra espaciadora
		if (!espacioPresionado) //Compruebo que no estaba presionada ya
		{
			velocidad.y = vSalto; //Si no lo estaba, a.k.a la acabo de pulsar, genera un salto
		}
		espacioPresionado = true; //Marco la barra espaciadora como pulsada.
	}
	else if (!solicitado) { //Si no estoy pulsando la barra espaciadora
		espacioPresionado = false; //la marco como no pulsada.
	}
}
