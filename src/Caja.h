#pragma once
#include "Rectangulo.h"

class Caja
{
public:
	friend class Interaccion;
	Caja();
	virtual ~Caja();
	void Dibuja();

private:
	float alto, ancho;
	Rectangulo suelo, techo, paredI, paredD;
};

