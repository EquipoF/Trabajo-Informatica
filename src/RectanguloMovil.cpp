#include "RectanguloMovil.h"

RectanguloMovil::RectanguloMovil(Rectangulo rectanguloIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn,float velXIn,float velYIn)
{
	//Establecer l�mites
	limDcha = limDchaIn;		limIzq = limIzqIn;
	limArriba = limArribaIn;	limAbajo = limAbajoIn;

	//Establecer velocidad
	velocidad = Vector2D(velXIn, velYIn);

	//Establecer rect�ngulo deseado
	centro=rectanguloIn.GetCentro(); 
	ancho = rectanguloIn.GetAnchoAlto().x;
	alto = rectanguloIn.GetAnchoAlto().y;
	CentroVertice();

	//Igualar centro del rect�ngulo como objeto m�vil al centro del rect�ngulo como objeto visible
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
	SetCentro(posicion);//Actualiza el centro del rect�ngulo (parte visible) para que se dibuje en la nueva posicion (parte cinem�tica)

	//Comprobaciones de l�mites: horizontal
	if (posicion.x > limDcha) //Si ha llegado al l�mite derecho
		velocidad.x *= -1; //Cambia de direcci�n en x

	if (posicion.x < limIzq) //Si ha llegado al l�mite izq
		velocidad.x *= -1;

	//Comprobaciones de l�mites: vertical
	if (posicion.y > limArriba) //Si ha llegado al l�mite superior
		velocidad.y*= -1; //Cambia de direcci�n en y

	if (posicion.x < limAbajo) //Si ha llegado al l�mite inf
		velocidad.x *= -1;
}