#include "ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}
ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}

void ObjetoMovil::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
void ObjetoMovil::setPos(Vector2D pos) {
	posicion = pos;
}
void ObjetoMovil::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
void ObjetoMovil::setVel(Vector2D vel)
{
	velocidad = vel;
}
void ObjetoMovil::setAcc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void ObjetoMovil::setAcc(Vector2D acc) {
	aceleracion = acc;
}

Vector2D ObjetoMovil::getPos(void) {
	return posicion;
}
Vector2D ObjetoMovil::getVel(void) {
	return velocidad;
}
Vector2D ObjetoMovil::getAcc(void) {
	return aceleracion;
}