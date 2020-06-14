#pragma once
#include "Rectangulo.h"
#include "ListaRectangulos.h"

class Caja
{
public:
	friend class Interaccion;
	friend class Mundo;
	Caja();
	virtual ~Caja();
	void Dibuja();

private:
	float alto, ancho;
	Rectangulo suelo, techo, paredDcha, paredIzq;
	ListaRectangulos ladosCaja;
};

