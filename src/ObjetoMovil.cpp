#include "ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}
ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::Mueve(float t) {
	Vector2D nuevaPosicion; //Creación de variables auxiliares para los cálculos
	Vector2D nuevaVelocidad;

	nuevaPosicion = posicion + velocidad * t + aceleracion * (0.5f*t*t); //Calcular nuevas pos y vel
	nuevaVelocidad = velocidad + aceleracion * t;

 	ObjetoMovil::SetPos(nuevaPosicion); //Asignar nuevas pos y vel
	ObjetoMovil::SetVel(nuevaVelocidad);
}

void ObjetoMovil::SetPos(float xIn, float yIn)
{
	posicionAnterior.x = posicion.x; //Primero se actualiza la posición anterior
	posicionAnterior.y = posicion.y;

	posicion.x = xIn; //Después se acutaliza la posición actual con la nueva posición
	posicion.y = yIn;
}
void ObjetoMovil::SetPos(Vector2D posIn) {
	posicionAnterior = posicion;
	posicion = posIn;
}
void ObjetoMovil::SetVel(float vxIn, float vyIn)
{
	velocidad.x = vxIn;
	velocidad.y = vyIn;
}
void ObjetoMovil::SetVel(Vector2D velIn)
{
	velocidad = velIn;
}
void ObjetoMovil::SetAcc(float axIn, float ayIn) {
	aceleracion.x = axIn;
	aceleracion.y = ayIn;
}
void ObjetoMovil::SetAcc(Vector2D accIn) {
	aceleracion = accIn;
}

Vector2D ObjetoMovil::GetPos(void) {
	return posicion;
}
Vector2D ObjetoMovil::GetVel(void) {
	return velocidad;
}
Vector2D ObjetoMovil::GetAcc(void) {
	return aceleracion;
}
Vector2D ObjetoMovil::GetPosAnt(void) {
	return posicionAnterior;
}