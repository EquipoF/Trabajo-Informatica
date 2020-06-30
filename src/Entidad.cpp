#include "Entidad.h"

Entidad::Entidad() {
	movil = true;
	atravesar = false;

	limDcha = posicion.x;	limIzq = posicion.x;
	limArriba = posicion.y; limAbajo = posicion.y;
}

Entidad::~Entidad() {

}

void Entidad::Mueve(float t) {
	if (movil)
		ObjetoMovil::Mueve(t);
}