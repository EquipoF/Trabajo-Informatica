#include "RectanguloMovil.h"

RectanguloMovil::RectanguloMovil(Rectangulo rectanguloIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn,float velXIn,float velYIn)
{
	//Establecer límites
	limDcha = limDchaIn;		limIzq = limIzqIn;
	limArriba = limArribaIn;	limAbajo = limAbajoIn;

	//Establecer velocidad
	velocidad = Vector2D(velXIn, velYIn);

	//Establecer rectángulo deseado
	centro=rectanguloIn.GetCentro(); 
	ancho = rectanguloIn.GetAnchoAlto().x;
	alto = rectanguloIn.GetAnchoAlto().y;
	CentroVertice();

	//Igualar centro del rectángulo como objeto móvil al centro del rectángulo como objeto visible
	posicion = GetCentro();

	//Variables auxiliares
	movil = true;
}

RectanguloMovil::~RectanguloMovil()
{
}

void RectanguloMovil::Mueve(float t) 
{
	//Movimiento normal y corriente
	ObjetoMovil::Mueve(t);
	SetCentro(posicion);//Actualiza el centro del rectángulo (parte visible) para que se dibuje en la nueva posicion (parte cinemática)

	//Comprobaciones de límites: horizontal
	if (posicion.x > limDcha) //Si ha llegado al límite derecho
		velocidad.x *= -1; //Cambia de dirección en x

	if (posicion.x < limIzq) //Si ha llegado al límite izq
		velocidad.x *= -1;

	//Comprobaciones de límites: vertical
	if (posicion.y > limArriba) //Si ha llegado al límite superior
		velocidad.y*= -1; //Cambia de dirección en y

	if (posicion.x < limAbajo) //Si ha llegado al límite inf
		velocidad.x *= -1;
}