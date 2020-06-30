#include "Entidad.h"

Entidad::Entidad() {
	movil = true;
	atravesar = false;
}

Entidad::~Entidad() {

}

void Entidad::Mueve(float t) {
	if (movil)
		ObjetoMovil::Mueve(t);
}